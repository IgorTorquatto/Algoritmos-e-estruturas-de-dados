#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"Portuguese");
	
	Arvore *ab;
	ab=criar();
	
	inserir(ab,8);
	inserir(ab,7);
	inserir(ab,9);
	inserir(ab,3);
	printf("Árvore: \n");
	imprimir(ab,1);
	printf("\nAltura: %d",altura(ab));
	printf("\nQuantidade de nós: %d",qtd_nos(ab));
	int a;
	acessar(ab,3,&a);
	printf("\nValor acessado: %d",a);
	destruir(ab);
	
	return 0;
}