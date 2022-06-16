struct aluno{
	int matricula;
};

typedef struct no *Arvore;

Arvore* criar();
void destruir(Arvore* ab);
int vazia(Arvore* ab);
void percorrer(Arvore* ab, int tipo);
int altura(Arvore* ab);
int qtd_nos(Arvore* ab);
int inserir(Arvore* ab, struct aluno novo);
int acessar(Arvore* ab, int x, struct aluno *a);