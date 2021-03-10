#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*-----------------------------------------------*/
void ConverteTempo(double tempo){
int mili, seg, min, hr, tempo_int = tempo * 1000;

mili = (tempo_int) % 1000;
seg = (tempo_int / 1000) % 60;
min = ((tempo_int / 1000) / 60) % 60;
hr = (((tempo_int / 1000) / 60) / 60) % 60;
printf("%2d:%2d:%2d:%3d", hr, min, seg, mili);

}
/*----------------------------------------------*/
void ShellSort(int *vet, int tamanho)
{
 int i , j , valor;
 int gap = 1;
 clock_t inicio = clock();
 do {
  gap = 3*gap+1;
} while(gap < tamanho);

 do {
  gap /= 3;
  for(i = gap; i < tamanho; i++) {
   valor = vet[i];
   j = i - gap;

   while (j >= 0 && valor < vet[j]) {
    vet[j + gap] = vet[j];
    j -= gap;
   }
   vet[j + gap] = valor;
  }
 }while(gap > 1);

	double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
	printf("Tempo= %lf\n", tempo);
	ConverteTempo(tempo);
}
/*-----------------------------------------------*/
void SelectionSort(int *vet, int tamanho)
{
    int i, j, menor, aux;
 clock_t inicio = clock();
    for (i = 0; i < tamanho-1; i++)
    {
        menor = i;
        for (j = i+1; j < tamanho; j++)
          if (vet[j] < vet[menor])
          menor = aux;
          menor = j;
          j = aux;

    }

	double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
	printf("Tempo= %lf\n", tempo);
	ConverteTempo(tempo);
}
/*-----------------------------------------------*/
int main (){
int i, *vetor, tamanho, op;
FILE *arquivo, *resultado;
char nomeArquivo[255];

printf("Quantidade de dados:\n1- 500.000\n2-750.000\n3-1.000.000\n");
scanf("%d", &op);

switch (op) {
  case 1: tamanho = 500000; break;

  case 2:	tamanho = 750000; break;

  case 3:	tamanho = 1000000; break;

  default:
    printf("Erro!");
    break;
}

op = 0;
printf("Tipo de dados:\n1-ORDENADOS\n2-INVERTIDOS\n3-ALEATORIOS\n");
scanf("%d", &op);

switch (op) {
  case 1: sprintf(nomeArquivo, "Ordenado%d.txt", tamanho);  break;

  case 2:	sprintf(nomeArquivo, "Invertido%d.txt", tamanho);  break;

  case 3:	sprintf(nomeArquivo, "Randomico%d.txt", tamanho); break;

  default:
    printf("Erro!");
    break;
}

arquivo = fopen(nomeArquivo, "r");

vetor = (int *) malloc(tamanho * sizeof(int));

for (i=0; i < tamanho; i++)
{
fscanf(arquivo, "%d", &vetor[i]);
}

fclose(arquivo);
op = 0;
printf("Método de ordenação:\n1-ShellSort\n2-SelectionSort");
scanf("%d", &op);

switch (op) {
  case 1: ShellSort(vetor, tamanho);
  break;
  case 2: SelectionSort(vetor, tamanho);
  break;
  default:
    printf("Erro!");
    break;
}


}
