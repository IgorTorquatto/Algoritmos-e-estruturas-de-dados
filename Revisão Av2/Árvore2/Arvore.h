typedef struct no *Arvore;

Arvore* criar();
void destruir(Arvore* ab);
int vazia(Arvore* ab);
void percorrer(Arvore* ab, int tipo);
int altura(Arvore* ab);
int qtd_nos(Arvore* ab);
int inserir(Arvore* ab,int y);
