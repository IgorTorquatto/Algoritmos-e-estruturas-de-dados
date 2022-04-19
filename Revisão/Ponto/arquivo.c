#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"
#include <math.h>

struct ponto{
	int x;
	int y;
};

Ponto* criar(int a, int b){
	Ponto* po;
	po=(Ponto*)malloc(sizeof(Ponto));
	po->x=a;
	po->y=b;
	return po;
}

void imprimir(Ponto *po){
	printf("(%d,%d) \n",po->x,po->y);
}
int inserir_novo(Ponto *po, int k,int j){
	if(po==NULL){
		return 0;
	}
	po->x=k;
	po->y=j;
}

void destruir(Ponto *po){
	free(po);
}

int ponto_escrito(Ponto *po){
	if(po!=NULL){
		if(po->x &&po->y!=NULL){
			return 1;
		}
	}
	return 0;
}
int ponto_vazio(Ponto *po){
	if(po!=NULL){
		if(po->x && po->y==NULL){
			return 1;
		}
	}
	return 0;
}
float distancia(Ponto *po,Ponto *po_2){
	int primeiro,segundo;
	primeiro=(po_2->x - po->x) * (po_2->x - po->x);
	segundo=(po_2->y - po->y) * (po_2->y - po->y);
	
	return sqrt(primeiro+segundo);

}