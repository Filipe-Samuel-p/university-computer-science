#include <stdio.h>
#include <stdlib.h>

/*Uma outra forma de implementar uma lista. Neste caso, ao invés de usar "a real cabeça da lista" (o primeiro nodo)
a gente cria um nodo inicial e dentro do LINK deste nodo "genérico", é que a lista se inicia. Dizem que assim tem menos erros
entao, a cabeca/ primeiro nodo da lista, fica dentro deste nodo genérico */




typedef struct nodo{
    int dados;
    struct nodo *link;
}NODO;

void iniciaLista(NODO *head){
    head->link=NULL;
}

void inserirInicio(NODO *head){
    NODO *newNodo = (NODO*)malloc(sizeof(NODO));
    printf("Enter a number: ");
    scanf("%d", &newNodo->dados);
     
    NODO *oldHead = head->link; // necessário para guardar o endereco do nodo que era a cabeca. Neste caso, NULL
    head->link = newNodo;
    newNodo->link = oldHead;
    
}

void mostrarLista(NODO *head){
    NODO *temp;

   temp = head->link;
   while(temp != NULL){
    printf("%d\t", temp->dados);
    temp = temp->link;
   }
}

int main(void){
  
  NODO *headNodo;
  headNodo = (NODO*)malloc(sizeof(NODO));
  iniciaLista(headNodo);
  int x = 4;
  while(x > 0){
    inserirInicio(headNodo);
    x -= 1;
  }
  mostrarLista(headNodo);
  free(headNodo);
    return 0;
}