#include <string.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>


#define Const 	32      
#define P2  "P2"

typedef struct {            
    uint32_t w, h;          
    uint16_t max;           
    uint16_t **pixels;      
} plain_pgm;

uint16_t **alloc_pgm_pixels (uint32_t w, uint32_t h)
{
    uint16_t **pixels = NULL;

    
    if (!(pixels = malloc (h * sizeof *pixels))) {
        perror ("malloc-pixels");
        return NULL;
    }
    
    for (uint32_t i = 0; i < h; i++)
        if (!(pixels[i] = malloc (w * sizeof *pixels[i]))) {
            perror ("malloc-pixels[i]");
            return NULL;
        }

    return pixels;  
}

int readpgm (FILE *fp, plain_pgm *pgm)
{
    char buf[Const];            
    uint32_t h = 0, w = 0;      

    if (fscanf (fp, "%s", buf) != 1) {  
        fputs ("formato invalido", stderr);
        return 0;
    }

    if (strcmp (buf, P2) != 0) { 
        fprintf (stderr, " P2 Nao foi achado, logo provavelmente nao e pgm.\n");
        return 0;
    }

    
    if (fscanf (fp, "%" SCNu32 " %" SCNu32 " %" SCNu16, 
                &pgm->w, &pgm->h, &pgm->max) != 3) {
        fputs ("Formato invalido ou ha comentarios do criador da imagem\n",
                stderr);
        return 0;
    }

    
    if (!(pgm->pixels = alloc_pgm_pixels (pgm->w, pgm->h)))
        return 0;
	
    for (;;) {  
        if (fscanf (fp, "%" SCNu16, &pgm->pixels[h][w]) != 1) {
            fputs ("Há menos numeros do que deveria!\n", stderr);
            return 0;
        }
        if (++w == pgm->w)
            w = 0, h++;
        if (h == pgm->h)
            break;
    }
	
	
    return 1;
}

void baw(char xxx[],plain_pgm *pgm){
	char pt[100];
	strcpy(pt,xxx);
	int i,j;
	int xx,l;
	
	FILE *file2 = fopen(xxx,"r");
	char a[50],b[50],c[50],d[50];
	fscanf(file2,"%s",a);
	fscanf(file2,"%d\n",b);
	fscanf(file2,"%d %d",c,d);
	while(fscanf(file2,"%d",&l) !=-1){
		xx=xx+l;
	}	
	int final = xx/(pgm->h*pgm->w);
	
	fclose(file2);
	strtok(pt,".");

	FILE *file = fopen(strcat(pt,"3.pgm"), "w");
	
	fprintf(file,"P2\n%d %d\n%d\n",pgm->w, pgm->h,pgm->max);
	int h=0,w=0;
	for (;;) {  
        if (final >= pgm->pixels[h][w]){
			fprintf(file,"0 ");}
        else
			fprintf(file,"255 ");    
        
        if (++w == pgm->w){
            w = 0, h++;
            fprintf(file,"\n");}
        if (h == pgm->h)
            break;
    }

    
	fclose(file);
}

void clarear(char xxx[],plain_pgm *pgm){
	char pt2[100];
	strcpy(pt2,xxx);
	strtok(pt2,".");
	FILE *file = fopen(strcat(pt2,"1.pgm"), "w");
	
	fprintf(file,"P2\n%d %d\n%d\n",pgm->w, pgm->h,pgm->max);
	int h=0,w=0;
	for (;;) {  
        
        if(pgm->pixels[h][w]>=224)
        	fprintf(file,"255 ");
        else{
			fprintf(file,"%d ",pgm->pixels[h][w]+Const);}
		
        if (++w == pgm->w){
            w = 0, h++;
            fprintf(file,"\n");}
        if (h == pgm->h)
            break;
    }
	fclose(file);	
}
void rotatepgm(char xxx[],plain_pgm *pgm){
    int w=0,h=0;
    char pt3[50];
    strcpy(pt3,xxx);
	strtok(pt3,".");
    FILE *file = fopen(strcat(pt3,"4.pgm"),"w");
    

	fprintf(file,"P2\n%d %d\n%d\n",pgm->h, pgm->w,pgm->max);
    for (;;){
	
    	fprintf(file,"%d ",pgm->pixels[h][w]);
    	if (++h == pgm->h)
            h = 0, w++;
        if (w == pgm->w)
            break;
	}
		

    
fclose(file);

}

void zoompgm(char xxx[],plain_pgm *pgm){
    int w,h=0,v;
    char pt4[50];
    strcpy(pt4,xxx);
	strtok(pt4,".");
    FILE *file=fopen(strcat(pt4,"2.pgm"),"w");
   
	fprintf(file,"P2\n%d %d\n%d\n",pgm->w/2, pgm->h/2,pgm->max);
    
	while(h!=pgm->h){ 
	
        v=(pgm->pixels[h][w]+pgm->pixels[h+1][w]+pgm->pixels[h][w+1]+pgm->pixels[h+1][w+1])/4;
        fprintf(file,"%d ",v);
        w=w+2;
        v=0;
        if (w == pgm->w){
            w = 0;
			h=h+2;
            fprintf(file,"\n");
		}
        
    }
           	
	fclose(file);

}
int main (int argc, char **argv) {

    plain_pgm pgm = { .w = 0 }; 
    
    FILE *fp = argc > 1 ? fopen (argv[1], "r") : stdin;

    if (!fp) {  
        perror ("Falha ao abrir arquivo");
        return 1;
    }

    if (!readpgm (fp, &pgm)) { 
        fputs ("erro na leitura.\n", stderr);
        return 1;
    }
    if (fp != stdin)            
        fclose (fp);
   
    printf ("Leitura de %s ocorreu corretamente, suas 4 imagens devem ter sido criadas!",argv[1]);
    
	
	zoompgm(argv[1],&pgm);
	clarear(argv[1],&pgm);
	rotatepgm(argv[1],&pgm);
	baw(argv[1],&pgm);
	
	
	

    for (uint32_t i = 0; i < pgm.h; i++)    
        free (pgm.pixels[i]);
    free (pgm.pixels);
	return 0;                   
}