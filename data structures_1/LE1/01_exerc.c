#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Agenda{
    char nome[100],email[100],telefone[20];
} AGENDA;




int main(void){
 int numescolhas = 0;
 AGENDA *ptrAgenda;

 

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
    /* code */
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