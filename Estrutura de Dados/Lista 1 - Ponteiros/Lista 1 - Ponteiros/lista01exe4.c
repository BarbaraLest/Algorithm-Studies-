#include <stdio.h>
#include <stdlib.h> // importar essa biblioteca para usar o malloc e size off

//duvida, tipo void está certo?
int main() {


int n;
void *x, *y, *soma;


printf("Digite 1 para inteiro ou 2 para real\n" );
scanf("%d", &n);

if(n == 1)
{
  printf("Insira dois numeros: \n" );
  x = (int*)malloc(sizeof(int));
  y = (int*)malloc(sizeof(int));
  soma = (int*)malloc(sizeof(int));
  scanf("%d %d", x,y);
  *((int*)soma)= *((int*)x)+*((int*)y);
  printf("%d", *((int*)soma));
}
  else if(n==2)
  {
    printf("Insira dois numeros: \n" );
    x = (float*)malloc(sizeof(float));
    y = (float*)malloc(sizeof(float));
    soma = (float*)malloc(sizeof(float));
    scanf("%f %f", x,y);
    *((float*)soma)= *((float*)x)+*((float*)y);
    printf("%f", *((float*)soma));
}


  return 0;
}
