#include <stdio.h>
#include <stdlib.h>
#include <math.h>







void seggrau(float a, float b, float c,float*r1,float*r2)
{
   
    float delta, x1, x2;
 
 
    printf("\nf(x) = %8.2fx² + %8.2fx + %8.2f\n", a, b, c);
 
    delta = b*b - 4 * a * c;
 
    if(delta < 0)
    {
        printf("\nDELTA = %8.2f\nNão possui raízes reais!\n\n", delta);
    }
    else
    {
        if(delta == 0)
        {
            x1 = -b / (2 * a);
            printf("\nDELTA = %8.2f \nx'   = %8.2f\n\n", delta, x1);
        }
        else
        {
            x1 = (-b - sqrt(delta)) / (2 * a);
            x2 = (-b + sqrt(delta)) / (2 * a);
            printf("\nDELTA = %8.2f \nx'   = %8.2f\nx''  = %8.2f\n\n", delta, x1, x2);
        }
    }
 	*r1 = x1;
 	*r2 = x2;
   
} 

int main(){
	float x1,x2;
	float a=40;
	float b=200;              /* aqui no caso seria as entradas para a,b,c */
	float c=3;
	seggrau(a,b,c,&x1,&x2);
	printf("%f %f",x1,x2);
	return 0;
}