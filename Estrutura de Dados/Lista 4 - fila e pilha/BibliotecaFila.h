#include <stdio.h>
#include "Comum.h"
#include <stdlib.h>

/* --------------------------*/
struct DFila{
   struct Noh *primeiro;
   struct Noh *ultimo;
   int         qtdeNohs;
};

/* --------------------------*/
struct DFila* criarFila(){

   struct DFila *desc;

   desc=(struct DFila*)malloc(sizeof(struct DFila));
   desc->primeiro = NULL;
   desc->ultimo   = NULL;
   desc->qtdeNohs = 0;

   return desc;
}

/* --------------------------*/
void enfileira(struct DFila *fila, void *info){

    struct Noh *novo;

    novo = (struct Noh*) malloc(sizeof(struct Noh));

    novo->info     = info; /* (*novo).info = info; */
    novo->prox     = NULL;

    /* atulaiza o descritor*/
    if (fila->qtdeNohs == 0)
        fila->primeiro = novo;
     else
        fila->ultimo->prox = novo;

    fila->ultimo = novo;
    fila->qtdeNohs++;
}

/* --------------------------*/
void mostrarFila(struct DFila *fila, funcaoImpressao fi){

    struct Noh *atual;

    atual = fila->primeiro;

    while(atual != NULL){

        fi(atual->info);
        atual = atual->prox;
    }
}



void* desenfileira(struct DFila    *fila){

    struct Noh *atual;

    atual = fila->primeiro;

    if (atual != NULL){

        fila->qtdeNohs--;

        fila->primeiro = atual->prox;

        void *auxInfo = atual->info;

        free(atual);

        return auxInfo;
    }

    return NULL;

}


void* inicio(struct DFila *fila){

    if (fila->primeiro != NULL)
        return fila->primeiro->info;

    return NULL;
}
