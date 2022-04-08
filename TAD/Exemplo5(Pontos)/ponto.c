#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include <math.h>

struct ponto{
	float x;
	float y;	
};

Ponto* pto_cria(float x,float y){
	Ponto *p;
	p=(Ponto*)malloc(sizeof(Ponto));
	if(p!=NULL){
		p->x=x;
		p->y=y;
	}
	return p;
}
void pto_libera(Ponto *p){
	free(p);
}
void pto_acessa(Ponto *p,float *x,float *y){
	//Não consiguimos ter dois returns em uma função por isso precisamos do ponteiro para acessar pos valores de um ponto.
	//colocamos dentro dos ponteiros x e y os dados que estavam dentro da struct p nos campos x e y da struct.
	*x=p->x;
	*y=p->y;
}
void pto_atribui(Ponto *p,float x, float y){
	p->x=x;
	p->y=y;
}
float pto_distancia(Ponto *p1,Ponto *p2){
	float dx,dy;
	dx=p1->x - p2->x;
	dy=p1->y - p2->y;
	return sqrt(dx*dx+dy*dy);
}
void imprimir(Ponto*p){
	printf("(%.2f,%.2f) \n",p->x,p->y);
}