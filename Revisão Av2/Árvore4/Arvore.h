typedef struct no *Arvore;


Arvore* criar();
int inserir(Arvore *ab,int valor);
void imprimir(Arvore *ab,int tipo);
int altura(Arvore *ab);
int qtd_nos(Arvore *ab);
int acessar(Arvore *ab,int x,int *a);
void destruir(Arvore *ab);