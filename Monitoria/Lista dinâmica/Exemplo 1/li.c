#include <stdio.h>
#include <stdlib.h>
#include "li.h"

struct elemento{
	struct pessoa dados;
	struct elemento *prox;
};

typedef struct elemento Elem;

Lista* criar(){
	Lista *li;
	li=(Lista *)malloc(sizeof(Lista));
	if(li!=NULL)
	*li=NULL;
	return li;
}

void liberar(Lista *li){
	if(li!=NULL){
		Elem *no;
		while((*li)!=NULL){
			no=(*li);
			*li=(*li)->prox;
			free(no);
		}
		free(li);
	}
}

int tamanho(Lista *li){
	if(li==NULL){
		return 0;
	}
	Elem *no;
	int cont=0;
	no=(*li);
	while(no!=NULL){
		cont++;
		no=no->prox;
	}
	return cont;
}

int vazia(Lista *li){
	if(li==NULL){
		return 1;
	}
	if(*li==NULL){
		return 1;
	}
	return 0;
}

int cheia(Lista *li){
	return 0;
}

int inserir_inicio(Lista *li,struct pessoa pe){
	if(li==NULL) return 0;
	Elem *no;
	no=(Elem*)malloc(sizeof(Elem));
	if(no==NULL) return 0;
		no->dados=pe;
		no->prox=(*li);
		*li=no;
	return 1;
}

int imprimir(Lista *li){
	if (li==NULL) return 0;
	if (vazia(li)) return 0;
	Elem *aux;
	aux=(*li);
	while(aux!=NULL){
		printf("( %d| %s| %s)",aux->dados.id,aux->dados.nome,aux->dados.emprego);
		aux=aux->prox;
	}
}

int inserir_final(Lista *li,struct pessoa pe){
	if(li==NULL) return 0;
	Elem *no;
	no=(Elem*)malloc(sizeof(Elem));
	no->dados=pe;
	no->prox=NULL;
	if((*li)==NULL){
		*li=no;
	}else{
		Elem *aux;
		aux=*li;
		while(aux->prox!=NULL){
			aux=aux->prox;
		}
		aux->prox=no;
	}
	return 1;
}