#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
struct pilha{
	int qtd;
	struct aluno dados[MAX];
};

Pilha* cria(){
	Pilha *pi;
	pi=(Pilha*)malloc(sizeof(Pilha));
	if(pi!=NULL){
		pi->qtd=0;
	}
	return pi;
}
void libera(Pilha *pi){
	free(pi);
}
int tamanho(Pilha *pi){
	if(pi==NULL){
		return -1;
	}else{
		return pi->qtd;
	}
	
}
int cheia(Pilha *pi){
	if(pi==NULL){
		return -1;
	}
	return (pi->qtd==MAX);
	//se pi==MAX dará resposta 1 e se for diferente dará resposta 0.

}
int vazia(Pilha *pi){
	if(pi==NULL){
		return -1;
	}
	return(pi->qtd==0);
}
int inserir(Pilha *pi,struct aluno al){
	if(pi==NULL){
		return 0;
	}
	if(cheia(pi)){
		return 0;
	}
	pi->dados[pi->qtd]=al;
	pi->qtd++;
	return 1;
}
int remover(Pilha *pi){
	if(pi==NULL||pi->qtd==0){
		return 0;
	}
	pi->qtd--;
}