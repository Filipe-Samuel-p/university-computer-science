#include <stdio.h>
#include <stdlib.h> 



int main(void){
   
  int tamanho_do_vetor, *ptr;

 printf("Digite o tamanho do vetor: ");
 scanf("%d", &tamanho_do_vetor);
 
  int byte_necessario = tamanho_do_vetor * sizeof(int); // mostrando que vai retornar um inteiro
  ptr = malloc(byte_necessario); // vai retornar um endereço que tem uma memoria de tamanho "byte_tamanho" 
                                 // de maneira sequencial, lembrando um vetor
  
  printf("\n\n"); 

  for (int i = 0; i < tamanho_do_vetor; i++){
    printf("Digite o %d valor do vetor: ", (i + 1));
    scanf("%d", &ptr[i]);
  }
  printf("\n\n");

  for( int i = 0; i < tamanho_do_vetor; i++){
    printf("O %d valor do vetor é: %d\n", (i+1), ptr[i]);
  }
  free(ptr); // liberando o espaço alocado (reservado)
  




    return 0;
}