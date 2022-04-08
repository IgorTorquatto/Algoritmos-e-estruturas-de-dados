#define MAX 50
typedef struct lista Lista;

Lista* criar(int);
void preencher(Lista*);
int tamanho(Lista*);
void destruir(Lista*li);
int cheia(Lista*li);
int vazia(Lista*li);
void imprimir(Lista*li);
void inserir_fim(Lista*li,int y);
void inserir_inicio(Lista*li,int y);
void remover_final(Lista*li);
void remover_inicio(Lista*li);