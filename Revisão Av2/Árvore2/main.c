#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

int main(int argc, char *argv[]) {
	Arvore *ab;
	ab=criar();
	
	inserir(ab,8);
	inserir(ab,9);
	inserir(ab,3);
	inserir(ab,1);
	inserir(ab,6);
	inserir(ab,4);
	inserir(ab,7);
	percorrer(ab,1);
	printf("\nAltura: %d",altura(ab));
	printf("\nQTD Nos: %d",qtd_nos(ab));
	
	destruir(ab);
	return 0;
}