#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int data;
    struct nodo *nodo;
}NODO;


int inicializacao(NODO *firstNodo){
    if(firstNodo->nodo==NULL){
        printf("A lista esta vazia");
    }
    else{
        firstNodo->nodo = NULL; // inicia a lista
    }
}

void insereNoinicio(NODO *firstNodo){
     NODO *newNodo = (NODO*)malloc(sizeof(NODO));
     printf("Enter a Number: ");
     int number;
     scanf("%d", &newNodo->data);
    
    newNodo->nodo= firstNodo;
}



int main(void){
  
  NODO *ptrLista,*headList;
  ptrLista = NULL;
  headList = (NODO *)malloc(sizeof(NODO));
  headList->data= 10;
  headList->nodo=NULL;
  ptrLista = headList;
  NODO *nodo2;
  nodo2 = (NODO *)malloc(sizeof(NODO));
  headList->nodo = nodo2;
  nodo2->data = 5;
  nodo2->nodo= NULL;

  NODO *temp;
  temp = headList;
  while(temp != NULL){
    printf("%d\n", temp->data);
    temp = temp->nodo;
  }




 
  



    return 0;
}