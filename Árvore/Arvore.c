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

void liberaNo(No *x) {
	if (x!= NULL) {
	liberaNo(x->esq);
	liberaNo(x->dir);
	free(x);
	x = NULL;
	}
}


void destruir(Arvore *ab) {
	if (ab != NULL) {
	liberaNo(*ab);
	free(ab);
	}
}

void preOrdem (No *x) {
	if (x != NULL) {
	printf("%d|%s|%.2f-> ",x->dados.matricula,x->dados.nome,x->dados.av);
	preOrdem(x->esq);
	preOrdem(x->dir);
	}
} 

void emOrdem (No *x) {
	if (x != NULL) {
	emOrdem(x->esq);
	printf("%d|%s|%.2f-> ",x->dados.matricula,x->dados.nome,x->dados.av);
	emOrdem(x->dir);
	}
} 

void posOrdem (No *x) {
	if (x != NULL) {
	posOrdem(x->esq);
	posOrdem(x->dir);
	printf("%d|%s|%.2f-> ",x->dados.matricula,x->dados.nome,x->dados.av);
	}
}

void percorrer (Arvore *ab, int tipo) {
	if (*ab==NULL||ab==NULL) {
	printf("Árvore Vazia!");
	}
	else if (tipo == 1)
	preOrdem(*ab);
	else if (tipo == 2)
	emOrdem(*ab);
	else if (tipo == 3)
	posOrdem(*ab);
	else {
	printf("Percurso inválido!");
	}
}

int contAltura(No *x) {
	if (x == NULL)
	return 0;
	else {
	int esq = contAltura(x->esq);
	int dir = contAltura(x->dir);
	return ((esq > dir) ? esq : dir) + 1;
	}
	}
	int altura (Arvore *ab) {
	if (*ab==NULL||ab==NULL)
	return 0;
	else {
	return contAltura(*ab);
	}
}

int contNos(No *x) {
	if (x == NULL)
	return 0;
	else
	return contNos(x->esq) + contNos(x->dir) + 1;
}


int quantidadeNos (Arvore *ab) {
	if (*ab==NULL||ab==NULL)
	return 0;
	else {
	return contNos(*ab);
	}
}

int inserir(Arvore *ab, struct aluno novosdados) {
	if (ab == NULL)
	return 0;
	No *novo = (No *)malloc(sizeof(No));
	if (novo == NULL) return 0;
	novo->dados = novosdados;
	novo->esq = NULL;
	novo->dir = NULL;
	if (*ab == NULL) {
	*ab = novo;
	}
	else {
	No *aux = *ab, *pai;
	while (aux != NULL) {
	pai = aux;
	if (novosdados.matricula < pai->dados.matricula)
	aux = aux->esq;
	else if (novosdados.matricula > pai->dados.matricula)
	aux = aux->dir;
	else {
	free(novo);
	return 0;
	}
	}
	if (novosdados.matricula < pai->dados.matricula)
	pai->esq = novo;
	else
	pai->dir = novo;
	
	}
	return 1;
}

int acessarValor(Arvore *ab, int x, struct aluno *a) {
	if (*ab==NULL||ab==NULL)
	return 0;
	No *aux = *ab;
	while (aux != NULL) {
	if (x < aux->dados.matricula)
	aux = aux->esq;
	else if (x > aux->dados.matricula)
	aux = aux->dir;
	else {
	*a = aux->dados;
	return 1;
	}
	}
	return 0;
}

int remover(Arvore *ab, int x) {
	if (*ab==NULL||ab==NULL)
	return 0;
	else {
	No *aux = *ab;
	No *pai = NULL;
	while (aux != NULL) {
	if (x < aux->dados.matricula) {
	pai = aux;
	aux = aux->esq;
	}
	else if (x > aux->dados.matricula) {
	pai = aux;
	aux = aux->dir;
	}
	else {
	if (aux->esq != NULL && aux->dir != NULL) {
	// Dois filhos
	No *paiMaior = aux;
	No *maior = aux->esq;
	while (maior->dir != NULL) {
	paiMaior = maior;
	maior = maior->dir;
	}
	if (paiMaior != aux) {
	paiMaior->dir = maior->esq;
	maior->esq = aux->esq;
	}
	maior->dir = aux->dir;
	if (pai == NULL)
	*ab = maior;
	else if (pai->esq == aux)
	pai->esq = maior;
	else
	pai->dir = maior;
	}
	else if (aux->esq == NULL && aux->dir == NULL) {
	// Nenhum filho
	if (pai == NULL)
	*ab = NULL;
	else {
	if (pai->esq == aux)
	pai->esq = NULL;
	else
	pai->dir = NULL;
	}
	}
	else {
	// Um filho
	if (pai == NULL) {
	if (aux->esq != NULL)
	*ab = aux->esq;
	else
	*ab = aux->dir;
	}
	else {
	if (pai->esq == aux)
	if (aux->esq != NULL)
	pai->esq = aux->esq;
	else
	pai->esq = aux->dir;
	else
	if (aux->esq != NULL)
	pai->dir = aux->esq;
	else
	pai->dir = aux->dir;
	}
	}
	free(aux);
	return 1;		
	}
	}
	return 0;
	}
}
