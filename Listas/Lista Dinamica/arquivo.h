struct aluno{
	int matricula;
};

typedef struct elemento* Lista;

Lista* criar();
void liberar(Lista *li);
int tamanho(Lista *li);
int cheia(Lista *li);
int vazia(Lista *li);
int inserir_inicio(Lista *li,struct aluno al);
int inserir_final(Lista *li,struct aluno al);
int inserir_ordenado(Lista *li,struct aluno al);
void destruir(Lista *li); 
int removerInicio(Lista *li) ;
int removerFim(Lista *li);
int removerValor(Lista *li, int x);
int acessarIndice(Lista *li, int pos, struct aluno *a);
int acessarValor(Lista *li, int x, struct aluno *a);
