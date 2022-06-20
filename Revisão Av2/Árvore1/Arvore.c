#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

struct no{
	struct no *esq;
	struct aluno dados;
	struct no *dir;
};

typedef struct no No;

Arvore* criar(){
	Arvore *ab;
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
		printf("%d",x->dados.matricula);
		preordem(x->esq);
		preordem(x->dir);
	}
}

void emordem(No* x){
	if(x!=NULL){
		emordem(x->esq);
		printf("%d",x->dados.matricula);
		emordem(x->dir);
	}
}

void posordem(No* x){
	if(x!=NULL){
		posordem(x->esq);
		posordem(x->dir);
		printf("%d",x->dados.matricula);
	}
}

void percorrer(Arvore* ab, int tipo){
	if(vazia(ab)){
		printf("Arvore vazia");
	}
	else if(tipo==1){
		preordem(*ab);
	}
	else if(tipo==2){
		emordem(*ab);
	}
	else if(tipo==3){
		posordem(*ab);
	}
	else{
		printf("Percuso invalido");
	}
}

int contAltura(No* x){
	if(x==NULL) return 0;
	else{
		int esq= contAltura(x->esq);
		int dir= contAltura(x->dir);
		if(esq>dir) return esq+1;
		else return dir+1;
	}
}

int altura(Arvore* ab){
	if(vazia(ab)) return 0;
	else{
		return contAltura(*ab);
	}
}

int cont_nos(No* x){
	if(x==NULL) return 0;
	else{
		return cont_nos(x->esq) + cont_nos(x->dir) + 1;
	}
}

int qtd_nos(Arvore* ab){
	if(vazia(ab)) return 0;
	else{
		return cont_nos(*ab);
	}
}

int inserir(Arvore* ab, struct aluno novosdados){
	if(ab==NULL) return 0;
	No* novo;
	novo=(No*)malloc(sizeof(No));
	if(novo==NULL) return 0;
	novo->dados=novosdados;
	novo->esq=NULL;
	novo->dir=NULL;
	if(*ab==NULL){
		*ab=novo;
		//Inserir em arvore vazia;
	}
	else{
		No* aux;
		No* pai;
		aux=*ab;
		while(aux!=NULL){
			pai=aux;
			if(novosdados.matricula<pai->dados.matricula){
				aux=aux->esq;
			}
			else if(novosdados.matricula>pai->dados.matricula){
				aux=aux->dir;
			}
			else{
				free(novo);
				return 0;
			//já existe
			}
		}
		if(novosdados.matricula<pai->dados.matricula)
		pai->esq=novo;
		else
		pai->dir=novo;
	}
	return 1; //Para atender tanto o if quanto o else;
	
}

int acessar(Arvore* ab, int x, struct aluno *a){
	if(vazia(ab)) return 0;
	No* aux;
	aux=*ab;
	while(aux!=NULL){
		if(x<aux->dados.matricula){
			aux=aux->esq;
		}
		else if(x>aux->dados.matricula){
			aux=aux->dir;
		}
		else{
			//igual
			*a=aux->dados;
			return 1;
		}
	}
	return 0;
}