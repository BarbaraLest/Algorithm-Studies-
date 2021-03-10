#include <stdio.h>
#include <stdlib.h> // importar essa biblioteca para usar o malloc e size off

void Maior(int p[], int n)
{
  int i, maior=0;
  for(i=0; i<n; i++)
  {
    printf("%d\n", p[i]);
    if(p[i]>maior)
    {
      //não esta mostrando o maior
      maior = p[i];
    }
  }

  printf("O maior eh: %d\n", maior);

}

int main() {
int n,i;
printf("Insira N:\n" );
scanf("%d", &n);

int *p = (int*)malloc(n*sizeof(int));
for(i=0; i<n; i++)
{
  scanf("%d", &p[i]);
}

Maior(p, n);

  return 0;
}
