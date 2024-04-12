#include <stdbool.h> 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void random_vector(int *vet, int size){
    srand(time(NULL)); 
    for(int i = 0; i < size; i++){
        vet[i] = rand()%100;
    }
}

void random(int *vet, int size){
    
    printf("******* VETOR ALEATORIO ********\n\n");
    
    for(int i = 0; i<size;i++){
        printf("| %d |\t", vet[i]);
    }
    printf("\n\n");
}

void bubble_sort(int *vet,int  size){
    bool change;
    int aux;
    while(true){
        for(int i=0; i < size - 1; i++){
            if (vet[i] > vet[i + 1]){
                 aux = vet[i];
                 vet[i] = vet[i + 1];
                 vet[i + 1]= aux;
                 change = true;
            }   
        if (!change){
            break;
        }    
        }
    }
}

void selection_sort(int *vet,int size){ 
    int x = 0,aux;
    while (x < size){
       int menor = x;
        for(int i=x+1; i<size; i++){
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

void insertion_sort(int *vet, int size){
    int aux,next;
    for (int i = 1; i<size; i++){
        while((next != 0) && (vet[next] < vet[next-1])){
            aux = vet[next];
            vet[next] = vet[next - 1];
            vet[next - 1] = aux;
            next -= 1;
        }
    }
}

void ordered_vector(int *vet, int size){
   
    printf("****** VETOR ORDENADO *******\n\n");
   
    for(int i = 0; i<size;i++){
        printf("| %d |\t", vet[i]);
    }
    printf("\n\n");
}

int main (void){
  int vector_size, *vector, option;
  clock_t time;
  
  printf("Enter the size of the vector: ");
  scanf("%d", &vector_size);

  vector = (int *)malloc(vector_size * sizeof(int));

  if (vector){
    while(true){
        printf("\n\n Choose one of the sorting algorithms: \n\n");
        printf("1- Bublle Sort");
        printf("2- Selection Sort");
        printf("3- Insertion Sort");
        printf("4- Exit");

        printf("\n\n Option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
        
        random_vector(vector,vector_size); 
        time = clock(); // tempo da chamada da ordenacao 
        bubble_sort(vector,vector_size);
        time = clock() - time;  // calculo final do tempo de execucao
        ordered_vector(vector,vector_size);

        printf("\n\n runtime %d",time);
            break;
        case 2:
            random_vector(vector,vector_size);
            time = clock();
            selection_sort(vector,vector_size);
            time = clock() - time;
            ordered_vector(vector,vector_size);

            printf("\n\n runtime %d",time);
            break;
        case 3:
            random_vector(vector,vector_size);
            time = clock();
            insertion_sort(vector,vector_size);
            time = clock - time;
            ordered_vector(vector,vector_size);

            printf("\n\n runtime %d",time);
            break;
        case 4:
          break;
        
        default:
        Printf("\nBYE!!!!");
            break;
        }
    }
  }
  free(vector);

 return 0;

}