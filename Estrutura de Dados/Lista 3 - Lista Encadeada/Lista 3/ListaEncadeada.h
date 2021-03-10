#include <stdio.h>

typedef int  (*funcaoComparacao)(void*, void*);
typedef void (*funcaoImpressao)(void*);



/* --------------------------*/
struct Noh{
   void       *info;
   struct Noh *prox;
};

/* --------------------------*/
struct DLista{ // Descritor
   struct Noh *primeiro;
   struct Noh *ultimo;
   int         qtdeNohs;
};

/* --------------------------*/
struct DLista* criarLista(){

   struct DLista *desc;

   desc=(struct DLista*)malloc(sizeof(struct DLista));
   desc->primeiro = NULL;
   desc->ultimo   = NULL;
   desc->qtdeNohs = 0;

   return desc;
}

/* --------------------------*/
void incluirInfo(struct DLista *lista, void *info){

    struct Noh *novo;

    novo = (struct Noh*) malloc(sizeof(struct Noh));

    novo->info     = info; /* (*novo).info = info; */
    novo->prox     = NULL;

    /* atulaiza o descritor*/
    if (lista->qtdeNohs == 0)
        lista->primeiro = novo;
     else
        lista->ultimo->prox = novo;

    lista->ultimo = novo;
    lista->qtdeNohs++;
}

/* --------------------------*/
void mostrarLista(struct DLista *lista, funcaoImpressao fi){

    struct Noh *atual;

    atual = lista->primeiro;

    while(atual != NULL){

        fi(atual->info);
        atual = atual->prox;
    }
}

/* --------------------------*/

void excluirInfo(struct DLista     *lista,
                void              *info,
                funcaoComparacao  fc){

    struct Noh *atual, *ant;

    atual = lista->primeiro;
    ant   = NULL;

    while(atual != NULL){

        if (fc(info, atual->info)==0)
            break;

        ant   = atual;
        atual = atual->prox;
    }

    if (atual != NULL){

        lista->qtdeNohs--;

        if (atual == lista->primeiro){
            lista->primeiro = atual->prox;
        } else
        if (atual == lista->ultimo){
            lista->ultimo = ant;
            ant->prox     = NULL;
        } else{
            ant->prox = atual->prox;
        }

        free(atual);
    }

}


int buscarInfo(struct DLista *lista, void *info, funcaoComparacao fc){
    struct Noh *atual;
     atual = lista->primeiro;

     while(atual != NULL){ // Se sao iguais retorna 1
        if(fc(atual->info, info) == 0){
            return 1;
        }

        atual = atual->prox;
     }

    return 0;
}

struct DLista* Uniao(struct DLista* lista1, struct DLista* lista2, funcaoComparacao fc){

    struct DLista *novaLista;
    novaLista = criarLista();

    struct Noh *atual1;
    struct Noh *atual2;

    atual1 = lista1->primeiro;
    atual2 = lista2->primeiro;

    while (atual1 != NULL || atual2 != NULL){
        if (atual1 != NULL){
            if (buscarInfo(novaLista, atual1->info, fc) == 0){
                incluirInfo(novaLista, atual1->info);
            }
            atual1 = atual1->prox;
        }

        if (atual2 != NULL){
            if (buscarInfo(novaLista, atual2->info, fc) == 0){
                incluirInfo(novaLista, atual2->info);
            }
          atual2 = atual2->prox;
        }
    }

    return (novaLista);
}


struct DLista* intersecao (struct DLista* lista1, struct DLista* lista2, funcaoComparacao fc){

  struct DLista *novaLista;
  struct Noh *atual1;
  struct Noh *atual2;


  novaLista = criarLista();

  atual1 = lista1 -> primeiro;
  atual2 = lista2 -> primeiro;

  while (atual2 != NULL){
    while (atual1 != NULL){
      if (fc(atual1 -> info, atual2 -> info) == 0 && buscarInfo(novaLista, atual1 -> info, fc) == 0){
        incluirInfo(novaLista, atual1 -> info);
        break;
      }
      atual1 = atual1 -> prox;
    }
    atual1 = lista1 -> primeiro;
    atual2 = atual2 -> prox;
}

  return (novaLista);
}


int disjunta (struct DLista* lista1, struct DLista* lista2, funcaoComparacao fc){

  struct Noh *atual1;
  struct Noh *atual2;

  int confirma = 1;

  atual1 = lista1 -> primeiro;
  atual2 = lista2 -> primeiro;

  while (atual2 != NULL){
    while (atual1 != NULL){
    if (fc(atual1 -> info, atual2 -> info) == 0){
      confirma = 0;
      break;
    }
    atual1 = atual1 -> prox;
  }
  atual1 = lista1 -> primeiro;
  atual2 = atual2 -> prox;
}

  return(confirma);
}


int contida (struct DLista * lista1, struct DLista * lista2, funcaoComparacao fc){

  struct Noh *atual1;
  struct Noh *atual2;

  int verifica = 0;
  int confirma = 0;

  atual1 = lista1 -> primeiro;
  atual2 = lista2 -> primeiro;

  while (atual2 != NULL){
    while (atual1 != NULL){
    if (fc(atual1 -> info, atual2 -> info) == 0){
      verifica ++;
      break;
    }
    atual1 = atual1 -> prox;
  }
  atual1 = lista1 -> primeiro;
  atual2 = atual2 -> prox;
}
  if (verifica == lista1 -> qtdeNohs || verifica == lista2 -> qtdeNohs){
    confirma = 1;
  }

  return (confirma);
}

void ordenar (struct DLista * lista, funcaoComparacao fc) {
    struct Noh* atual;
    struct Noh* ant;
    struct Noh* next;
    struct Noh* temp;

    atual = (struct Noh*) malloc(sizeof(struct Noh));
    ant = (struct Noh*) malloc(sizeof(struct Noh));
    next = (struct Noh*) malloc(sizeof(struct Noh));

    ant = NULL;

    for (int i = 0; i < lista->qtdeNohs; i++) {
        atual = lista->primeiro;
        while (atual->prox != NULL) {
            next = atual->prox;
            if (atual == lista->primeiro) {
                if (fc(atual->info, next->info) > 0) {
                    atual->prox = next->prox;

                    next->prox = atual;

                    ant = next;

                    lista->primeiro = next;
                }
                else {
                    ant = atual;
                    atual = atual->prox;
                }
            }
            else {
                if (fc(atual->info, next->info) > 0) {
                    if (next->prox == NULL) {
                        atual->prox = NULL;

                        ant->prox = next;

                        next->prox = atual;

                        ant = next;

                        lista->ultimo = atual;
                    }
                    else {
                        atual->prox = next->prox;

                        ant->prox = next;

                        next->prox = atual;

                        ant = next;
                    }
                }
                else {
                    ant = atual;
                    atual = next;
                }
            }
        }
    }
}

void mostrarListaRecursivamente(struct DLista *lista, funcaoImpressao fi){

     mostrarListaRecursivo(lista->primeiro, fi);
}

void mostrarListaRecursivo(struct Noh *atual, funcaoImpressao fi){
    if (atual == NULL)
        return;

    fi(atual->info);
    mostrarListaRecursivo(atual->prox, fi);
}

void incluirInfoNoInicio(struct DLista *lista, void *info){

  struct Noh *novo;

  novo = (struct Noh*) malloc(sizeof(struct Noh));

  novo -> info = info;
  novo -> prox = lista -> primeiro;

  lista -> primeiro = novo;
  lista->qtdeNohs++;

}

struct DLista *inverteListaFuncao (struct DLista * lista) {
    struct DLista* desc;

    desc = criarLista();

    struct Noh* atual;

    atual = (struct Noh*) malloc(sizeof(struct Noh));

    atual = lista->primeiro;

    while (atual != NULL) {
        incluirInfoPosicao(desc, atual->info, 0);
        atual = atual->prox;
    }

    return desc;
}

void inverteListaMetodo (struct DLista * lista) {
    struct Noh* atual;
    struct Noh* ant;
    struct Noh* temp;

    atual = (struct Noh*) malloc(sizeof(struct Noh));
    ant = (struct Noh*) malloc(sizeof(struct Noh));
    temp = (struct Noh*) malloc(sizeof(struct Noh));

    ant = lista->primeiro;
    atual = ant->prox;
    temp = atual->prox;
    ant->prox = NULL;

    while (atual != NULL) {
        temp = atual->prox;
        atual->prox = ant;

        ant = atual;
        atual = temp;
    }

    temp = lista->primeiro;
    lista->primeiro = lista->ultimo;
    lista->ultimo = temp;
}

void incluirInfoPosicao(struct DLista *lista, void *info, int n) {

    int cont = 0;

    struct Noh *novo;
    novo = (struct Noh*) malloc(sizeof(struct Noh));

    struct Noh *atual;
    atual = (struct Noh*) malloc(sizeof(struct Noh));
    atual = (*lista).primeiro;

    struct Noh *anterior;
    anterior = (struct Noh*) malloc(sizeof(struct Noh));

    if (n == 0) {
        lista -> primeiro = novo;
    }
    else if (n == (lista -> qtdeNohs)-1) {
        lista -> ultimo = novo;
    }
    else if (n > (lista -> qtdeNohs)) {
        printf("n maior que quantidade de nohs na lista");
        return;
    }

    novo -> info = info;

    while (cont < n) {
        anterior = atual;
        atual = atual -> prox;
        cont++;
    }

    anterior -> prox = novo;
    novo -> prox = atual;
    lista -> qtdeNohs++;

}
