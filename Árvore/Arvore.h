struct aluno{
	int matricula;
	char nome[50];
	float av;
};

typedef struct no* Arvore;

Arvore* criar();
void destruir(Arvore* ab);
void percorrer (Arvore *ab, int tipo);
int quantidadeNos (Arvore *ab) ;
int inserir(Arvore *ab, struct aluno novosdados);
int acessarValor(Arvore *ab, int x, struct aluno *a);
int remover(Arvore *ab, int x);
