#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Lista *li;
	int tam;
	printf("Digite o tamanho da lista:");
	scanf("%d",&tam);
	li=criar(tam);
	preencher(li);
	tamanho(li);
	imprimir(li);
	printf("\nNova lista(Adicionando 10 no fim):\n");
	inserir_fim(li,10);
	imprimir(li);
	inserir_inicio(li,1);
	printf("\nNova lista (Adicionando 1 no inicio): \n");
	imprimir(li);
	remover_final(li);
	printf("\nNova lista (Retirando 10 do final): \n");
	imprimir(li);
	remover_inicio(li);
	printf("\nNova lista (Retirando 1 do inicio): \n");
	imprimir(li);
	destruir(li);
	return 0;
}