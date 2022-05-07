#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct elemento{
	struct aluno dados;
	struct elemento *prox;
};

struct fila{
	struct elemento *inicio;
	struct elemento *final;
};

typedef struct elemento Elem;

Fila* criar(){
	Fila *fi;
	fi=(Fila*)malloc(sizeof(Fila));
	if(fi==NULL) return 0;
	fi->inicio=NULL;
	fi->final=NULL;
	return fi;
}

void destruir(Fila *fi){
	if(fi!=NULL){
		Elem *aux;
		while(fi->inicio!=NULL){
			aux=fi->inicio;
			fi->inicio=fi->inicio->prox;
			free(aux);
		}
		free(fi);
	}
}

int tamanho(Fila *fi){
	if(fi==NULL) return 0;
	if(fi->inicio==NULL) return 0;
	int cont=0;
	Elem *aux;
	aux=fi->inicio;
	while(aux!=NULL){
		cont++;
		aux=aux->prox;
	}
	return cont;
}

int cheia(Fila *fi){
	return 0;
}

int vazia(Fila *fi){
	if(fi==NULL) return 1;
	if(fi->inicio==NULL) return 1;
	
	return 0;
}

int inserir(Fila *fi,struct aluno al){
	if(fi==NULL) return 0;
	Elem *no;
	no=(Elem*)malloc(sizeof(Elem));
	if(no==NULL) return 0;
	no->dados=al;
	no->prox=NULL;
	if(fi->final==NULL){
		fi->inicio=no;
	}
	else{
		fi->final->prox=no;
		fi->final=no;
	}
	return 1;
}

int remover(Fila *fi){
	if(fi==NULL)
	return 0;
	if(fi->inicio=NULL)
	return 0;
	
	Elem *no;
	no=fi->inicio;
	fi->inicio=fi->inicio->prox;
	if(fi->inicio=NULL);
		fi->final=NULL;
	free(no);
	return 1;
}