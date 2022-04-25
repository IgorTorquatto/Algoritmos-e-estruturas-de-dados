#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct elemento{
	struct aluno dados;
	struct elemento *prox;
};

typedef struct elemento Elem;

Pilha* criar(){
	Pilha *pi;
	pi=(Pilha*)malloc(sizeof(Pilha));
	if(pi!=NULL){
		*pi=NULL;
	}
	return pi;
}

int cheia(Pilha *pi){
	return 0;
}
int vazia(Pilha *pi){
	if(pi==NULL)
	return 1;
	if(*pi==NULL)
	return 1;
	
	return 0;
}

int inserir(Pilha *pi,struct aluno al){
	if(pi==NULL)
	return 0;
	Elem *no;
	no=(Elem*)malloc(sizeof(Elem));
	if(no!=NULL){
		no->dados=al;
		no->prox=(*pi);
		*pi=no;
	}
	return 1;
}

int remover(Pilha*pi){
	if(pi==NULL)
	return 0;
	if(*pi==NULL)
	return 0;
	Elem *no;
	no=(*pi);
	*pi=no->prox;
	free(no);
	return 1;
}
int tamanho(Pilha *pi){
	if(pi==NULL){
		return 0;
	}
	if(*pi==NULL){
		return 0;
	}
	int cont=0;
	Elem *aux;
	aux=*pi;
	while(aux!=NULL){
		cont++;
		aux=aux->prox;
	}
	return cont;
}

int imprimir(Pilha *pi){
	
	if(pi==NULL){
		return 0;
	}
	if(*pi==NULL){
		return 0;
	}
	Elem *aux;
	aux=*pi;
	while(aux!=NULL){
		printf("(%d)",aux->dados);
		aux=aux->prox;
	}
	return 1;
}

void liberar(Pilha *pi){
	if(pi!=NULL){
	Elem *aux;
	while(*pi!=NULL){
		aux=*pi;
		*pi=(*pi)->prox;
		free(aux);
	}
}
}