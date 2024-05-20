#include <stdio.h>
#include <stdlib.h>

/*Aqui a impementação da lista esta sendo levada ao pé da letra. Alocamos um nodo na main 
que será o primeiro nodo da lista, a cabeca. Para implementar deste jeito, usamos ponteiro duplo 
na funcao de inserção, pois a gente tem que passar o endereço da variavel que contem o primeiro nodo. Como a variavel "head"
na main é na verdade o endereço do primeiro nodo, a gente passa para a funcao de inserir o endereco
da head,ou seja, o endereco da variavel que contém o endereco da head*/



typedef struct nodo{
    int data;
    struct nodo *nodo;
}NODO;


void insereNoinicio(NODO *firstNodo){ // ver mais sobre este ponteiro duplo
     NODO *newNodo = (NODO*)malloc(sizeof(NODO));
     printf("Enter a Number: ");
     int number;
     scanf("%d", &newNodo->data);
     
     newNodo->nodo = firstNodo;
     firstNodo = newNodo;
}


void printList(NODO *firstNodo){

    NODO *temp = firstNodo;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->nodo;
    }
}

int main(void){
  
  NODO *ptrHead;
  ptrHead = (NODO *)malloc(sizeof(NODO));
  if(ptrHead == NULL){
    return 1;
  }
  //ptrHead->nodo = NULL; // uma tentativa de inicializar um nodo
  int x = 4;
    while(x > 0){
        insereNoinicio(ptrHead);
        x -= 1;
  }
  printList(ptrHead);
  free(ptrHead);

    return 0;
}