#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Agenda{
    char nome[100],email[100],telefone[20];
} AGENDA;

void alocacao_vetor(AGENDA **agenda, int numero_de_elementos){
    (*agenda) = (AGENDA *)realloc(*agenda,(numero_de_elementos + 1) * sizeof(AGENDA));
    if ((*agenda) == NULL){
      printf("ERRO DE ALOCACAO");
    }
}

void inclusao(AGENDA *agenda){
   printf("\n**** INCLUSAO ******\n\n");
   printf("Digite o nome: \n");
   fgets(agenda->nome,100,stdin);
   printf("\nDigite o email: ");
   fgets(agenda->email,100,stdin);
   printf("\nDigite o telefone: ");
   fgets(agenda->telefone, 20,stdin);
}



int main(void){
 int numescolhas = 0, numero_de_elementos = 0;
 AGENDA *ptrAgenda;
 ptrAgenda = (AGENDA *)malloc(1 * sizeof(AGENDA));

 

 printf("***** ESCOLHA UMA DAS OPCOES ABAIXO: \n\n");
 printf("1- inclusao \n");
 printf("2- Alteracao \n");
 printf("3- Consulta \n");
 printf("4- Excluir\n");
 printf("5- Pesquisar \n");
 printf("6- Sair \n\n");
 printf("Opcao escolhida: ");
 int opcao;
 scanf("%d", &opcao);

 switch (opcao)
 {
 case 1:
    alocacao_vetor(&ptrAgenda,numero_de_elementos);
    inclusao(&ptrAgenda[numero_de_elementos]);
    numero_de_elementos++;
    break;
 case 2:
    /* code */
    break;
 case 3:
    /* code */
    break;
 case 4:
    /* code */
    break;
 case 5:
    /* code */
    break;
 case 6:
    /* code */
    break;
 
 default:
   printf("Nenhuma das opcoes disponiveis foi escolhida");
    break;
 }



    return 0;
}