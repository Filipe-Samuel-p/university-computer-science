#include <stdio.h>
#include <stdlib.h>

struct St_node{
    int valor;
    struct St_node *proximo; // um ponteiro para um tipo struct, serve para apontar para o proximo elemento
};

typedef struct St_node NODE;

int vazia(NODE *linked_list){ // Uma funcao que verifica se a lista esta vazia ou nao. 
    if (linked_list->proximo == NULL){ 
        return 1;
    }
    else{
        return 0;
    }
}

void inicia (NODE *linked_list){
    linked_list->proximo = NULL;
}

void libera(NODE *linked_list){
    if(!vazia(linked_list)){
        NODE *proximoNo, *atual;
        atual = linked_list->proximo;
        while(atual == NULL){
            proximoNo = atual->proximo; // pegando o valor do proximo nó e passando para o atual.
            free(atual);  // limpando o atual
            atual = proximoNo; //  dizendo que o atual receberá o proximo no
        }
    }
}

void exibe(NODE *linked_lis){
    if(vazia(linked_lis)){
        printf("A lista esta vazia");
        return;
    }
    else{
        NODE *tmp;
        tmp = linked_lis->proximo;

        while(tmp != NULL){
            printf("%d ", tmp->valor);
            tmp = tmp->proximo;
        }
    }
    printf("\n\n");
}

void insere_inicio(NODE *linked_list){
    NODE *novo = (NODE *)malloc(sizeof(NODE));
    if(!novo){
        printf("Sem memória");
        exit(1);
    }
    printf("Digite um valor: ");
    scanf("%d", &novo->valor);

    NODE *old_head = linked_list->proximo;
    linked_list->proximo = novo;
    novo->proximo = old_head;
}

void insere_fim(NODE *linked_list){
    NODE *novo = (NODE *)malloc(sizeof(NODE));
    if(!novo){
        printf("Sem memória");
        exit(1);
    }
    printf("Digite um valor: ");
    scanf("%d", &novo->valor);
    
    novo->proximo = NULL;
    if(vazia(linked_list)){
        linked_list->proximo = novo;
    }
    else{
        NODE *tmp = linked_list->proximo;
        while(tmp->proximo != NULL){
            tmp = tmp->proximo;
        }
        tmp->proximo = novo;
    }
}

void opcao(NODE *linked_list, int op){
    switch (op)
    {
    case 0:
        libera(linked_list);
        break;
    case 1:
        exibe(linked_list);
        break;
    case 2:
      insere_inicio(linked_list);
      break;
    case 3:
      insere_fim(linked_list);
      break;
    case 4:
       inicia(linked_list);
    default:
       printf("Comando inválido");
        break;
    }
}

int menu(){
    int opc;
    printf("\n\nEscolha a opcao: \n\n");
    printf("[0]- Libera\n");
    printf("[1]- Exibe\n");
    printf("[2]- insere um elemento no inicio\n");
    printf("[3]- insere um elemento no final\n");
    printf("[4]- Zera a lista\n");
    
    printf("Opcao escolhida: ");
    scanf("%d", &opc);

    return opc;
}

int main(void){
  
  NODE *linked_list=(NODE*)malloc(sizeof(NODE));
     if(!linked_list){
        printf("Sem memória");
        exit(1);
     }
     inicia(linked_list);
     int opt;
     do{
        opt = menu();
        opcao(linked_list, opt);

     } while(opt);
    
    free(linked_list);


    return 0;
}