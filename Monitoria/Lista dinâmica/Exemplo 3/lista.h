struct aluno{
	int id;
	char nome[30];
};

typedef struct elemento *Lista;

Lista* criar();
void destruir(Lista *li);
int cheia(Lista *li);
int vazia(Lista *li);
int tamanho(Lista *li);
int imprimir(Lista *li);
int inserir_inicio(Lista *li,struct aluno al);
int remover_inicio(Lista *li);
int inserir_final(Lista *li,struct aluno al);
int remover_final(Lista *li);
int inserir_ordenado(Lista *li,struct aluno al);
int remover_valor(Lista *li, int x);