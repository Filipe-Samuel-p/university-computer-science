#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void vetor_aleatorio(int *vet, int number){
    srand(time(NULL)); 
    for(int i = 0; i < number; i++){
        vet[i] = rand()%100;
    }
}

void mostrar_vet_alea(int *vet, int number){
    
    printf("******* VETOR ALEATORIO ********\n\n");
    
    for(int i = 0; i<number;i++){
        printf("| %d |\t", vet[i]);
    }
    printf("\n\n");
}

void selection_sort(int *vet,int number){ 
    int x = 0,aux;
    while (x < number){
       int menor = x;
        for(int i=x+1; i<number; i++){
            if (vet[menor]>vet[i]){ 
                menor = i;  // o selection sort vai pelo indice
                            // pegando o indice do menor elemento
            }
        }
        if (x != menor){ // se o elemento tiver o mesmo indice, nao tem pq haver troca
            aux = vet[x];
            vet[x] = vet[menor];
            vet[menor] = aux;
        }
        x += 1;
    }
}

void mostrar_vet_ordenado(int *vet, int number){
   
    printf("****** VETOR ORDENADO *******\n\n");
   
    for(int i = 0; i<number;i++){
        printf("| %d |\t", vet[i]);
    }
    printf("\n\n");
}



int main(void){
  int *tamanho_vetor,n;

  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);

  tamanho_vetor = (int*)malloc(n * sizeof(int));
  if (tamanho_vetor){
     vetor_aleatorio(tamanho_vetor,n);
     mostrar_vet_alea(tamanho_vetor,n);
     selection_sort(tamanho_vetor,n);
     mostrar_vet_ordenado(tamanho_vetor,n);
  }
  free(tamanho_vetor);

    return 0;
}