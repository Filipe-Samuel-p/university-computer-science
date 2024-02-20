#include <stdio.h>



int main(){
 int a,b,maior_valor;
 int *p1,*p2;
 printf("Digite o valor de a: \n");
 scanf("%d", &a);
 printf("\nDigite o valor de b: ");
 scanf("%d", &b);
 p1 = &a;
 p2 = &b;

 maior_valor = (p1 > p2) ? a : b;  // operação ternária em C
 printf("%d", maior_valor);
 



    return 0;
}