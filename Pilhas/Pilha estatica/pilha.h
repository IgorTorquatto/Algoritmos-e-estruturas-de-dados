#define MAX 100
struct aluno{
	int matricula;
	char nome[30];
	float n1,n2,n3;
};
typedef struct pilha Pilha;

Pilha* cria();
void libera(Pilha *pi);
int tamanho(Pilha *pi);
int cheia(Pilha *pi);
int vazia(Pilha *pi);
int inserir(Pilha *pi,struct aluno al);
int remover(Pilha *pi);