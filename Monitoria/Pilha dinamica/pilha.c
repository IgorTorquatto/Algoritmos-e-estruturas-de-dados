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

int cheia(Pilha* pi){
	return 0;
}

int vazia(Pilha* pi){
	if(pi==NULL){
		return 1;
	}
	if(*pi==NULL){
		return 1;
	}
	return 0;
}

int inserir(Pilha* pi,struct aluno al){
	if(pi==NULL){
		return 0;
	}
	Elem *no;
	no=(Elem*)malloc(sizeof(Elem));
	no->dados=al;

	no->prox=(*pi);
	*pi=no;
	
	return 1;
}

int tamanho(Pilha* pi){
	if(pi==NULL){
		return 0;
	}
	Elem* aux;
	aux=*pi;
	int cont=0;
	while(aux!=NULL){
		cont++;
		aux=aux->prox;
	}
	return cont;
}

/*void liberar(Pilha *pi){
	
	if(pi!=NULL){
		Elem* aux;
		while(*pi!=NULL){
			aux=*pi;
			*pi=(*pi)->prox;
			free(aux);
		}
		free(pi);
	}
	
}
*/

int remover(Pilha* pi){
	if(pi==NULL){
		return 0;
	}
	if(*pi==NULL){
		return 0;
		//Porque nao tem como remover em uma pilha vazia.
	}
	
	Elem *no;
	no=(*pi);
	*pi=no->prox;
	free(no);
	return 1;
}
int imprimir(Pilha *pi){
	if(pi==NULL)
	return 0;
	if(*pi==NULL)
	return 0;
	Elem *aux;
	aux=*pi;
	while(aux!=NULL){
		printf("(%d | %.2f)",aux->dados.matricula,aux->dados.n1);
		aux=aux->prox;
	}
	return 1;
}

/*int consultar(Pilha *pi,struct aluno *al){
	if(pi==NULL){
		return 0;
	}
	if((*pi)==NULL){
		return 0;
	}
	*al=(*pi)->dados;
	return 1;
}
*/
