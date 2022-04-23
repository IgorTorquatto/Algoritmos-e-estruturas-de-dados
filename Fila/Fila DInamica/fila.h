struct aluno{
	int matricula;
	float n1,n2;
};

typedef struct fila Fila;

Fila* criar();
void libera (Fila *fi);
int tamanho (Fila *fi);
int vazia(Fila *fi);
int cheia(Fila *fi);
int inserir(Fila *fi,struct aluno al);
int remover(Fila *fi);