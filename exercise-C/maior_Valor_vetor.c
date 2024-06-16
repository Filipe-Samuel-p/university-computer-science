#include <stdio.h>
#include <stdlib.h>
#include <time.h> // lib que tem a funcao time


int definindo_maior_valor(int *vet){
    int auxiliar = 0;
    for (int i = 0; i < 10; i++){
       if (vet[i] > auxiliar){
         auxiliar = vet[i];
        }
    }
    return auxiliar;
}


int main(){

srand(time(NULL)); 
int vetor[10],maior_valor;
printf("****** VETOR ******\n");
for (int i = 0; i < 10; i++){
    vetor[i] = rand()%100; // gerando numeros aleatorios
    printf("%d\t", vetor[i]);
}
maior_valor = definindo_maior_valor(vetor); // nao precisa usar " & ", pois o vetor em si, já é um endereço
printf("\n o maior valor do vetor e %d", maior_valor);



    return 0;
}