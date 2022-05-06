struct aluno{
	char nome[30];
	int matricula;
};

typedef struct elemento *Pilha;

Pilha* criar();
void destruir(Pilha *pi);
int tamanho(Pilha* pi);
int cheia(Pilha *pi);
int vazia(Pilha *pi);
int imprimir(Pilha *pi);
int inserir(Pilha *pi,struct aluno al);
int remover(Pilha *pi);
int acessar(Pilha *pi, struct aluno *al);

//Exercicios
int acessar_ultimo(Pilha *pi, struct aluno *al);