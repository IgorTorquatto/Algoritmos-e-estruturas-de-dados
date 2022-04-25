struct aluno{
	int matricula;
	float n1;
};

typedef struct elemtento *Pilha;

Pilha* criar();
int vazia(Pilha* pi);
int cheia(Pilha* pi);
int inserir(Pilha* pi,struct aluno al);
int tamanho(Pilha *pi);
int remover(Pilha* pi);
int imprimir(Pilha *pi);

//int consultar(Pilha *pi,struct aluno *al);
//void liberar(Pilha* pi);