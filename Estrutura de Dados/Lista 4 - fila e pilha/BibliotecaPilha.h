#include <stdio.h>
#include "Comum.h"
#include <stdlib.h>

/* --------------------------*/
struct DPilha{
   struct Noh *topo;
   int         qtdeNohs;
};

/* --------------------------*/
struct DPilha* criarPilha(){

   struct DPilha *desc;

   desc=(struct DPilha*)malloc(sizeof(struct DPilha));
   desc->topo = NULL;
   desc->qtdeNohs = 0;

   return desc;
}

/* --------------------------*/
void empilha(struct DPilha *pilha, void *info){

    struct Noh *novo;

    novo = (struct Noh*) malloc(sizeof(struct Noh));

    novo->info     = info; /* (*novo).info = info; */
    novo->prox     = pilha->topo;

    pilha->topo = novo;
    pilha->qtdeNohs++;
}

/* --------------------------*/
void mostrarPilha(struct DPilha *pilha, funcaoImpressao fi){

    struct Noh *atual;

    atual = pilha->topo;

    while(atual != NULL){

        fi(atual->info);
        atual = atual->prox;
    }
}



void* desempilha (struct DPilha  *pilha){

    struct Noh *atual;

    atual = pilha->topo;

    if (atual != NULL){

        pilha->qtdeNohs--;
        pilha->topo = atual->prox;

        void *auxInfo = atual->info;
        free(atual);

        return auxInfo;
    }

    return NULL;

}


void* topo(struct DPilha  *pilha){

    if (pilha->topo != NULL)
        return pilha->topo->info;

    return NULL;
}
