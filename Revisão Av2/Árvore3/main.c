#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Arvore* ab;
	ab=criar();
	
	inserir(ab,8);
	inserir(ab,7);
	inserir(ab,9);
	inserir(ab,3);
	
	printf("Arvore: ");
	percorrer(ab,1);
	printf("\nAltura: %d",altura(ab));
	printf("\nQtd nos: %d",qtd_nos(ab));
	int x;
	acessar(ab,7,&x);
	printf("\nValor acessado: %d",x);
	destruir(ab);
	return 0;
}