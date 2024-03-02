#include<stdio.h>

#include<conio.h>

#include<math.h>

void tercgrau(double *r1,double *r2,double *r3)

{

double a,b,c,d,euler,formula1,formula2,h,i,j,k,l,m,n,p,r,s,t,u,x1,x2,x3;

int cont;

printf("\n a*x^3+b*x^2+c*x+d:\n");

printf("Numero a=");

scanf("%lf", &a);

printf("\nNumero b=");

scanf("%lf", &b);

printf("\nNumero c=");

scanf("%lf", &c);

printf("\nNumero d=");

scanf("%lf", &d);

euler=2.7182818284590;

formula1=((3*c/a)-(b*b/(a*a)))/3; //**aqui eu desisti de fazer os nomezinhos bonitos, vai ser tudo letra mesmo

formula2=((2*b*b*b/(a*a*a))-(9*b*c/(a*a))+(27*d/a))/27; 

h=(formula2*formula2/4)+(formula1*formula1*formula1/27);

i=sqrt(((formula2*formula2/4)-h));

j=exp(log10(i)/log10(euler)/3);

k=acos((-1)*(formula2/(2*i)));

l=j*(-1);

m=cos(k/3);

n=sqrt(3)*sin(k/3);

p=(b/3*a)*(-1);

r=(-1)*(formula2/2)+sqrt(h);

s=exp(log10(r)/log10(euler)/3);

t=(-1)*(formula2/2)-sqrt(h);

u=exp(log10(t)/log10(euler)/3);

if (h>0) cont=1;

if (h<=0) cont=3;

if ((formula1==0) && (formula2==0) && (h==0)) cont=2;

switch (cont){

case 1:

x1=(s+u)-(b/3*a);

x2=(-1)*(s+u)/2-(b/3*a);            

x3=(s-u)*sqrt(3)/2;

printf("\nA 3 pont:\n%lf\n%lf +i*%lf\n%lf -i*%lf", x1, x2, x3, x2, x3);


break;

case 2:

x1=exp(log10(d/a)/log10(euler)/3)*(-1);

printf("\n%lf", x1);

break;

case 3:

x1=2*j*cos(k/3)-(b/3*a);

x2=l*(m+n)+p;

x3=l*(m-n)+p;

*r1 = x1;
*r2 = x2;
*r3 = x3;

printf("\nA As 3 raizes:\n%lf\n%lf\n%lf", x1, x2, x3);

break;

}

getch();

}
int main(){
	double r1,r2,r3;
	tercgrau(&r1,&r2,&r3);
	printf("%8.2lf %8.2lf %8.2lf", r1,r2,r3);
	return 0;
}