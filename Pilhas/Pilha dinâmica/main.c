#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Pilha* pi;
	pi=cria();
	int x;
	x=tamanho(pi);
	int y=vazia(pi);
	struct aluno al;
	al.matricula=1;
	inserir(pi,al);
	remover(pi);
	libera(pi);
	return 0;
}