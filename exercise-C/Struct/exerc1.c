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
 fgets(pess.nome,100,stdin);
 printf("Digite Sua idade: ");
 scanf("%d",&pess.idade);
 printf("Digite seu endereço: ");
 fgets(pess.endereco,100,stdin);

 


    return 0;
}