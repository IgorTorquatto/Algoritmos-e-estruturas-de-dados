#include <stdio.h>

//Criando um struct usuario com id e nome:
struct usuario {
    int id;
    char nome[100];
};

struct usuario cadastrar () {
    struct usuario u;
    printf("Matricula: ");
    scanf("%d", &u.id);
    printf("Nome: ");
    scanf("%s", u.nome);
    printf("Cadastro efetuado!\n");
    return u;
}
//Função para imprimir a matricula e o n ome de cada usuário:
void imprimir (struct usuario u) {
    printf("[%d] %s\n", u.id, u.nome);
}

int main () {
    struct usuario alunosCCT[5];
    int i;
    for (i = 0 ; i < 5 ; i++) {
    alunosCCT[i] = cadastrar();
    }
    //Imprimir, usando a função void imprimir(), os dados dos alunos:
    for (i = 0 ; i < 5 ; i++) {
    imprimir(alunosCCT[i]);
    }
return 0;
}