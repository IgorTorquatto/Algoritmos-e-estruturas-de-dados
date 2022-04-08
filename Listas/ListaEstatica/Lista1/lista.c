#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista{
	int qtd;
	int *valor;
};
Lista* criar(int tamanho){
	Lista *li;
	li=(Lista*)malloc(sizeof(Lista));
	if(li!=NULL){
		li->qtd=tamanho;
	}
	li->valor=(int*)malloc(sizeof(int));
	return li;
}

void preencher(Lista*li){
	int i;
	for(i=0;i<li->qtd;i++){
		printf("Digite o valor para a posiçao %d: ",i+1);
		scanf("%d",&li->valor[i]);
	}
}

int tamanho(Lista*li){
	if(li==NULL)
	return -1;
	else{
		printf("Tamanho: %d\n",li->qtd);
	}

}
void destruir(Lista*li){
	int i;
	for(i=0;i<li->qtd;li++){
		free(li->valor[i]);
	}
	free(li);
}
int cheia(Lista *li) {
	if (li == NULL)
	return -1;
	else if (li->qtd == MAX)
	return 1;
	else
	return 0;
}
int vazia(Lista *li) {
	if (li == NULL)
	return -1;
	else if (li->qtd == 0)
	return 1;
	else
	return 0;
}
void imprimir(Lista*li){
	int i;
	for(i=0;i<li->qtd;i++){
		printf("(%d) ",li->valor[i]);
	}
}
void inserir_fim(Lista*li,int y){

	if(cheia(li)){
		return 0;
	}
	else{
		//Como o qtd é o tamanho da lista, podemos usar sua posiçao li->qtd para nela colocar o li->valor=y que passaremos como parametro.
		//qtd é o ultimo espaço livre da lista, onde podemos colcoar nosso novo valor.
		li->valor[li->qtd]=y;
		//Aumentamos mais uma posiçao na lista:
		li->qtd++;
	}
}
void inserir_inicio(Lista*li,int y){
	if(li==NULL){
		return 0;
	}
	if(cheia(li)){
		return 0;
	}
	//A ideia é que cada elemento passe uma posição pra frente para que libere espaço n a posição 0.
	int i;
	//qtd é vazio já que o indice começa em 0, mas qtd-1 jpa tem algum valor.
	for(i=li->qtd-1;i>=0;i--){
		//A proxima posicão receberá o valor da posição atual.
		li->valor[i+1]=li->valor[i];
	}
	li->valor[0]=y;
	li->qtd++;
	return 1;
}
void remover_final(Lista*li){
	//A ideia é que o qtd seja reduzido (-1), assim o valor que estava no qtd inicial será perdido.
	if(li==NULL)
	return 0;
	if(li->qtd==0)
	return 0;
	li->qtd--;
	return 1;
}
void remover_inicio(Lista*li){

	//A ideia é que o li->valor da posição atual receba o li->valor da proxima posicao e o qtd final seja reduzido(-1), assim o primeiro l->valor seria perdido.
	if (li == NULL)
	return 0;
	else if (vazia(li))
	return 0;
	else {
	int i;
	for (i = 0 ; i < (li->qtd)-1 ; i++){
	li->valor[i] = li->valor[i+1];
	}
	li->qtd--;
	return 1;
}
}

