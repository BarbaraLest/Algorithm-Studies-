#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


//CALCULO DO TEMPO
void ConverTempo(double tempo){
	int mili, seg, min, hor, tempo_int = tempo * 1000;

	mili = (tempo_int) % 1000;
	seg = (tempo_int / 1000) % 60;
	min = ((tempo_int / 1000) / 60) % 60;
	hor = (((tempo_int / 1000) / 60) / 60) % 60;

	printf("%2d:%2d:%2d:%3d\n", hor, min, seg, mili);
}


//BUBBLE
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
	printf("Tempo = %lf\n", tempo);

	ConverTempo(tempo);

	/*for (int i = tam -1; i > 0; i--){
		printf ("%d", vet[i]);
	}*/
}


//INSERT
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
	printf("Tempo = %lf\n", tempo);

	ConverTempo(tempo);

	/*for (int i = tam -1; i > 0; i--){
		printf ("%d", vet[i]);
	}*/
}


int main (){

	int  y=0, tamanho=0;
  char nomeArq[300];
	FILE *arquivo;


printf ("Escolha o tamanho do arquivo :\n");
printf ("1 - 500.000 mil dados\n");
printf ("2 - 750.000 mil dados \n");
printf ("3 - 1.000.000 milhao de dados \n");
scanf ("%d", &y);


if (y == 1){
  tamanho = 500000;
} else if (y == 2){
  tamanho = 750000;
} else if (y == 3){
  tamanho = 1000000;
}

y = 0;

printf ("Escolha a situacao dos dados :\n");
printf ("1 - Ordenados\n");
printf ("2 - Aleatorios\n");
printf ("3 - Invertidos\n");
scanf ("%d", &y);

if (y == 1){
  sprintf (nomeArq, "Ordenado%d.txt", tamanho);
} else if (y == 2){
  sprintf (nomeArq, "Random%d.txt", tamanho);
} else if (y == 3){
  sprintf (nomeArq, "Invertido%d.txt", tamanho);
}

//SELECIONANDO O TAMANHO E O ARQUIVO

arquivo = fopen (nomeArq, "r");

int *vet, i = 0;
vet = (int *) malloc(tamanho * sizeof(int));

for (int i = 0; i < tamanho; i++){
	fscanf(arquivo, "%d", &vet[i]);
	//printf("%d\n", vet[i]);
}
fclose(arquivo);

printf ("Selecione o metodo de organizacao\n 1 - Bubble Sort\n 2 - Insert Short\n");

scanf("%d", &y);
if (y == 1){
	BubbleSort(vet, tamanho);
} else if (y == 2){
	InsertSort(vet, tamanho);
}
}
