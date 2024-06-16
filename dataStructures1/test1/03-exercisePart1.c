#include <stdio.h>
#include <stdlib.h>

typedef struct stackPX{
    int top;
    int items[5];
}StackPX;

int empty(StackPX *stack){
    return (stack->top == -1) ? 1:0;
}

void push(StackPX *stack, int x){
    if(stack->top >= 4){
        printf("\nA pilha esta cheia\n");
        exit(1);
    }
    else{
        stack->top += 1;
        stack->items[stack->top] = x;
    }
}

int pop(StackPX *stack){
    if(!empty(stack)){
        int returnedValue = stack->items[stack->top];
        stack->top -= 1;
        return returnedValue;
    }
    else{
        printf("\nA pilha esta vazia\n");
        return 0;
    }
}

void stack_copy(StackPX *stackOriginal, StackPX *stackCopy){
    int vetAux[5];
    if(empty(stackOriginal)){
            printf("\nA stack original esta vazia!\n");
        }
    else{
        int x = 0;
        while(x <= 4){
            vetAux[x] = pop(stackOriginal);
            x += 1;
        }
        for(int index = 4; index > -1; index--){
            push(stackCopy, vetAux[index]);
        }
    }
}

void mostrar(StackPX *stack){
    for(int j=4; j>=0; j--){
        printf("%d\n", stack->items[j]);
    }
}


int main(void){

 StackPX *stackOriginal = (StackPX*)malloc(sizeof(StackPX));
 StackPX *stackCopy = (StackPX*)malloc(sizeof(StackPX));
 stackOriginal->top = -1; // inicializando o topo da lista
 stackCopy->top = -1;
 
 printf("\n----- PREENCHENDO A PILHA ORIGINAL -----\n\n");
 for(int i = 0; i<5; i++){
    int number;
    printf("Digite um valor:  ");
    scanf("%d", &number);
    push(stackOriginal, number);
 }
 
 printf("\n--- Stack Original ---\n");
 mostrar(stackOriginal);
 stack_copy(stackOriginal, stackCopy);
 printf("\n\n");
 printf("--- Stack Copia preservando os dados ---\n");
 mostrar(stackCopy);
 
    return 0;
}