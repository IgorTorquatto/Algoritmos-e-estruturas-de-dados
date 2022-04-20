#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"
struct elemento{
	struct aluno dados;
	struct elemento *prox;
};


typedef struct elemento Elem;

Lista* criar(){
	Lista* li;
	li=(Lista*)malloc(sizeof(Lista));
	*li=NULL;
	return li;
}
void liberar(Lista *li){
	//Como a função é void precisamos saber se a lista realmente existe, para ela existir é só ser diferente de NULL:
	if(li!=NULL){
	//Criamos um elemento no que vai nos ajudar a receber cada uma das posições da lista e liberá-las uma a uma:
		Elem* no;
	//Enquanto a cabeça da lista for diferente de NULL, ou seja , enquanto ainda houver elementos ( Porque o ultimo sempre aponta para NULL), vamos liberar cada posição:
		while(*li!=NULL){
	//O no recebe essa cabeça da lista:
			no=*li;
	//O elemento , que antes era a cabeça da lista, vai recebendo os dados da próxima posição:
			*li=(*li)->prox;
	//E vamos liberando esse no , até que seja o ultimo.
			free(no);
		}
	//Por fim liberamos a lista também:
		free(li);
	}
}

int tamanho(Lista *li){
	if(li==NULL){
		return 0;
	}
	Elem* no;
	no=*li;
	int cont;
	while(no!=NULL){
		cont++;
		no=no->prox;
	}
	return cont;
}
int cheia(Lista *li){
	//Lista dinâmica não existe o conceito de cheia.
	return 0;
}
int vazia(Lista *li){
	//Se a lista nem existe , ela está vazia:
	if(li==NULL){
		return 1;
	}
	//Se o primeiro elemento da lista( Cabeça) aponta pra NULL logo de cara, ela também está vazia:
	if(*li==NULL){
		return 1;
	}
	return 0;
}

int inserir_inicio(Lista *li,struct aluno al){
	if(li==NULL) return 0;
	//Criamos o elemento no:
	Elem *no;
	no=(Elem*)malloc(sizeof(Elem));
	//no dados receberá o parâmetro al da função.
	no->dados=al;
	//no agora vai aponta para o primeiro elemento da lista:
	no->prox=(*li);
	//a cabeça da lista agora vai apontar para no;
	*li=no;
	return 1;
	// *li cabeça da lista ; (*li) primeiro elemento da lista.
}
int inserir_final(Lista *li,struct aluno al){
	if(li==NULL){
		return 0;
	}
	Elem* no;
	no=(Elem*)malloc(sizeof(Elem));
	if(no==NULL){
		return 0;
	}
	no->dados=al;
	no->prox=NULL;
	if((*li)==NULL){ 
	//lista vazia insere no inicio:
		*li=no;
	}else{
		Elem *aux=*li;
		while(aux->prox!=NULL){
			aux=aux->prox;
		}
		aux->prox=no;
	}
	return 1;
}
int inserir_ordenado(Lista *li,struct aluno al){
	if(li==NULL){
		return 0;
	}
	Elem* no;
	no=(Elem*)malloc(sizeof(Elem));
	if(no==NULL){
		return 0;
	}
	no->dados=al;
	if(vazia(li)){
		no->prox=(*li);
		*li=no;
		return 1;
	}
	else{
		Elem *ant,*atual=*li;
		while(atual!=NULL && atual->dados.matricula<al.matricula){
			ant=atual;
			atual=atual->prox;
		}
		if(atual==*li){
			no->prox=(*li);
			*li=no;
		}else{
			no->prox=ant->prox;
			ant->prox=no;
		}
		
		return 1;
	}
}
void destruir(Lista *li) {
if (li != NULL) {
	Elem *aux;
	while (*li != NULL) {
	aux = *li;
	*li = (*li)->prox;
	free(aux);
	}
	
}
}
int removerInicio(Lista *li) {
	if (vazia(li)) {
	return 0;
	}
	else {
	Elem *aux = *li;
	*li = aux->prox;
	free(aux);
	return 1;
	}
}

int removerFim(Lista *li) {
	if (vazia(li)) {
	return 0;
	}
	else if ((*li)->prox == NULL){
	Elem  *aux = *li;
	*li = aux->prox;
	free(aux);
	return 1;
	}
	else {
	// Caminhando até o final da lista
}
}
int removerValor(Lista *li, int x) {
	if (vazia(li)) {
	return 0;
	}
	else if ((*li)->dados.matricula == x){
	Elem *aux = *li;
	*li = aux->prox;
	free(aux);
	return 1;
	}
	else {
	
	Elem *ant = *li;
	Elem *aux = ant->prox;
	while (aux != NULL && aux->dados.matricula != x) {
	ant = aux;
	aux = aux->prox;
	}
	if (aux == NULL) return 0;
	ant->prox = aux->prox;
	free(aux);
	return 1;
	
	}
}
int acessarIndice(Lista *li, int pos, struct aluno *a) {
	if (vazia(li))
	return 0;
	else if (pos < 0)
	return 0;
	else {
	int cont = 0;
	Elem *aux = *li;
	while (aux != NULL && pos != cont) {
	aux = aux->prox;
	cont++;
	}
	if (aux == NULL) return 0;
	*a = aux->dados;
	return 1;
	}
}
int acessarValor(Lista *li, int x, struct aluno *a) {
	if (vazia(li))
	return 0;
	else {
	Elem *aux = *li;
	while (aux != NULL && aux->dados.matricula != x) {
	aux = aux->prox;
	}
	if (aux == NULL) return 0;
	*a = aux->dados;
	return 1;
	}
}


