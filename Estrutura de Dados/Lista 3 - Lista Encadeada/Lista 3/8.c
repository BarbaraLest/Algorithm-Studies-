#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

int comparaInteiro(void *info1, void *info2) {
  int *n1 = (int*) info1;
  int *n2 = (int*) info2;

  return *n1 - *n2;
}

void imprimeInteiro(void *info) {
   printf("\n%d - ", *((int *) info));
}

int main()
{
    struct DLista* desc;
    struct DLista* descInvertida;

    desc = criarLista();
    descInvertida = criarLista();

    void* p;
    void* i;
    void* j;
    void* k;
    void* l;
    void* m;

    p = malloc(sizeof(int));
    i = malloc(sizeof(int));
    j = malloc(sizeof(int));
    k = malloc(sizeof(int));
    l = malloc(sizeof(int));
    m = malloc(sizeof(int));

    *(int*)p = 1;
    *(int*)i = 2;
    *(int*)j = 3;
    *(int*)k = 4;
    *(int*)l = 2;
    *(int*)m = 89;

    incluirInfo(desc, p);
    incluirInfo(desc, i);
    incluirInfo(desc, j);
    incluirInfo(desc, k);
    incluirInfo(desc, l);
    incluirInfo(desc, m);

    descInvertida = inverteListaFuncao(desc);
    inverteListaMetodo(desc);
    mostrarLista(descInvertida, imprimeInteiro);
    printf("\n/---------/\n");
    mostrarLista(desc, imprimeInteiro);
}
