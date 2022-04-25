#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Pilha *pi;
	pi=criar();
	
	struct aluno al;
	al.matricula=1;
	inserir(pi,al);
	
	struct aluno al2;
	al2.matricula=8;
	inserir(pi,al2);
	
	struct aluno al3;
	al3.matricula=9;
	inserir(pi,al3);
	
	struct aluno al4;
	al4.matricula=47;
	inserir(pi,al4);
	
	imprimir(pi);
	printf("\nTamanho: %d \n",tamanho(pi));
	printf("Vazia? %d",vazia(pi));
	
	remover(pi);
	printf("\nLista depois de remover:\n");
	imprimir(pi);
	
	liberar(pi);
	return 0;
}