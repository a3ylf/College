#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

void ler() {
    FILE *file = fopen("funcionarios.dat", "r");
    FILE *file2 = fopen("departamentos.dat", "r");
    int a,b,c,d,e,j,l,k;
    char nome[100];
    
    if(file2){
	    printf("Dados lidos do arquivo departamentos.dat:\n");
	    while(fscanf(file2, "%d%s%d",	&j, nome, &l) != -1)
			printf("\nCodigo do departamento: %d Nome do departamento: %s  Primeiro do departamento: %d\n", j,nome, l);
		fclose(file2);		
	}
	printf("---------------------------------------------");
	if(file){
        printf("\nDados lidos do arquivo funcionarios.dat:\n");
        while(fscanf(file, "%d%d%d%d%d", &a, &b, &c,&d,&e) != -1){
            printf("\nLinha: %d   NumFunc: %d   NivelSalario: %d  Dept: %d  Proximo: %d", a, b, c,d,e);
        }
        fclose(file);
       }
    printf("\n--------------------------------------------");    
}

int checkfile(char f[],char g[]){
	FILE *file = fopen(f, "r");
	FILE *file2 = fopen(g, "r");
	int aaa;
	if(file){
		aaa++;}
	else{
		return 0;
	}
	if(file2){
		aaa++;}
	else{
		return 0;
	}
	fclose(file);
	fclose(file2);
	return 1;
	
}
void checkfirst(){
		FILE *file = fopen("funcionarios.dat", "r");
		FILE *file3= fopen("temp2.txt","w");
		FILE *file2= fopen("departamentos.dat","r");
	int a,b,c,d,e,j,l;
	char k[100];
	int aa=100,bb=100,cc=100,dd=100,ee=100;
	if(file){
        
        while(fscanf(file, "%d%d%d%d%d", &a, &b, &c,&d,&e) != -1){
        	
			if(a<aa){
				if(d==1){
					aa=a;
				}}
			if(a<bb){
				if(d==2){
					bb=a;
				}}
			if(a<cc){
				if(d==3){
					cc=a;
				}}
			if(a<dd){
				if(d==4){
					dd=a;
				}}
			if(a<ee){
				if(d==5){
					ee=a;
				}}
				    
		}
		fclose(file);
	}
	if(file2){
		while(fscanf(file2, "%d%s%d", &j, k, &l) != -1){
			
			if(j==1){
				fprintf(file3,"%d %s %d \n",j,k,aa);
			}
			if(j==2){
				fprintf(file3,"%d %s %d \n",j,k,bb);
			}
			if(j==3){
				fprintf(file3,"%d %s %d \n",j,k,cc);
			}
			if(j==4){
				fprintf(file3,"%d %s %d \n",j,k,dd);
			}
			if(j==5){
				fprintf(file3,"%d %s %d \n",j,k,ee);
			}}
		fclose(file2);}		
		fclose(file3);
	remove("departamentos.dat");
	rename("temp2.txt","departamentos.dat");
	
		
}	
int checkfunc(char f[],int x){
	FILE *file = fopen(f, "r");
	int a,b,c,d,e;
	if(file){
        
        while(fscanf(file, "%d%d%d%d%d", &a, &b, &c,&d,&e) != -1){
        	if(x==b){
        		fclose(file);
        		return 1;
			}}}
	
    fclose(file);
	return 0;
}
		

void demissao(char f[]){
	FILE *file = fopen(f,"r");
	FILE *file2 =fopen("temp.txt", "w");
	int a,b,c,d,e,nfc,tempa = 1210,ret;
	printf("\nDiga o numero do funcionario que ira ser demitido:");scanf("%d",&nfc);
	int aaa=checkfunc(f,nfc);
	while(aaa!=1){
		printf("\nEsse funcionario nao existe, porfavor digite outro:");scanf("%d",&nfc);
		aaa=checkfunc(f,nfc);
		}
	if(file){
        
        while(fscanf(file, "%d%d%d%d%d", &a, &b, &c,&d,&e) != -1){

			if(nfc==b){
				tempa = a;
				}
			if(a<tempa){
				fprintf(file2,"%d %d %d %d %d \n",a,b,c,d,e);
				}
			if(a>tempa){
				fprintf(file2,"%d %d %d %d %d \n",a-1,b,c,d,e);
			}
		}
		fclose(file);
		fclose(file2);
		}
	ret = remove(f);
	rename("temp.txt",f);

   if(ret == 0) {
      printf("funcionario demitido com sucesso!");
   } else {
      printf("Erro no programa");
   }
   	checkfirst();
   	Sleep(3000);
	ler();	
}


void muddpt(char f[]){
	
	FILE *file = fopen(f,"r");
	FILE *file2 =fopen("temp.txt", "w+");
	int a,b,c,d,e,dpt,nfc,ret;
	printf("\nDiga o numero do funcionario que ira mudar de departamento:"); scanf("%d",&nfc);
	int aaa=checkfunc(f,nfc);
	while(aaa!=1){
		printf("\nEsse funcionario nao existe, porfavor digite outro:");scanf("%d",&nfc);
		aaa=checkfunc(f,nfc);
		}
	printf("\nDiga o novo departamento no qual ele ira trabalhar:"); scanf("%d", &dpt);
	while(dpt  <=0 || dpt >=6){printf("\nEste departamento nao existe, porfavor digite corretamente:"); scanf("%d", &dpt);}
	if(file){
        
        while(fscanf(file, "%d%d%d%d%d", &a, &b, &c,&d,&e) != -1){
			if(nfc==b){
				fprintf(file2, "%d %d %d %d %d \n",a,b,c,dpt,e);}
			else
				fprintf(file2,"%d %d %d %d %d \n",a,b,c,d,e);
		}
		fclose(file);
		fclose(file2);
		}
	ret = remove(f);
	rename("temp.txt",f);

   if(ret == 0) {
      printf("Departamento modificado com sucesso");
   } else {
      printf("Error: unable to delete the file");
   }
	checkfirst();
	Sleep(3000);
	ler();		
}

int checkmax(int x,char f[]){
	FILE *file = fopen(f,"r");
	int a,b,c,d,e,p=0; 
	if(file){
        
        while(fscanf(file, "%d%d%d%d%d", &a, &b, &c,&d,&e) != -1){
        	p++;
        }
    	fclose(file);
    }
    else
        printf("\nERRO ao abrir arquivo!\n");
    x=p;
    return(x);
    	
}
	
int admissao(char f[],int xx){
	int linhas, numfunc,ns,dpt,prox,proxtemp,aa=100;
	int linha; linha = checkmax(linhas,f);
	FILE *file = fopen(f, "r+");
	
	printf("\nDiga o numero do funcionario:"); scanf("%d", &numfunc);
	while(checkfunc(f,numfunc)!=0){
		printf("\nEste funcionario ja existe, escreva outro numero:"); scanf("%d", &numfunc);
	}
	int a,b,c,d,e;
	printf("\nPara qual departamento ele vai trabalhar? (1-vendas 2-contabilidade 3-estoque 4-entrega 5-rh)"); scanf("%d", &dpt);
    while(dpt  <=0 || dpt >=6){printf("\nEste departamento nao existe, porfavor digite corretamente:"); scanf("%d", &dpt);}
	if(file){
        
        while(fscanf(file, "%d%d%d%d%d", &a, &b, &c,&d,&e) != -1){
		
        	if(a<aa){
				if(d==dpt){
					aa=a;
        	}

    }}}
    printf("\nQual sera o nivel salarial do funcionario?"); scanf("%d",&ns);
    fprintf(file, "%d %d %d %d %d \n", xx, numfunc, ns,dpt,aa);
	fclose(file);
    
    
	printf("Carregando novos arquivos.......\n");
	checkfirst();
	Sleep(3000);
	ler();
	return 0 ;
}

void consultdepart(char f[]){
	FILE *file = fopen(f,"r");
		
	int a,b,c,d,e,dpt,ccc,cont=0,controle= 0 ;
	printf("\nDigite o numero do departamento:"); scanf("%d",&dpt);
	while(dpt  <=0 || dpt >=6){printf("\nEste departamento nao existe, porfavor digite corretamente:"); scanf("%d", &dpt);}
    printf("LISTA DE FUNCIONARIOS DO DEPARTAMENTO %d ", dpt);
	if(file){
		
	        
	    while(fscanf(file, "%d%d%d%d%d", &a, &b, &c,&d,&e) != -1){
			if(dpt == d){
				printf("\n. Funcionario %d\n. Linha: %d\n. Nivel Salarial: %d\n ",b, a,c);
				
			}
			
			}
		}
	fclose(file);

}
		
int consultindiv(char f[]){
	FILE *file = fopen(f,"r");
	
	int a,b,c,d,e,nfc,ccc,cont=0,controle= 0 ;
	printf("\nDigite o numero do funcionario:"); scanf("%d",&nfc);
	
	if(file){
		
	        
	    while(fscanf(file, "%d%d%d%d%d", &a, &b, &c,&d,&e) != -1){
			if(nfc == b){
				printf("\nFuncionario %d\n, Linha: %d\n, Nivel Salarial: %d\n Departamento: %d", nfc, a, c,d);
				fclose(file);
				printf("\nOperacao de consulta realizada com sucesso");
				return 0;
			}
			if(nfc != b){
				cont++;
				}
			}
		}
				
			
	if(cont == checkmax(ccc,f)){
		printf("Este funcionario nao existe, porfavor tente novamente.\n \n");
		fclose(file);	
		return 0;
	}
}

int main() {
	int l,ll,a;
    char func[] = {"funcionarios.dat"};
    char dept[] = {"departamentos.dat"};
    a=checkmax(ll,func);
   
	if(a>=21){
    	printf("A capacidade de funcionarios estorou!");
    	
    	return 0;
	}
	
    if(checkfile(func,dept)== 0){
    	printf("Alguns dos arquivos estao com problema");
    	return 0;
	}
    
    ler(func,dept);
    Sleep(100);
    printf("\n\nQual operacao voce deseja fazer? \n1-Admissao \n2-Demissao \n3-Mudanca de departamento \n4-Consulta de departamento \n5-Consulta de um funcionario especifico \n0-fim\n");
    scanf("%d",&l);
    while(l>5 || l<0){printf("Essa funcao nao existe, tente novamente."); scanf("%d",&l);}
	while(l!=0){
		printf("------------------------------------------------------------------");
	    if(l==1){
	    	admissao(func,a);
	    	
		}
		if(l==2){
			demissao(func);
		}
	    if(l==3){
	    	muddpt(func);
		}
		if(l==4){
			consultdepart(func);
		}
		if(l==5){
			consultindiv(func);
		}
		printf("\nQual operacao deseja fazer agora?\n1-Admissao \n2-Demissao \n3-Mudanca de departamento \n4-Consulta de departamento \n5-Consulta de um funcionario especifico \n0-fim\n");
		scanf("%d",&l);
	}
    
    
	return 0;
}