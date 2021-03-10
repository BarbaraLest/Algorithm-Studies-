#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"


void imprimeInteiro(void *info) {
   printf("\n%d - ", *((int *) info));
}


int main(void) {

  struct DLista *lista;

  int a = 7, b = 8, c = 9;


  lista = criarLista();

  incluirInfo(lista, &a);
  incluirInfo(lista, &b);
  incluirInfo(lista, &c);

  mostrarListaRecursivamente(lista, imprimeInteiro);

}
