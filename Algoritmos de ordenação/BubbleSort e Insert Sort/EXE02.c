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
void BubbleSort(int *vet, int tam){
 clock_t inicio = clock();
	for (int i = tam-1; i > 0; i--)
	{
		for (int d = 0; d < i; d++)
		{
			if (vet[d] > vet[d+1])
			{
				int aux = vet[d];
				vet[d] = vet[d+1];
				vet[d+1] = aux;
			}
		}
	}
	double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
	printf("Tempo= %lf\n", tempo);
	ConverteTempo(tempo);
}
/*-----------------------------------------------*/
void InsertSort(int *vet, int tam){
 clock_t inicio = clock();
	for (int i = 1; i < tam; i++)
	{
		int aux = vet[i];
		int d = i - 1;
		while (d >= 0 && vet[d] > aux)
		{
			vet[d+1] = vet[d];
			d--;
		}
		vet[d+1] = aux;
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
printf("Método de ordenação:\n1-BubbleSort\n2-InsertSort");
scanf("%d", &op);

switch (op) {
  case 1: BubbleSort(vetor, tamanho);
  break;
  case 2: InsertSort(vetor, tamanho);
  break;
  default:
    printf("Erro!");
    break;
}


}
