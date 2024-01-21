#include <stdio.h>

int fatorial (int n){
    int fat;
    fat = 1;
    while (n > 1) {   // em C é melhor usar while do que for
        fat *= n;
        n -= 1;
    }
    return fat;
}

int main(){
  int n;
  printf("Digite um valor: ");
  scanf("%d", &n);
  fatorial(n);
  printf("o valor do fatorial de %d é %d", n, fatorial(n));

    return 0;
}

