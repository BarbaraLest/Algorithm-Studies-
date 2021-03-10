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
/*-----------------------------------------------*/
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

/*-----------------------------------------------*/
int main (){
int i, *vetor, tamanho, op;
FILE *arquivo, *resultado;
char nomeArquivo[255];

printf("Quantidade de dados:\n1- 500.000\n2-750.000\n3-1.000.000\n4-10.000.000\n");
scanf("%d", &op);

switch (op) {
  case 1: tamanho = 500000; break;

  case 2:	tamanho = 750000; break;

  case 3:	tamanho = 1000000; break;

	case 4: tamanho = 10000000; break;

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
printf("Método de ordenação:\n1-QuickSort\n2-MergeSort\n");
scanf("%d", &op);

switch (op) {
  case 1: QuickSort(vetor, 0, tamanho - 1);
  break;
  case 2: MergeSort(vetor, tamanho);
  break;
  default:
    printf("Erro!");
    break;
}


}
