
#include <stdio.h>
#include <string.h>

//Criando a struct:
struct ficha_aluno{
    char nome[50];
    float nota;
};

int main()
{
    //Usando a struct numa variável "aluno":
    struct ficha_aluno aluno;
    //Atribuindo nota:
    aluno.nota=8.5;
    //Atribuindo o nome usando o strcpy():
    strcpy(aluno.nome, "Manoel");
    printf("Nota aluno : %f \n",aluno.nota);
    printf("Nome aluno: %s",aluno.nome);
    return 0;
}
