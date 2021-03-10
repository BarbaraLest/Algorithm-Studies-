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

  struct DLista *lista;

  int a = 3, b = 5, c = 1, d = 7;


  lista = criarLista();

  incluirInfo(lista, &a);
  incluirInfo(lista, &b);
  incluirInfo(lista, &c);
  incluirInfo(lista, &d);

  printf("Antes: ");
  mostrarLista(lista, imprimeInteiro);

  ordenar(lista, comparaInteiro);

  printf("\nDepois: ");
  mostrarLista(lista, imprimeInteiro);

}
