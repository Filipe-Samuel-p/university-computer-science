#include <stdio.h>
#include <stdlib.h>


typedef struct aluno{
    int id_aluno;
    float cr;
} ALUNO;

typedef struct node{  // definindo um nó
    ALUNO *informacoes_aluno;
    struct node *link;
} NODE;


int vazia(NODE *linked_list){ // Uma funcao que verifica se a lista esta vazia ou nao. 
    if (linked_list->link == NULL){ 
        return 1;
    }
    else{
        return 0;
    }
}

void inicia (NODE *linked_list){
    linked_list->link = NULL;
}


void insere_elemento(NODE *linked_list){
    NODE *novo = (NODE *)malloc(sizeof(NODE));
    if(!novo){
        printf("Sem memória");
        exit(1);
    }
  
    printf("Digite o ID: ");
    scanf("%d", &novo->informacoes_aluno->id_aluno);
    printf("\nDigite o cr: ");
    scanf("%f", &novo->informacoes_aluno->cr);
    
    
    novo->link= NULL;
    if(vazia(linked_list)){
        linked_list->link= novo;
    }
    else{
        NODE *tmp = linked_list->link;
        while(tmp->link != NULL){
            tmp = tmp->link;
        }
        tmp->link= novo;
    }
}


void exibe(NODE *linked_lis){
    if(vazia(linked_lis)){
        printf("A lista esta vazia");
        return;
    }
    else{
        NODE *tmp;
        tmp = linked_lis->link;

        while(tmp != NULL){
            printf("ID aluno: %d ", tmp->informacoes_aluno->id_aluno);
            printf("CR aluno: %f ", tmp->informacoes_aluno->cr);
            tmp = tmp->link;
        }
    }
    printf("\n\n");
}


int main(void){
  
  NODE *linked_list=(NODE*)malloc(sizeof(NODE));
     if(!linked_list){
        printf("Sem memória");
        exit(1);
     }
     inicia(linked_list);
     int x = 0;
     int opcao;
     do{
        printf("\n\n***** Escolha uma opcao: \n\n");
        printf("[1]- Inserir dados de um aluno \n");
        printf("[2]- exibir lista \n");
        printf("Indique a opcao ->: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            insere_elemento(linked_list);
            break;
        case 2:
            exibe(linked_list);
            break;
        default:
            break;
        }
        x += 1;

     } while(x<10);
    
    free(linked_list);
 

    return 0;
}
