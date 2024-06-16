#include <stdio.h>
#include <stdlib.h>


int main(void){
 
 int tamanho_do_vetor = 3, *vetor;
 printf("Digite o quantos valores quer informar: ");
 scanf("%d", &tamanho_do_vetor);
 printf("\n\n");

 vetor = (int *)calloc(tamanho_do_vetor, sizeof(int));
 if(vetor){
    if (tamanho_do_vetor > 3){
        vetor = (int *)realloc(vetor, tamanho_do_vetor * sizeof(int));
        if (vetor){
            for (int i=0; i < tamanho_do_vetor;i++){
                printf("Digite o %d- valor: ", (i+1));
                scanf("%d", &vetor[i]);
            }
        }
    }
    else{
        for (int i=0; i < tamanho_do_vetor; i++){
            printf("Digite o %d- valor: ", (i+1));
            scanf("%d", &vetor[i]);
        }
    }
 }
 printf("\n\n");
 for(int i=0; i < tamanho_do_vetor;i++){
    printf("O %d- valor digitado foi %d\n", (i+1), vetor[i]);
 }
 free(vetor);
 
 
    return 0;
}