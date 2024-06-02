#include <stdio.h>

int main(){
  int numero_de_linhas;
  char auxiliar;
  printf("Digite o numero de linhas: ");
  scanf("%d", &numero_de_linhas);
  for (int i = 1; i < numero_de_linhas + 1; i++){
    printf("\n");
    for(int j = 1; j < i + 1; j++){
      printf("!");
    }
  }

  return 0;
}