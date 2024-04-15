#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct locadora{
   char nome_filme[50], genero[15];
   int ano_lanca;
} Filme;




int main(void){
  Filme *locadora;
  int num_entradas = 0,opcao;

  locadora = (Filme*)malloc(sizeof(Filme)); // alocando para a posição 0 do vetor
  if (locadora == NULL){
   printf("Erro de alocacao");
   exit(1);  // funcao encerra o programa !!!
  }
  
  do {
    
    printf("****** Bem vindo a sua locadora de filmes ******\n\n");
    printf("[1]- Incluir filme na locadora\n");
    printf("[2]- Alterar filme na locadora\n");
    printf("[3]- Consultar filme na locadora\n");
    printf("[4]- Pesquisar se um filme tem na locadora \n");
    printf("[5]- Alugar (Excluir) um filme na locadora\n");
    printf("[6]- SAIR\n\n");
    printf("Diga a opcao escolhida: ");
    scanf("%d", &opcao);
    getchar(); // funcao que le uma entrada no teclado e retorna essa entrada como tipo int



  } while(opcao != 6);






   return 0;
}