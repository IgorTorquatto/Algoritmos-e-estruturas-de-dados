struct aluno{
	char nome[30];
	int matricula;
};

typedef struct fila Fila;

Fila* criar();
void destruir(Fila *fi);
int tamanho(Fila *fi);
int cheia(Fila *fi);
int vazia(Fila *fi);
int inserir(Fila *fi,struct aluno al);
int remover(Fila *fi);