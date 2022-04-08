#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Ponto *p,*q;
	p=pto_cria(10,21);
	q=pto_cria(7,25);
	
	float d;
	d=pto_distancia(p,q);
	imprimir(p);
	imprimir(q);
	printf("Distancia entre dois pontos: %.2f \n",d);
	pto_libera(q);
	pto_libera(p);

	return 0;
}