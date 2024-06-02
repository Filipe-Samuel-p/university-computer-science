#include <stdio.h>

struct Tipo_aluno {
    char nome[100], curso[100];
    int numero_de_matricula;

};

void cadastro_aluno(struct Tipo_aluno *x){
    
    printf("Digite o nome do aluno: ");
    fgets(x->curso,100,stdin); 
    printf("\nDigite o nome do curso do aluno: ");
    fgets(x->curso,100,stdin); 
    printf("Digite o numero da matrícula aluno: ");
    scanf("%d", &x->numero_de_matricula);

}

void dados_alunos(struct Tipo_aluno *y){
    printf("Nome do aluno: %s\n", y->nome);
    printf("Nome curso do aluno: %s\n", y->curso);
    printf("A matrícula do aluno: %d\n", y->numero_de_matricula);

}

int main(){
  
 struct Tipo_aluno vet[3], *aluno,aluno0,aluno1,aluno2;

 for (int i = 0; i < 3; i++){
    printf("\n\n");
    cadastro_aluno(&aluno[i]);
 }
 
 for ( int i = 0; i < 3; i++){

 printf("\n ****** ALUNO %d ****** \n\n", i);
 dados_alunos(&aluno[i]);


 }
 
    return 0;
}