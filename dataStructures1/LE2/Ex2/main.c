#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define STACKSIZE 100

typedef struct stack{
    int top;
    char stackItems[STACKSIZE];
} Stack;

void startStack(Stack *stack){
    stack->top = -1; 
}

int empty(Stack *stack){
    return (stack->top == -1) ? 1:0;
}


void push (Stack *stack, char z){
    if(stack->top + 1 == STACKSIZE){
        printf("\n Pilha cheia\n");
    }
    else{
        stack->top++;
        stack->stackItems[stack->top] = z;
    }

}

char pop(Stack *stack){
    if(empty(stack)){
        printf("\n Pilha vazia\n");
        return 'x';
    }
    else{
        char aux = stack->stackItems[stack->top];
        stack->top--;
        return stack->stackItems[aux];
    }
}






int main(void){




    return 0;
}