#include <stdio.h>
#include <string.h>

struct Dados_Pessoa
{
    char nome[100];
    char endereco[50];
    int idade;

}pess;




int main (void){

 printf("Digite o seu nome: ");
 scanf("%s", pess.nome); // não precisa de & pois o argumento é um vetor e vetor é por si só um endereço
 printf("Digite Sua idade: ");
 scanf("%d",&pess.idade);
 printf("Digite seu endereço: ");
 scanf("%s", pess.endereco);

 


    return 0;
}