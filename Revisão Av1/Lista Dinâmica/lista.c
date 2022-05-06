#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct elemento{
	struct aluno dados;
	struct elemento *prox;
};

typedef struct elemento Elem;

Lista* criar (){
	Lista *li;
	li=(Lista*)malloc(sizeof(Lista));
	if(li==NULL) return 0;
	*li=NULL;
	return li;
}

void destruir(Lista *li){
	if(li!=NULL){
		Elem *aux;
		while(*li!=NULL){
			aux=*li;
			*li=(*li)->prox;
			free(aux);
		}
		free(li);
	}
}

int cheia(Lista* li){
	return 0;
}

int vazia(Lista* li){
	if(li==NULL) return 1;
	if(*li==NULL) return 1;
	return 0;
}

int tamanho(Lista *li){
	if(li==NULL) return 0;
	if(*li==NULL) return 0;
	int cont=0;
	Elem *aux;
	aux=*li;
	while(aux!=NULL){
		cont++;
		aux=aux->prox;
	}
	return cont;
}

int imprimir(Lista *li){
	if(li==NULL) return 0;
	if(*li==NULL) return 0;
	
	Elem *aux;
	aux=*li;
	
	while(aux!=NULL){
		printf("(%d | %s)",aux->dados.matricula,aux->dados.nome);
		aux=aux->prox;
	}
	return 1;
}

int inserir_inicio(Lista *li,struct aluno al){
	if(li==NULL) return 0;
	Elem *no;
	no=(Elem*)malloc(sizeof(Elem));
	if(no==NULL) return 0;
	no->dados=al;
	no->prox=(*li);
	*li=no;
	return 1;	
}

int inserir_final(Lista *li,struct aluno al){
	if(li==NULL) return 0;
	Elem *no;
	no=(Elem*)malloc(sizeof(Elem));
	if(no==NULL) return 0;
	no->dados=al;
	no->prox=NULL;
	
	if(*li==NULL){
		*li=no;
		return 1;
	}
	else{	
	Elem *aux;
	aux=*li;
	while(aux->prox!=NULL){
		aux=aux->prox;
	}
	aux->prox=no;
	return 1;	
	}
}

int inserir_ordenado(Lista *li,struct aluno al){
	if(li==NULL) return 0;
	Elem *no;
	no=(Elem*)malloc(sizeof(Elem));
	if(no==NULL) return 0;
	no->dados=al;
	
	if(*li==NULL){
		no->prox=(*li);
		*li=no;
		return 1;
	}
	else{
		Elem *ant,*atual;
		atual=*li;
		while(atual!=NULL && atual->dados.matricula < al.matricula){
			ant=atual;
			atual=atual->prox;
		}
		if(atual==(*li)){
			//Faz o inserir inicio:
			no->prox=(*li);
			*li=no;
		}else{
			no->prox=ant->prox;
			ant->prox=no;
			
		}
		return 1;
	}
}

int remover_inicio(Lista *li){
	if(li==NULL) return 0;
	if(*li==NULL) return 0;
	Elem *aux;
	aux=*li;
	*li=(*li)->prox;
	free(aux);
	return 1;
}

int remover_final(Lista *li){
	if(li==NULL) return 0;
	Elem *ant,*atual;
	atual=*li;
	while(atual->prox!=NULL){
		ant=atual;
		atual=atual->prox;
	}
	if(atual==*li){
		*li=atual->prox;	
	}
	else{
		ant->prox=atual->prox;
	}

	free(atual);
	return 1;
}

int remover_valor(Lista *li,int x){
	if(li==NULL) return 0;
	Elem *ant,*atual;
	atual=*li;
	while(atual!=NULL && atual->dados.matricula != x){
		ant=atual;
		atual=atual->prox;
	}
	if(atual==NULL) return 0;
	if(atual==*li){
		*li=atual->prox;
	}
	else{
		ant->prox=atual->prox;
	}
	free(atual);
	return 1;	
}