#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void criacao_vet_aleat (int *vet, int taman){
    srand(time(NULL));
    for (int i = 0; i < taman; i++){
        vet[i] = rand()%100;
    }
}   

void mostra_Vetor_ale(int *vet,int taman){
    for (int i = 0; i < taman; i++){
        printf("****** vetor aleatorio ******\n\n");
        printf("%d,\t", vet[i]);
    }
}

void selection_sort(int *vet,int taman){
  int x = 0, aux;
  while (x <= taman){
    for (int i = 0; i <  taman; i++){
        if (vet[x] > vet[i]){
            aux = vet[x];
            vet[i] = vet[i];
            vet[i] = aux;
         }
    }
    x += 1;
  }
}

void mostra_Vetor_org(int *vet,int taman){
    for (int i = 0; i < taman; i++){
        printf("****** vetor ordenado ******\n\n");
        printf("%d,\t", vet[i]);
    }
}


int main(void){
   int *tamanho_vetor,n;
   printf("Digite o tamanho do vetor: ");
   scanf("%d", &n);

   tamanho_vetor = malloc(n * sizeof(int));
   if(tamanho_vetor){
        int vetor_aleatorio[n];
        criacao_vet_aleat(vetor_aleatorio,n);
        mostra_Vetor_ale(vetor_aleatorio,n);
        selection_sort(vetor_aleatorio, n);
        mostra_Vetor_org(vetor_aleatorio,n);
   }
   
   free(tamanho_vetor);


    return 0;
}