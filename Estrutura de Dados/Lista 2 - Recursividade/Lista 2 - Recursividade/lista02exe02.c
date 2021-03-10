#include <Stdio.h>

int Soma(int num)
{


  num = num + Soma(num);

  return num;
}


int  main() {

int x, y, resultado;
printf("Insira dois numero: ");
scanf("%d %d", &x, &y);

while(y>0)
{
resultado= resultado+  Soma(x);
  y=y-1;
}



printf("A multiplicação eh: %d\n", resultado);











  return 0;
}
