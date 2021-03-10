#include <stdio.h>
#include <stdlib.h>

int Antecessor(int x)
{
  x=x-1;

return x;
}

int Sucessor(int y)
{
    y=y+1;
    return y;
}


int main ()
{

int x,y, aux;
printf("Insira dois numeros: \n");
scanf("%d %d", &x, &y);



while(x>0)
{
  x = Antecessor(x);
  y = Sucessor(y);
  aux=aux-1;
}


printf("A soma eh %d\n", y);




  return 0;
}
