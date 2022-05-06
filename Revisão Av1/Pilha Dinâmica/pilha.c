#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct elemento{
	struct aluno dados;
	struct elemento *prox;
};

typedef struct elemento Elem;

Pilha* criar(){
	Pilha* pi;
	pi=(Pilha*)malloc(sizeof(Pilha));
	if(pi==NULL) return 0;
	*pi=NULL;
	return pi;
}

void destruir(Pilha *pi){
	if(pi!=NULL){
		Elem *aux;
		while(*pi!=NULL){
			aux=*pi;
			*pi=(*pi)->prox;
			free(aux);
		}
		free(pi);
	}
}

int cheia(Pilha *pi){
	return 0;
}
int tamanho(Pilha* pi){
	if(pi==NULL) return 0;
	if(*pi==NULL) return 0;
	int cont=0;
	Elem *no;
	no=*pi;
	while(no!=NULL){
		cont++;
		no=no->prox;
	}
	return cont;
}

int vazia(Pilha *pi){
	if(pi==NULL) return 1;
	if(*pi==NULL) return 1;
	return 0;
}

int imprimir(Pilha *pi){
	if(pi==NULL) return 0;
	if(*pi==NULL) return 0;
	Elem *aux;
	aux=*pi;
	while(aux!=NULL){
		printf("(%d|%s)",aux->dados.matricula,aux->dados.nome);
		aux=aux->prox;
	}
}

int inserir(Pilha *pi,struct aluno al){
	if(pi==NULL) return 0;
	Elem *no;
	no=(Elem*)malloc(sizeof(Elem));
	if(no==NULL) return 0;
	no->dados=al;
	no->prox=(*pi);
	*pi=no;
	return 1;
}

int remover(Pilha *pi){
	if(pi==NULL) return 0;
	Elem *aux;
	aux=*pi;
	*pi=aux->prox;
	free(aux);
	return 1;
}

int acessar(Pilha *pi, struct aluno *al){
	if(pi==NULL) return 0;
	if(*pi==NULL) return 0;
	*al=(*pi)->dados;
	return 1;
}