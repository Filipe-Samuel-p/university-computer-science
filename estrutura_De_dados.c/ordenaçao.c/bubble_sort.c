#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int main(){
bool trocou;
int vet[10],temp;

    for(int i = 0; i < 10; i++){
    printf("Digite o numero da posicao %d: ", i);
    scanf("%d", &vet[i]);
    }

    printf("***** VETOR ALEATORIO *****\n");
    for(int i = 0; i < 10; i++){
        printf("%d\t", vet[i]);
    }
    while (true) {
        trocou = false; 
        for (int j = 0; j < 9; j++){
            if (vet[j] > vet[j + 1]){
                temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j+1]=temp;
                trocou = true;
            }
        }
        if (!trocou) {
            break;
        }
    }
    printf("\n***** LISTA ORGANIZADA *****\n");
    for( int i = 0; i < 10; i++){
    printf("%d\t", vet[i]);
    }

        return 0;
}
