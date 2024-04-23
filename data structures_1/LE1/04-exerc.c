#include <stdio.h>
#include <stdlib.h>

typedef struct id{
    int id_aluno;
    float cr;
} ID;

typedef struct node{  // definindo um nó
    ID *informacoes_aluno;
    struct node *link;
} NODE;


 void clearScreen() { // funcao para limpar o terminal
    system("clear"); 
 }

NODE *criacao_no(ID *info_aluno){ // funcao que cria o nó em memoria
    NODE *ptrnode;    // alocando os nós em memoria
    ptrnode = (NODE *)malloc(sizeof(NODE));
    ptrnode->informacoes_aluno = info_aluno;
    ptrnode->link = NULL;  // se o link aponta pra NULL, é o final da lista
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



int main(void){
  int contador = 1, x= 0, id;
  float cr;
  ID *nova_informacao;
  ID *atual_informacao;
  NODE *no;

  while (x < 5){
    
    printf("\nDigite o ID do %d aluno: ", contador);
    scanf("%d", &id);
    printf("Digite o CR do %d aluno: ", contador);
    scanf("%f", &cr);
     
     // ALUNO 1
    nova_informacao = (ID *)malloc(sizeof(ID));
    nova_informacao->id_aluno = id;
    nova_informacao->cr = cr;

    no = criacao_no(nova_informacao);  //OBS: struct já é um endereco de memoria, por isso nao precisa do *
    atual_informacao = no->informacoes_aluno;
        
    
        // ALUNO 2
    contador += 1;
    clearScreen();

    printf("Digite o ID do %d aluno: ", contador);
    scanf("%d", &id);
    printf("Digite o CR do %d aluno: ", contador);
    scanf("%f", &cr);

    nova_informacao = (ID *)malloc(sizeof(ID));
    nova_informacao->id_aluno = id;
    nova_informacao->cr = cr;


    no->link = criacao_no(nova_informacao); // criando outro nó no link do anterior;
    atual_informacao = no->link->informacoes_aluno;
    
    clearScreen();
    float cr_1 = no->informacoes_aluno->cr, cr_2 = no->link->informacoes_aluno->cr;
    int id_1 = no->informacoes_aluno->id_aluno, id_2 = no->link->informacoes_aluno->id_aluno;

    printf("****** INFORMAÇOES ******\n\n");
    printf("Informacoes do aluno %d: CR: %.2f e ID: %d\n", contador - 1,cr_1,id_1);
    printf("Informacoes do aluno %d: CR: %.2f e ID: %d\n", contador, cr_2,id_2);
    comparacao(cr_1,cr_2,contador);
    contador += 1;
    x += 1;
  }

    return 0;
}