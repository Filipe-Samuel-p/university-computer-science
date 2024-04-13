#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Agenda{
    char nome[100],email[100],telefone[20];
} AGENDA;

void clearScreen() { // funcao para limpar o terminal
    system("clear"); 
}

void alocacao_vetor(AGENDA **agenda, int *numero_de_elementos){
    (*agenda) = (AGENDA *)realloc(*agenda,(*numero_de_elementos + 1) * sizeof(AGENDA));
    if ((*agenda) == NULL){
      printf("ERRO DE ALOCACAO");
    }
}

void inclusao(AGENDA *agenda,int numero){

   printf("\n**** INCLUSAO ******\n");
   printf("Digite o nome: ");
   scanf("%s", agenda[numero].nome);
   printf("Digite o email: ");
   fgets(agenda[numero].email,100,stdin);
   if (fgets(agenda[numero].email,100,stdin) == NULL){
     printf("ERRO");
   }
   printf("Digite o telefone: ");
   fgets(agenda[numero].telefone, 20,stdin);
}

void consulta(AGENDA agenda, int tamanho){
   
   for (int i = 0; i < tamanho;i++){
    printf("\nO %d elemento da agenda: \n\n", tamanho);
    printf("Nome: %s\n", agenda.nome);
    printf("Email: %s\n", agenda.email);
    printf("telefone: %s\n", agenda.telefone);
   }
}

void alteracao(AGENDA *agenda,int tamanho){    
   char op,nome[100];
   int i;
  
   for(int i=0; i < tamanho && strncmp( agenda[i].nome,nome, strlen(nome))!=0;i++);
      if( i>= tamanho){
        printf("registro não encontrado");
      }
      else{
         printf("\n\tRegistro %d", i);
         printf("\n\tNome : %s", agenda[i].nome );
         printf("\n\tEmail : %s", agenda[i].email );
         printf("\n\tFone : %s", agenda[i].telefone );
         printf("\n\tConirma a alteracao ?");
         scanf("%c", &op);
         if (op == "S"  || op == "s"){
            printf("Digite o novo nome: ");
            fgets(agenda[i].nome,100,stdin);
            printf("\nDigite o novo email: ");
            fgets(agenda[i].email,100,stdin);
            printf("\nDigite o novo telefone: ");
            fgets(agenda[i].telefone,20,stdin);
         }
      }
}


int main(void){
 int numescolhas = 0, numero_de_elementos = 0,opcao;
 AGENDA *ptrAgenda;
 ptrAgenda = (AGENDA *)malloc(1 * sizeof(AGENDA));

 
 do {

      printf("\n***** ESCOLHA UMA DAS OPCOES ABAIXO: \n\n");
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
         alocacao_vetor(&ptrAgenda,&numero_de_elementos);
         inclusao(ptrAgenda,numero_de_elementos);
         numero_de_elementos++;
         break;
      case 2:
         clearScreen();
         alteracao(ptrAgenda,numero_de_elementos);
         break;
      case 3:
         consulta(*ptrAgenda,numero_de_elementos);
         break;
      case 4:
         /* code */
         break;
      case 5:
         consulta(*ptrAgenda, numero_de_elementos);
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