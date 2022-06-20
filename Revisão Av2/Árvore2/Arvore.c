#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

struct no {
	struct no *esq;
	int numero;
	struct no *dir;
};

typedef struct no No;

Arvore* criar(){
	Arvore* ab;
	ab=(Arvore*)malloc(sizeof(Arvore));
	if(ab!=NULL){
		*ab=NULL;
	}
	return ab;
}


void libera_no(No* x){
	if(x!=NULL){
		libera_no(x->esq);
		libera_no(x->dir);
		free(x);
		x=NULL;
	}
}

void destruir(Arvore* ab){
	if(ab!=NULL){
		libera_no(*ab);
		*ab=NULL;
		free(ab);
	}
}

int vazia(Arvore* ab){
	if(ab==NULL) return 1;
	if(*ab==NULL) return 1;
	return 0;
}

void preordem(No* x){
	if(x!=NULL){
		printf("%d",x->numero);
		preordem(x->esq);
		preordem(x->dir);
	}
}

void emordem(No* x){
	if(x!=NULL){
		emordem(x->esq);
		printf("%d",x->numero);
		emordem(x->dir);
	}
}

void posordem(No* x){
	if(x!=NULL){
		posordem(x->esq);
		posordem(x->dir);
		printf("%d",x->numero);
	}
}


void percorrer(Arvore* ab, int tipo){
	if(vazia(ab)){
		printf("Arvore vazia");
	}
	else{
		if(tipo==1){
			preordem(*ab);
		}
		else if(tipo==2){
			emordem(*ab);
		}
		else if(tipo==3){
			posordem(*ab);
		}
		else{
			printf("Caminho invalido.");
	}
	}
	
}

int cont_altura(No* x){
	if(x==NULL) return 0; //caso base
	else{
		int esq=cont_altura(x->esq);
		int dir=cont_altura(x->dir);
		if(esq>dir)
		return esq+1;
		else
		return dir+1;
	}
}

int altura(Arvore* ab){
	if(vazia(ab)) return 0;
	else{
		return cont_altura(*ab);
	}
}


int cont_nos(No* x){
	if(x==NULL) return 0;
	else{
		//retorna a soma +1 
		return cont_nos(x->esq)+ cont_nos(x->dir)+1;
	}
}

int qtd_nos(Arvore* ab){
	if(vazia(ab)) return 0;
	else{
		return cont_nos(*ab);
	}
}

int inserir(Arvore* ab,int y){
	if(ab==NULL) return 0;
	No* novo;
	novo=(No*)malloc(sizeof(No));
	if(novo==NULL) return 0;
	novo->numero=y;
	novo->esq=NULL;
	novo->dir=NULL;
	if(*ab==NULL){
		*ab=novo;
	}
	else{
		No* aux;
		No* pai;
		aux=*ab;
		while(aux!=NULL){
			pai=aux;
			if(y<pai->numero){
				//Se o que eu quero inserir for menor do que pai->numero
				aux=aux->esq;
			}
			else if(y>pai->numero){
				aux=aux->dir;
			}
			else{
				free(novo);
				return 0;
				//igual
			}
		}
		if(y<pai->numero){
			pai->esq=novo;
		}
		else{
			pai->dir=novo;
		}
	}
	return 1;
}