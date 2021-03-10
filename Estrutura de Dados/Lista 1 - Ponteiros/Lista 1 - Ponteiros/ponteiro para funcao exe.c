#include <stdio.h>
/* funcao de ordenacao Bubble Sort */
void bubbleSort(void* dados[], int tam, int (*pfc)(void*, void*))
{
    int i, j;
    int temp;
    for (i=0; i<tam-1; i++){
       printf("Iteracao %d  \n", i+1);
       for (j=0; j<tam-(i+1); j++){
         if (dados[j] > dados[j+1]){
            printf("  Trocando... \n");
            temp       = dados[j];
            dados[j]   = dados[j+1];
            dados[j+1] = temp;
         }
       }
    }

}

  int compararInteiros(void*, n1, void* n2)
  {
    return *((int*)n1) - *((int*)n2);
  }

  struct Data{
    int dia, mes, ano;
  };

int compararDatas(void*, d1, void* d2)
{

struct Data *data1 = (struct Data*) d1;
struct Data *data2 = (struct Data*) d2;

return (data1->ano - data2-> ano) *365 +

}



/* programa principal */
void main()
{
   int i;
   int vi[3];
   vi[0] = (int*) malloc(sizeof(int));
   *vi[0]=6;

   vi[1] = (int*) malloc(sizeof(int));
   *vi[1]=3;

   vi[2] = (int*) malloc(sizeof(int));
   *vi[2]=5;


   bubbleSort(vi, 3, compararInteiros);

   for (i=0; i<3; i++){
      printf("%d - ", *vi[i]);
   }

   struct Data* vd[3];
   vd[0] = (struct Data*) malloc(sizeof(struct Data));
   *vd[0].dia = 5;
   *vd[0].mes = 1;
   *vd[0].ano = 2017;

   vd[1] = (struct Data*) malloc(sizeof(struct Data));
   *vd[1].dia = 10;
   *vd[1].mes = 10;
   *vd[1].ano = 2017;

   vd[2] = (struct Data*) malloc(sizeof(struct Data));
   *vd[2].dia = 5;
   *vd[2].mes = 5;
   *vd[2].ano = 2017;

   bubbleSort(vd, 3, compararInteiros);



}
