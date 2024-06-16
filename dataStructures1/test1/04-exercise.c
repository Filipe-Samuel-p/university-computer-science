#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>



typedef struct node{
    int data;
    struct node *link;
}NODE;

int emptyList(NODE *head){
   return (head->link == NULL) ? 1:0;
}

void startList(NODE *head){
    head->link = NULL;
}

void insertionEnd(NODE *head, int x){    
    NODE  *newNodo = (NODE *)malloc(sizeof(NODE));
    newNodo->data = x;
    if(!newNodo){
        printf("No alocation");
        exit(1);
    }
    else{
        if(emptyList(head)){ // verificacao para caso a lista seja vazia
        head->link = newNodo;
        newNodo->link = NULL;
        }
        else
        {
        NODE *aux = head->link;
        while(aux->link != NULL){
            aux = aux->link;
        }
        aux->link = newNodo;
        newNodo->link = NULL;
        }
    }
}

void showList(NODE *head){
    if(emptyList(head)){
        printf("\n Empty List\n");
        exit(1);
    }
    else{
        NODE *aux = head->link;
        while(aux != NULL){
            printf("%d\t", aux->data);
            aux = aux->link;
        }
    }
}

void inserirOrdenado(NODE *head, int x) {
    NODE *newNodo = (NODE*)malloc(sizeof(NODE));
    newNodo->data = x;
    newNodo->link = NULL;
    if(!newNodo){
        printf("\nNo alocation\n");
        exit(1);
    }
    else{

        if (head == NULL || x < head->data) {
            newNodo->link = head;
            head = newNodo;
        } else {
            NODE *aux = head;
            // sabendo onde inserir
            while (aux->link != NULL && aux->link->data < x) {
                aux = aux->link;
            }   
            newNodo->link = aux->link;
            aux->link = newNodo;
        }
    }
}


void insertionOfElementsInList3(NODE *head1, NODE *head2, NODE *head3){

    NODE *aux1, *aux2;
    aux1 = head1->link;
    aux2 = head2->link;
    
    do{
        if(aux1 == NULL && aux2!= NULL){
            insertionEnd(head3,aux2->data);
            aux2 = aux2->link;
        }
        else if(aux1 != NULL && aux2 == NULL){
            insertionEnd(head3,aux1->data);
            aux1= aux1->link;
        }

        else if(aux1->data < aux2->data){
            insertionEnd(head3, aux1->data);
            aux1 = aux1->link;
        }
        else{
            insertionEnd(head3, aux2->data);
            aux2 = aux2->link;
        }   
    } while(!(aux1 == NULL && aux2 == NULL));
}

 void libera(NODE *head){
    if(emptyList(head)){
        free(head);
    }
    NODE *aux = head->link;
    while(aux != NULL){
        NODE *aux2 = aux->link;
        free(aux);
        aux = aux2;
    }
 }


int main(void){
 
 srand(time(NULL));
 NODE *l1Head = (NODE *)malloc(sizeof(NODE));
 NODE *l2Head = (NODE *)malloc(sizeof(NODE));
 NODE *l3Head = (NODE *)malloc(sizeof(NODE));
 
 startList(l1Head);
 startList(l2Head);
 startList(l3Head);

 printf("Enter the size of the list 1: "); // preenchimento da L1
 int size;
 scanf("%d", &size);
 int x = 0;
 while(x < size){
    int number = rand()%30;
    inserirOrdenado(l1Head,number);
    x += 1;
 }

 printf("Enter the size of the list 2: "); 
 int size2;
 scanf("%d", &size2);
 int y = 0;
 while(y < size2){
    int number2 = rand()%20;
    inserirOrdenado(l2Head, number2);
    y += 1;
 }

 
 showList(l1Head);
 printf("\n");
 showList(l2Head);
 insertionOfElementsInList3(l1Head,l2Head,l3Head);
 printf("\n\n");
 showList(l3Head);
 printf("\n\n Deseja preservar as listas? [1] para NAO e [2] para SIM: ");
 int choice;
 scanf("%d", &choice);
 switch (choice)
 {
 case 1:
    libera(l1Head);
    libera(l2Head);
    printf("\nListas apagadas");
    break;
 case 2:
    printf("\nListas preservadas");
    break;
 
 default:
    printf("Voce não digitou um valor válido");
    break;
 }

 //showList(l1Head); 

 //ree(l1Head);  
 //free(l2Head);  
 //free(l3Head);  
    return 0;
}