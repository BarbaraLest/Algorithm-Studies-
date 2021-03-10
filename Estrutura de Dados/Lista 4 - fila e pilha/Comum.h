#include <stdio.h>
#include <stdlib.h>

#ifndef BLOCO1

#define BLOCO1

typedef int  (*funcaoComparacao)(void*, void*);
typedef void (*funcaoImpressao)(void*);

/* --------------------------*/
struct Noh{
   void       *info;
   struct Noh *prox;
};

#endif // BLOCO1
