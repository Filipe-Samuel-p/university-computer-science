#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    void *data;
    struct node *link;
} Node;

typedef struct{
    int count;
    Node *firstNode;
    Node *lastNode;
} List;

List *creatList(){
    List *headLista = (List*)malloc(sizeof(List));
    if(headLista){
        headLista->count = 0;
        headLista->firstNode = NULL;
        headLista->lastNode = NULL;
    }
    else{
        printf("\nErro de alocacao\n");
        exit(1);
    }
    return headLista;
}

void insertOrdered(List *head, void *x) {

    Node *newNodo = (Node*)malloc(sizeof(Node));
    newNodo->data = x;
    newNodo->link = NULL;
    if(!newNodo){
        printf("\nNo alocation\n");
        exit(1);
    }
    else{

    if (head->firstNode == NULL || x < head->firstNode->data) {
        newNodo->link = head->firstNode;
        head->firstNode = newNodo;
    } else {
        Node *aux = head->firstNode;
        // sabendo onde inserir
        while (aux != NULL && aux->link->data < x) {
            aux = aux->link;
        }   
        newNodo->link = aux->link;
        aux->link = newNodo;
        }
    }
}

void showList(List *head){
    Node *aux = head->firstNode;
    
    while(aux != NULL){
        int value = (int*)(aux->data);
        printf("%d", value);
        aux = aux->link;
    }
}




int main(void){
    int number;
    int *data;

    List *head = creatList();
    printf("\nDigite um numero: ");
    data = (int*)malloc(sizeof(int));
    scanf("%d", &number);
    *data = number;
    insertOrdered(head, data);

    printf("\nDigite um numero: ");
    data= (int*)malloc(sizeof(int));
    scanf("%d", &number);
    *data = number;
    insertOrdered(head, data);

    showList(head);




    return 0;
}