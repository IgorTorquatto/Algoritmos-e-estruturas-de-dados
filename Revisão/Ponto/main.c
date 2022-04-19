#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Ponto* po;
	po=criar(2,3);
	imprimir(po);
	inserir_novo(po,1,1);
	imprimir(po);
	printf("%d \n",ponto_escrito(po));
	Ponto* po_2;
	po_2=criar(1,4);
	printf("Distancia: %.2f",distancia(po,po_2));
		
	return 0;
}