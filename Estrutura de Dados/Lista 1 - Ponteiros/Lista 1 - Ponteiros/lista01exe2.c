#include <stdio.h>
#include <stdlib.h> // importar essa biblioteca para usar o malloc e size off

int main() {

int  *num;
int n, soma=0, i;

n = (int) malloc(sizeof(int));
num = (int*) malloc(sizeof(int));

printf("Entre com um numero\n" );
scanf("%d" , &n);
num = &n;

for( i=1; i<*num; ++i){
if (*num%i == 0)
{soma = soma+i;}
}

if(soma == *num)
{printf("%d eh perfeito", *num);}
else {printf("%d nao eh perfeito", *num);}
  return 0;
}
