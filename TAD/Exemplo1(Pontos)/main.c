#include <stdio.h>
#include <stdlib.h>
#include "especificação.h"



int main(int argc, char *argv[]) {
	Ponto *z,*h;
	float p1x,p1y,p2x,p2y;
	printf("Digite as coordenadas do primeiro ponto: \n");
	scanf("%f",&p1x);
	scanf("%f",&p1y);
	printf("Digite as coordenadas do segundo ponto: \n");
	scanf("%f",&p2x);
	scanf("%f",&p2y);
	
	z=criar(p1x,p1y);
	h=criar(p2x,p2y);
	mostrar(z);
	printf("\n");
	mostrar(h);
	printf("\n");
	printf("%.2f",distancia(z,h));
	destruir(z);
    destruir(h);
	return 0;
}