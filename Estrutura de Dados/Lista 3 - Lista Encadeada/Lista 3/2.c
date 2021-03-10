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


int main(void) {

  struct DLista *lista1;
  struct DLista *lista2;
  struct DLista *listaf;

  int a = 1, b = 2, c = 3;
  int e = 4, f = 2, g = 3;

  lista1 = criarLista();
  lista2 = criarLista();

  incluirInfo(lista1, &a);
  incluirInfo(lista1, &b);
  incluirInfo(lista1, &c);


  incluirInfo(lista2, &e);
  incluirInfo(lista2, &f);
  incluirInfo(lista2, &g);

  listaf = intersecao(lista1, lista2, comparaInteiro);
  mostrarLista(listaf, imprimeInteiro);
}
