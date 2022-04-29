#include <stdio.h>
#include <stdlib.h>
#include "pi.h"

struct elemento{
struct pessoa dados;
struct elemento *prox;
};

typedef struct elemento Elem;

Pi* criar(){
Pi* pi;
pi=(Pi*)malloc(sizeof(Pi));
if(pi!=NULL){
*pi=NULL;
}
return pi;
}

int cheia(Pi *pi){
return 0;
}

int vazia(Pi *pi){
if(pi==NULL)
return 1;
if(*pi==NULL){
return 1;
}
return 0;
}

int inserir(Pi *pi,struct pessoa pe){
if(pi==NULL){
return 0;
}
Elem *no;
no=(Elem*)malloc(sizeof(Elem));
no->dados=pe;
no->prox=(*pi);
*pi=no;
return 1;
}

void imprimir(Pi *pi){
if(pi!=NULL){
Elem *aux;
aux=*pi;
while(aux!=NULL){
printf("(%d| %s)",aux->dados.id,aux->dados.nome);
aux=aux->prox;
}
}
}

int tamanho(Pi *pi){
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

int remover(Pi*pi){
if(pi==NULL){
return 0;
}
if(*pi==NULL){
return 0;
}
Elem *aux;
aux=(*pi);
*pi=aux->prox;
free(aux);
return 1;

}