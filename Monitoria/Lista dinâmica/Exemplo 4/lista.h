struct pessoa{
int id;
char nome[30];
char emprego[40];
};

typedef struct elemento *Lista;


Lista* criar();
void destruir(Lista *li);
int cheia(Lista *li);
int vazia(Lista *li);
int tamanho(Lista *li);
int imprimir(Lista *li);
int inserir_inicio(Lista *li,struct pessoa pe);
int inserir_final(Lista *li,struct pessoa pe);
int remover_inicio(Lista *li);
int remover_final(Lista *li);
int inserir_ordenado(Lista *li,struct pessoa pe);
int remover_valor(Lista* li, int x);