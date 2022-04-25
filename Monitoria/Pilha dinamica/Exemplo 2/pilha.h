struct aluno{
	int matricula;
};

typedef struct elemento *Pilha;

Pilha* criar();
int cheia(Pilha *pi);
int vazia(Pilha *pi);
int inserir(Pilha *pi,struct aluno al);
int remover(Pilha*pi);
int tamanho(Pilha *pi);
int imprimir(Pilha *pi);
void liberar(Pilha *pi);
