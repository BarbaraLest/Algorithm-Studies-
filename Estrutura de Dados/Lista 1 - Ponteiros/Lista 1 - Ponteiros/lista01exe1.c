#include <stdio.h>


int main() {

float *num1,* num2;
float n1, n2;

printf("Entre com dois numeros:\n" );
scanf("%f %f" , &n1 , &n2);
num1 = &n1;
num2 = &n2;

printf("A soma eh: %.2f ", (*num1+*num2) );

  return 0;
}
