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
  int res;

  int a = 1, b = 2, c = 3;
  int e = 4, f = 7, g = 5;

  lista1 = criarLista();
  lista2 = criarLista();

  incluirInfo(lista1, &a);
  incluirInfo(lista1, &b);
  incluirInfo(lista1, &c);


  incluirInfo(lista2, &e);
  incluirInfo(lista2, &f);
  incluirInfo(lista2, &g);


  res = disjunta(lista1, lista2, comparaInteiro);
  printf("Caso as listas sejam disjuntas, o resultado sera 1, caso contrario, sera 0.\nFinal: %d\n", res);


}
