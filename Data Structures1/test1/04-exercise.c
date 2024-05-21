#include <stdio.h>
#include <stdlib.h>



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

void insertEnd(NODE *head){
    NODE *newNodo = (NODE *)malloc(sizeof(NODE));
    printf("Enter a number: ");
    scanf("%d", &newNodo->data);

    if(emptyList(head)){
        head->link = newNodo;
        newNodo->link = NULL;
    }
    else{
        NODE *aux = head->link;
        while(aux->link != NULL){
            aux = aux->link;
        }
        aux->link = newNodo;
        newNodo->link = NULL;
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

void joiningLists(NODE *head1, NODE *head2){
    NODE *aux1, *aux2;
    aux1 = head1->link;
    aux2 = head2->link;
    while(aux1 != NULL){
        aux1 = aux1->link;
        

    }
    

}

int main(void){
 

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
    insertEnd(l1Head);
    x += 1;
 }
 printf("Enter the size of the list 2: "); 
 int size2;
 scanf("%d", &size2);
 int y = 0;
 while(y < size2){
    insertEnd(l2Head);
    y += 1;
 }

 showList(l1Head);


    return 0;
}