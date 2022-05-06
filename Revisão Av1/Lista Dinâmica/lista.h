struct aluno {
	int matricula;
	char nome[30];
};

typedef struct elemento *Lista;

//Gerais:
Lista* criar ();
void destruir(Lista *li);
int cheia(Lista* li);
int vazia(Lista* li);
int tamanho(Lista *li);
int imprimir(Lista *li);

//Inserir:
int inserir_inicio(Lista *li,struct aluno al);
int inserir_final(Lista *li,struct aluno al);
int inserir_ordenado(Lista *li,struct aluno al);

//Remover:
int remover_inicio(Lista *li);
int remover_final(Lista *li);
int remover_valor(Lista *li,int x);