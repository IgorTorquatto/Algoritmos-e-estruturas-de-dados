struct pessoa{
int id;
char nome[30];
};

typedef struct elemento *Pi;

Pi* criar();
int cheia(Pi*);
int vazia(Pi*);
int inserir(Pi*,struct pessoa pe);
int tamanho(Pi*);
int remover(Pi*);
void destruir(Pi*);
void imprimir(Pi*);