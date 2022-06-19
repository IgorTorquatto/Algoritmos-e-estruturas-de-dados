typedef struct no *Arvore;

Arvore* criar();
void destruir(Arvore *ab);
int vazia(Arvore *ab);
int altura(Arvore *ab);
int qtd_nos(Arvore *ab);
int percorrer(Arvore *ab, int tipo);
int inserir(Arvore *ab,int x);
int acessar(Arvore *ab,int x,int *a);
