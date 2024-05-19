#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int data;
    struct nodo *nodo;
}NODO;


void insereNoinicio(NODO **firstNodo){ // ver mais sobre este ponteiro duplo
     NODO *newNodo = (NODO*)malloc(sizeof(NODO));
     printf("Enter a Number: ");
     int number;
     scanf("%d", &newNodo->data);
    
     newNodo->nodo= *firstNodo;
     *firstNodo = newNodo;
}


void printList(NODO *firstNodo){

    NODO *temp = firstNodo;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->nodo;
    }
}


int main(void){
  
  NODO *head;
  head = (NODO *)malloc(sizeof(NODO));
  if(head == NULL){
    return 1;
  }
  int x = 4;
    while(x > 0){
        insereNoinicio(&head);
        x -= 1;
  }
  printList(head);


    return 0;
}