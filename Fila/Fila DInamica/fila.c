#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila{
	struct elemento *inicio;
	struct elemento *final;
};

struct elemento{
	struct aluno dados;
	struct elemento *prox;
};

typedef struct elemento Elem;

Fila * criar(){
	Fila* fi;
	fi=(Fila*)malloc(sizeof(Fila));
	fi->inicio=NULL;
	fi->final=NULL;
	return fi;
}

void libera (Fila *fi){
	if(fi!=NULL){
		Elem*  no;
		while(fi->inicio!=NULL){
			no=fi->inicio;
			fi->inicio=fi->inicio->prox;
			free(no);
		}
		free(fi);
	}
}

int tamanho (Fila *fi){
	if(fi==NULL){
		return 0;
	}
	Elem *no;
	int cont=0;
	
	no=fi->inicio;
	while(no!=NULL){
		cont++;
		no=no->prox;
	}
	return 1;
}

int vazia(Fila *fi){
	if(fi==NULL){
		return 1;
	}
	if(fi->inicio=NULL){
		return 1;
	}
	return 0;
}

int cheia(Fila *fi){
	return 0;
}

int inserir(Fila *fi,struct aluno al){
	//Tendo em vista que uma inserção em uma fila sempre acontece no final, o elemento que iremos inserir deve apontar para NULL, que , em arquivos dinamicos , é sempre o final.
	if(fi==NULL){
		return 0;
	}
	Elem *no;
	no=(Elem*)malloc(sizeof(Elem));
	no->dados=al;
	no->prox=NULL;
	if(fi->final=NULL){//Se isso acontecer é porque a fila era vazia. Tratamento para fila vazia:
	fi->inicio=no;
	}
	else{//Relamente inserindo no final:
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
	//Já que nao podemos remover de uma fila vazia.
	
	Elem *no;
	no=fi->inicio;
	fi->inicio=fi->inicio->prox;
	if(fi->inicio=NULL);
		fi->final=NULL;
	free(no);
	return 1;
	//O nome recebe o primeiro elemento e o elemento que estava no primeiro espaço recebe o proximo e assim por diante, ara que possamos dar um free(no) que era o primeiro elemento.
}