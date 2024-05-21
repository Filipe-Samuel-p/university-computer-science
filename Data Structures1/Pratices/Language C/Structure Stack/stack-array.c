#include <stdio.h>
#include <stdlib.h>

// Implementação de uma filha usando contiguidade (sequencia) fisica, neste caso, usando array


// Uma pilha de inteiros

typedef struct stack{
    int top;
    int items[10]; // tamanho da pilha
} Stack;

int empty(Stack *stack){
   return (stack->top == -1) ? 1:0;
}

void push(Stack *stack, int x){
    if(stack->top >= 10){
        printf("Pilha cheia");
        exit(1);
    }
    else{
       stack->items[stack->top + 1] = x;
       stack->top += 1; 
    }
}

void pop(Stack *stack){
    if(!empty(stack)){
        int returnedValue = stack->items[stack->top];
        stack->top -= 1;
        printf("\nReturned value: %d\n", returnedValue);    
    }
    else{
        printf("Lista vazia");
    }
}

int main(void){
 
 Stack *stack;
 stack = (Stack*)malloc(sizeof(Stack));
 stack->top = -1; // inicializando o topo da lista
 int opcao;

 do{
    printf("\n\n------ opcoes da lista ------\n\n");
    printf("[1]- Adicionar elemento na pilha\n");
    printf("[2]- remover elemento na pilha\n");
    printf("[3]- exibir elementos na pilha\n"); // A exibição só é feita mediante retirada dos elementos do topo
    printf("[4]- aperte 4 para sair");
    printf("\nEntre com uma opcao:  ");
    
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        printf("Entre com o valor que quer adicionar: ");
        int number;
        scanf("%d", &number);
        push(stack, number);
        printf("\nNumero adicionado");
        break;
    case 2:
        pop(stack);
        break;
    case 3:
        if(empty(stack)){
            printf("Pilha vazia");
            exit(1);
        }
        else{
            while(stack->top != -1){
                pop(stack);
            }
        }
        break;
    case 4:
        exit(1);
        break;
    default:
        printf("digite um valor valido: ");
        break; 
    }
 } while(opcao != 4 || stack->top != 9); 
 
    return 0;
}