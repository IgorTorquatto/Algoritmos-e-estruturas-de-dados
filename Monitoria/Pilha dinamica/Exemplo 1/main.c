#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Pilha *pi;
	pi=criar();
	
	printf("Inicio: \n");
	printf("Vazia?: %d \n",vazia(pi));
	printf("Cheia?: %d \n",cheia(pi));
	
	struct aluno al;
	al.matricula=1;
	al.n1=7.0;
	int x=inserir(pi,al);
	
	printf("Deu certo inserir?:%d \n",x);
	printf("Vazia?: %d \n",vazia(pi));
	printf("Tamanho: %d \n",tamanho(pi));

	
	struct aluno al2;
	al2.matricula=2;
	al2.n1=4.3;
	inserir(pi,al2);
	printf("\nTamanho, depois de inserir o segundo elemento: %d \n",tamanho(pi));
	
	struct aluno al3;
	al3.matricula=3;
	al3.n1=5.6;
	inserir(pi,al3);
	printf("Tamanho, depois de inserir o terceiro elemento: %d \n",tamanho(pi));
	imprimir(pi);
	
	remover(pi);
	printf("\nTamanho, depois de remover: %d \n",tamanho(pi));
	imprimir(pi);
	return 0;
}
