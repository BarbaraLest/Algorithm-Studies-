#include <stdio.h>
#include <stlib.h>


int main(){

  //geração de arquivos
  FILE *ordenado, *invertido, *randomico;
  int tam, x;
  char nomeArquivo[255];
  printf("Informe o tamanho do arquivo ");
  scanf("%d", &tam);
  sprintf(nomeArquivo, "Ordenado%05d.txt", tam);
  ordenado = fopen(nomeArquivo, "w");
  for (x=1;x<=tam;x++){
    fprintf(ordenado, "%d\n", x);
  }
  fclose(ordenado);

  sprintf(nomeArquivo, "Invertido%05d.txt", tam);
  invertido = fopen(nomeArquivo, "w");
  for (x=tam;x>=1;x--){
    fprintf(invertido, "%d\n", x);
  }
  fclose(invertido);

  sprintf(nomeArquivo, "Random%05d.txt", tam);
  randomico = fopen(nomeArquivo, "w");
  srand (time(NULL));
  for (x=tam;x>=1;x--){
    fprintf(randomico, "%d\n", rand()%tam);
  }
  fclose(randomico);
}
