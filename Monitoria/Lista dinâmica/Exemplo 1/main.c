#include <stdio.h>
#include <stdlib.h>
#include "li.h"
#include <locale.h>
#include <string.h>

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"Portuguese");
	Lista *li;
	li=criar();
	
	printf("A lista está cheia? %d \n",cheia(li));
	printf("A lista está vazia? %d \n\n",vazia(li));
	
	struct pessoa pe1;
	pe1.id=1;
	strcpy(pe1.nome,"Igor");
	strcpy(pe1.emprego,"Programador");
	inserir_inicio(li,pe1);
	printf("Lista com 1 elemento: \n");
	imprimir(li);
	
	struct pessoa pe2;
	pe2.id=2;
	strcpy(pe2.nome,"Pedro");
	strcpy(pe2.emprego,"Servente");
	inserir_inicio(li,pe2);
	printf("\nLista com 2 elementos: \n");
	imprimir(li);
	
	struct pessoa pe3;
	pe3.id=3;
	strcpy(pe3.nome,"Antonio");
	strcpy(pe3.emprego,"Padeiro");
	inserir_inicio(li,pe3);
	printf("\nLista com 3 elementos: \n");
	imprimir(li);
	
	struct pessoa pe4;
	pe4.id=4;
	strcpy(pe4.nome,"Carlos");
	strcpy(pe4.emprego,"Professor");
	inserir_final(li,pe4);
	printf("\nLista com 4 elementos: \n");
	imprimir(li);
	
	printf("\n Removendo inicio: \n");
	remover_inicio(li);
	imprimir(li);
	
	printf("\n Removendo finaL: \n");
	remover_final(li);
	imprimir(li);
	
	
	liberar(li);
	return 0;
}