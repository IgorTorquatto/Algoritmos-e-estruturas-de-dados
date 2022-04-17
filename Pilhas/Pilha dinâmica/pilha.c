#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
struct elemento{
	struct aluno dados;
	struct elemento *prox;
};
typedef struct elemento Elem;

Pilha* cria(){
	Pilha *pi;
	pi=(Pilha*)malloc(sizeof(Pilha));
	if(pi!=NULL){
		*pi=NULL;
	}
	return pi;
}
void libera(Pilha *pi){
	if(pi!=NULL){
		Elem* no;
		while((*pi)!=NULL){
			no=*pi;
			*pi=(*pi)->prox;
			free(no);
		}
		free(pi);
	}
}
int tamanho(Pilha *pi){
	if(pi==NULL){
		return 0;
	}
	int cont=0;
	Elem* no;
	//no é um struct elemento, logo tem dados e *prox.
	no=*pi;
	//*pi -> topo da pilha
	while(no!=NULL){
		cont++;
		no=no->prox;
	}
	return cont;
}
int cheia(Pilha *pi){
	return 0;
	//Não existe pilha cheia em pilha dinâmica.
}
int vazia(Pilha *pi){
	if(pi==NULL){
		return 1;
		//Isso que dizer que a pilha não existe, ou seja, houve erro na criação.
	}
	if(*pi==NULL){
		return 1;
		//Aqui , realmente , checa se o topo aponta para NULL e , por consequência, se a pilha está vazia ou não.
	}
	return 0;
}
int inserir(Pilha *pi, struct aluno al){
	if(pi==NULL){
		return 0;
	}
	//Criamos um struct elemento no e vamos alocar memória para ele:
	Elem* no;
	no=(Elem*)malloc(sizeof(Elem));
	if(no==NULL){
		//Verifica se deu erro ou não na alocação do elemento no.
		return 0;
	}
	no->dados=al;
	//Novo elemento aponta para o topo da pilha:
	no->prox=(*pi);
	//Topo da pilha vira agora esse novo elemento:
	*pi=no;
	return 1;
	//Lembrando: *pi é o topo generico da pilha, logo por isso ele deve apontar para no agora. (*pi) era o primeiro elemento que o topo,*pi, apontava inicialmente.
	//Portanto o no->prox agora é esse novo elemento que antes era o (*pi).
}
int remover(Pilha *pi){
	//Remoção sempre do seu inicio.
	if(pi==NULL){
		return 0;
	}
	if((*pi)==NULL){
		return 0;
	}
	//Criamos um elemento no que irá ser o topo da pilha, e o antigo topo da pilha agora será o próximo elemento(no->prox). Com isso removemos o no, que era o primeiro elemento.
	Elem *no;
	no=*pi;
	*pi=no->prox;
	free(no);
	return 1;
}
int consultar(Pilha *pi,struct aluno *al){
	//Consultas sempre feitas no topo.
	if(pi==NULL){
		return 0;
	}
	if((*pi)==NULL){
		return 0;
	}
	*al=(*pi)->dados;
	return 1;
}