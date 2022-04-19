typedef struct ponto Ponto;

Ponto* criar(int a, int b);
void imprimir(Ponto *po);
int inserir_novo(Ponto *po, int k,int j);
void destruir(Ponto* po);
int ponto_escrito(Ponto *po);
int ponto_vazio(Ponto *po);
float distancia(Ponto *po,Ponto *po_2);