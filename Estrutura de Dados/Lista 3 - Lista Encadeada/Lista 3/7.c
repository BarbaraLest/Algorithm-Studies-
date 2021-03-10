#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

int comparaInteiro(void *info1, void *info2){
  int *n1 = (int*) info1;
  int *n2 = (int*) info2;

  return *n1 - *n2;
}

void imprimeInteiro(void *info){
   printf("\n%d - ", *((int *) info));
}

int main(void){

  struct DLista *lista;

  int a = 1, b = 2, c = 3, d = 6;

  lista = criarLista();

  incluirInfo(lista, &a);
  incluirInfo(lista, &b);
  incluirInfo(lista, &c);

  incluirInfoPosicao(lista, &d, 2);
  mostrarLista(lista, imprimeInteiro);

}
