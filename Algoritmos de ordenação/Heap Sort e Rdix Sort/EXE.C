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
/*----------- ALGORITMO BUBBLE SORT ------------------*/
void BubbleSort(int *vet, int tam){
 clock_t inicio = clock();
	for (int i = tam-1; i > 0; i--){
		for (int d = 0; d < i; d++){
			if (vet[d] > vet[d+1]){
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
/*------------- ALGORITMO INSERT SORT -------------------*/
void InsertSort(int *vet, int tam){
 clock_t inicio = clock();
	for (int i = 1; i < tam; i++){
		int aux = vet[i];
		int d = i - 1;
		while (d >= 0 && vet[d] > aux){
			vet[d+1] = vet[d];
			d--;
		}
		vet[d+1] = aux;
	}
	double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
	printf("Tempo= %lf\n", tempo);
	ConverteTempo(tempo);
}
/*------------- ALGORITMO SHELL SORT --------------------------*/
void ShellSort(int *vet, int tamanho){
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
/*----------------- ALGORITMO SELECTION SORT -------------------------*/
void SelectionSort(int *vet, int tamanho)
{
    int i, j, menor, aux;
 		clock_t inicio = clock();
    for (i = 0; i < tamanho-1; i++){
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
/*---------------- ALGORITMO QUICK SORT -----------------------*/

void QuickSort(int *a, int l, int r) {
    int i, j, x, y;

    i = l;
    j = r;
    x = a[(l + r)/ 2];
      clock_t inicio = clock();
    while(i <= j) {
        while(a[i] < x && i < r) {
            i++;
        }
        while(a[j] > x && j > l) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;

        }
    }

    if(j > l) {
        QuickSort(a, l, j);
    }
    if(i < r) {
        QuickSort(a, i, r);
    }
		double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
		printf("Tempo= %lf\n", tempo);
		ConverteTempo(tempo);
}
/*--------------- ALGORITMO MERGE SORT ---------------------------*/
void merge(int *v, int *c, int i, int m, int f) {
  int z,
      iv = i, ic = m + 1;

  for (z = i; z <= f; z++) c[z] = v[z];
  z = i;

  while (iv <= m && ic <= f) {

    if (c[iv] < c[ic]) v[z++] = c[iv++];
    else v[z++] = c[ic++];
  }

  while (iv <= m) v[z++] = c[iv++];
  while (ic <= f) v[z++] = c[ic++];
}
void sort(int *v, int *c, int i, int f) {
  if (i >= f) return;

  int m = (i + f) / 2;
  sort(v, c, i, m);
  sort(v, c, m + 1, f);

  if (v[m] <= v[m + 1]) return;

  merge(v, c, i, m, f);
}

void MergeSort(int *v, int n) {
  int *c;
	c = (int *) malloc(n * sizeof(int));

	clock_t inicio = clock();
  sort(v, c, 0, n - 1);
  free(c);
	double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
	printf("Tempo= %lf\n", tempo);
	ConverteTempo(tempo);
}

/*------------------ ALGORITMO MERGE SORT -----------------------------*/

void Peneira(int *vet, int raiz, int fundo) {
	int pronto, filhoMax, tmp;

	pronto = 0;
	while ((raiz*2 <= fundo) && (!pronto)) {
		if (raiz*2 == fundo) {
			filhoMax = raiz * 2;
		}
		else if (vet[raiz * 2] > vet[raiz * 2 + 1]) {
			filhoMax = raiz * 2;
		}
		else {
			filhoMax = raiz * 2 + 1;
		}

	if (vet[raiz] < vet[filhoMax]) {
		tmp = vet[raiz];
		vet[raiz] = vet[filhoMax];
		vet[filhoMax] = tmp;
		raiz = filhoMax;
    }
	else {
      pronto = 1;
	}
  }
}
void HeapSort(int *vet, int n) {
	int i, tmp;
clock_t inicio = clock();
	for (i = (n / 2); i >= 0; i--) {
		Peneira(vet, i, n - 1);
	}

	for (i = n-1; i >= 1; i--) {
		tmp = vet[0];
		vet[0] = vet[i];
		vet[i] = tmp;
		Peneira(vet, 0, i-1);
	}
	double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
	printf("Tempo= %lf\n", tempo);
	ConverteTempo(tempo);
}
/*---------------------- ALGORITMO RADIX SORT -------------------------*/
void RadixSort(int vetor[], int tamanho) {
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;
clock_t inicio = clock();
    b = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < tamanho; i++)
    	    bucket[(vetor[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	for (i = 0; i < tamanho; i++)
    	    vetor[i] = b[i];
    	exp *= 10;
    }

    free(b);
		double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
		printf("Tempo= %lf\n", tempo);
		ConverteTempo(tempo);
}

/*-----------------------------------------------*/
int main (){
int i, *vetor, tamanho, op;
FILE *arquivo, *resultado;
char nomeArquivo[255];

printf("Quantidade de dados:\n1 - 500.000\n2 - 750.000\n3 - 1.000.000\n4 - 5.000.000\n5 - 10.000.000\n6 - 15.000.000\n");
scanf("%d", &op);

switch (op) {
	case 1: tamanho = 500000; break;

  case 2:	tamanho = 750000; break;

  case 3: tamanho = 1000000; break;

  case 4:	tamanho = 5000000; break;

  case 5:	tamanho = 10000000; break;

	case 6: tamanho = 15000000; break;

  default:
    printf("Erro!");
    break;
}

op = 0;
printf("Tipo de dados:\n1 - ORDENADOS\n2 - INVERTIDOS\n3 - ALEATORIOS\n");
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
printf("Método de ordenação:\n1 - BubbleSort\n2 - InsertSort\n3 - Shell Sort\n4 - Selection Sort\n5 - Quick Sort\n6 - Merge Sort\n7 - Heap Sort\n8 - Radix Sort");
scanf("%d", &op);

switch (op) {
  case 1:	BubbleSort(vetor, tamanho);
  break;

  case 2: InsertSort(vetor, tamanho);
  break;

	case 3: ShellSort(vetor, tamanho);
	break;

	case 4: SelectionSort(vetor, tamanho);
	break;

	case 5: QuickSort(vetor, 0, tamanho - 1);
	break;

	case 6: MergeSort(vetor, tamanho);
	break;

	case 7: HeapSort(vetor, tamanho);
	break;

	case 8: RadixSort(vetor, tamanho);

  default:
    printf("Erro!");
    break;
}
}
