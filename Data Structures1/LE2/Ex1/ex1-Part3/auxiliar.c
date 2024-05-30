#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack{
    void *data;
    struct node *link;
} Stack;

typedef struct{ // esta estrutura terá um contador, total de nodes e o ponteiro para o primeiro node da lista
    int count;
    Stack *top;
} HeadStack; // pq "head"?" pois é atraves desta "cabeca" que iremos acessar a pilha


int empty(HeadStack *head){
    return (head->count == 0) ? 1:0; // pq esta vendo pela count e não pelo topo?
}

HeadStack *creatStack(void){ // aqui é a criacao da head, ou seja, a criacao da pilha
    HeadStack *head;
    head = (HeadStack*)malloc(sizeof(HeadStack));
    if(head){
        head->count = 0;
        head->top = NULL;
    }
    return head;
}

bool push(HeadStack *head, void *data){
   
    Stack *newNode = (Stack*)malloc(sizeof(Stack));
    if(!newNode){
        return false;
    }
    else{
        newNode->data = data;
        newNode->link = head->top;
        head->top = newNode;

        head->count++;
        return true;        
    }
}

void *pop(HeadStack *head){
    void *auxData;

    if(empty(head)){
        auxData = NULL;
    }
    else{
        Stack *aux = head->top; // guardando o primeiro node
        void *auxData = head->top->data; // pegando o dado do primeiro node
        head->top = head->top->link; // fazendo a cabeca apontar para o segundo node
        free(aux); 
        head->count --;
    }    
    return auxData;
}

void *elementTop(HeadStack *head){
    if(empty(head)){
        return NULL;
    }
    else{
        return head->top->data;
    }
}

bool fullStack(HeadStack *head){
    Stack *verification;
    verification = (Stack*)malloc(sizeof(*(head->top)));
    if(verification){
        free(verification);
        return false;
    }

    return true; // significa que a pilha esta cheia
}

