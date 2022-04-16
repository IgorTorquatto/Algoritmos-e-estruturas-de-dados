#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


int main(int argc, char *argv[]) {
    
	Pilha *pi;
	pi=cria();
	int x=tamanho(pi);
	int y=cheia(pi);
	printf("%d\n",y);
	int z=vazia(pi);
	printf("%d",z);
	remover(pi);
	libera(pi);

	return 0;
}