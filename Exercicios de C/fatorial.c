#include <stdio.h>

int fatorial (int n){
    int fat = 1;
    if (n == 0 || n == 1)
      return 1;
    else 
    {
        return fat = n * fatorial(n-1);
    }
    return fat;

}

int main(){
 int numero;
 printf("Digite o valor de um numero inteiro: \n");
 scanf("%d", &numero);
 printf("O valor do fatorial do numero %d e %d", numero,fatorial(numero));

    return 0;
}