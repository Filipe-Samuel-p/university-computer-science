#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Agenda{
    char nome[100],email[100],telefone[20];
} AGENDA;

void clearScreen() { // funcao para limpar o terminal
    system("clear"); 
}

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

void mostrar_agenda(AGENDA agenda, int tamanho){
   
   for (int i = 0; i < tamanho;i++){
    printf("O %d elemento da agenda: \n\n", tamanho);
    printf("Nome: %s\n", agenda.nome);
    printf("Email: %s\n", agenda.email);
    printf("telefone: %s\n", agenda.telefone);
   }
}


int main(void){
 int numescolhas = 0, numero_de_elementos = 0,opcao;
 AGENDA *ptrAgenda;
 ptrAgenda = (AGENDA *)malloc(1 * sizeof(AGENDA));

 
 do {

      printf("***** ESCOLHA UMA DAS OPCOES ABAIXO: \n\n");
      printf("1- inclusao \n");
      printf("2- Alteracao \n");
      printf("3- Consulta \n");
      printf("4- Excluir\n");
      printf("5- Pesquisar \n");
      printf("6- Sair \n\n");
      printf("Opcao escolhida: ");
      scanf("%d", &opcao);


      switch (opcao)
      {
      case 1:
         alocacao_vetor(&ptrAgenda,numero_de_elementos);
         inclusao(&ptrAgenda[numero_de_elementos]);
         numero_de_elementos++;
         break;
      case 2:
         clearScreen();
         mostrar_agenda(*ptrAgenda,numero_de_elementos);
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
   } while (opcao != 6);


    return 0;
}