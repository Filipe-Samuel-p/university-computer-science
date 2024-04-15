
#include "teste.h"
#include <stdio.h>
#include <stdlib.h>
 

struct id{
    int id_aluno;
    float cr;
} ;

struct node{  // definindo um nó
    ID *informacoes_aluno;
    struct node *link;
};

NODE *criacao_no(ID *info_aluno){ // funcao que cria o nó em memoria
    NODE *ptrnode;    // alocando os nós em memoria
    ptrnode = (NODE *)malloc(sizeof(NODE));
    ptrnode->informacoes_aluno = info_aluno;
    ptrnode->link = NULL;  // se o link é aponta pra NULL, é o final da lista
    return ptrnode;

}

void comparacao(float cr1, float cr2, int contador){
    if(cr1 > cr2){
        printf("\n O aluno %d tem o maior CR: %.2f\n", contador - 1, cr1);
    }
    else if ( cr1 < cr2){
        printf("\n O aluno %d tem o maior CR: %.2f\n", contador, cr2);
    }
    else{
        printf("Ambos os alunos tem o mesmo CR\n");
    }
}