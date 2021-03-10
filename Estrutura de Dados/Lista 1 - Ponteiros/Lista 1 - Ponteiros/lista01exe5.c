#include <stdio.h>
#include <stdlib.h>


 struct Pessoas
{
  char nome[200];
  int idade;
};
struct Pessoas pes[3];

/* ----------------------------------*/
int Menor()
{

}

int main() {

int i;

for(i=0; i<3; i++)
{
  printf("Nome: \n");
  scanf("%s", &pes[i].nome);
  printf("Idade: \n");
  scanf("%d", &pes[i].idade);
}






/*for(i=0; i<3; i++)
{
  printf("%s", pes[i].nome);
  printf("%d", pes[i].idade);
}*/





  return 0;
}
