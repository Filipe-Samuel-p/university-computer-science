// crie uma matriz 4x4 e diz quantos elementos maiores que dez existem

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maior_que_10(int mat[4][4]){
    int contador = 0;
    for (int i = 0;i < 4; i++){
        for(int j = 0; j< 4; j++){
            if (mat[i][j] > 10){
                contador += 1;
            }
        }
    }
    return contador;
}

int main(){
 int matriz[4][4], valores;

 srand(time(NULL));
 printf("***** MATRIZ ******\n\n");
 for (int i = 0;i < 4; i++){
    for(int j = 0; j< 4; j++){
        matriz[i][j] = rand()%20;
        printf("%d\t", matriz[i][j]);
        if (i == j){
            printf("\n");
        }
    }
 }

 valores = maior_que_10(matriz);
 printf("\n O numero de valores maiores que 10 e %d", valores);

return 0;
}
