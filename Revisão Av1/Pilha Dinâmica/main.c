#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include <string.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"Portuguese");
	Pilha* pi;
	pi=criar();
	
	struct aluno al1;
	al1.matricula=1;
	strcpy(al1.nome,"ALUNO1");
	
	struct aluno al2;
	al2.matricula=2;
	strcpy(al2.nome,"ALUNO2");
	
	inserir(pi,al1);
	inserir(pi,al2);
	inserir(pi,al1);
	inserir(pi,al2);
	imprimir(pi);
	printf("\nTamanho: %d \n",tamanho(pi));
	
	remover(pi);
	imprimir(pi);
	printf("\nTamanho: %d ",tamanho(pi));


	destruir(pi);
	return 0;
}