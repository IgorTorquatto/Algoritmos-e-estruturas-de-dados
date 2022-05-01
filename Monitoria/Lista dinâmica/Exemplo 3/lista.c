#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct elemento{
	struct aluno dados;
	struct elemento *prox;
};

typedef struct elemento Elem;

Lista* criar(){
	Lista *li;
	li=(Lista*)malloc(sizeof(Lista));
	if(li==NULL) return 0;
	*li=NULL;
	return li;
}

void destruir(Lista *li){
	if(li!=NULL){
		Elem *aux;
	while((*li)!=NULL){
		aux=(*li);
		*li=(*li)->prox;
		free(aux);
	}
	free(li);	
	}
}

int cheia(Lista *li){
	return 0;
}

int vazia(Lista *li){
	if(li==NULL) return 1;
	if(*li==NULL) return 1;
	return 0;
}

int tamanho(Lista *li){
	if(li==NULL) return 0;
	if(*li==NULL) return 0;
	
	Elem *aux;
	aux=(*li);
	int cont=0;
	
	while(aux!=NULL){
		cont++;
		aux=aux->prox;
	}
	return cont;
}

int imprimir(Lista *li){
	if(li==NULL) return 0;
	if(vazia(li)) return 0;
	
	Elem *aux;
	aux=(*li);
	
	while(aux!=NULL){
		printf("(%d | %s )",aux->dados.id,aux->dados.nome);
		aux=aux->prox;
	}
	return 1;
}

int inserir_inicio(Lista *li,struct aluno al){
	if(li==NULL) return 0;
	Elem *no;
	no=(Elem*)malloc(sizeof(Elem));
	if(no==NULL) return 0;
	no->dados=al;
	no->prox=(*li);
	*li=no;
	return 1;
}

int remover_inicio(Lista *li){
	if(li==NULL) return 0;
	if(*li==NULL) return 0;
	Elem *aux;
	aux=(*li);
	*li=(*li)->prox;
	free(aux);
	return 1;
}

int inserir_final(Lista *li,struct aluno al){
	if(li==NULL) return 0;
	Elem *no;
	no=(Elem*)malloc(sizeof(Elem));
	if(no==NULL) return 0;
	no->dados=al;
	no->prox=NULL;
	
	Elem *aux;
	aux=(*li);
	
	if((*li)==NULL){
		//Se a lista estiver vazia, a cabeça da lista já pode apontar para no porque no já aponta para NULL.
		*li=no;
	}else{
		while(aux->prox!=NULL){
		aux=aux->prox;
	}
	}
	aux->prox=no;
	return 1;
}

int remover_final(Lista *li){
	if(li==NULL) return 0;
	if(*li==NULL) return 0;
	
	Elem *atual,*ant;
	atual=(*li);
	while(atual->prox!=NULL){
		ant=atual;
		atual=atual->prox;
	}
	ant->prox=NULL;
	free(atual);
	return 1;
}