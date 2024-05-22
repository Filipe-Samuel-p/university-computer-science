#include <stdio.h>
#include <stdlib.h>
#include <time.h>



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

void insertEnd(NODE *head, int x){
    NODE *newNodo = (NODE *)malloc(sizeof(NODE));
    newNodo->data = x;
    
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
   NODE *aux1 = head1->link;
   while(aux1 != NULL){
    insertEnd(head2, aux1->data);
    aux1 = aux1->link;
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
    int number = rand()%20;
    insertEnd(l1Head, number);
    x += 1;
 }

 printf("Enter the size of the list 2: "); // preenchimento da L1
 int size2;
 scanf("%d", &size2);
 int y = 0;
 while(y < size2){
    int number2 = rand()%20;
    insertEnd(l2Head, number2);
    y += 1;
 }

 
 showList(l1Head);
 printf("\n");
 showList(l2Head);
 joiningLists(l1Head, l3Head);
 joiningLists(l2Head, l3Head);
 printf("\n\n LISTA 3 \n\n");
 showList(l3Head);
 
 
    return 0;
}