
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <locale.h>
#include <string.h>


int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"Portuguese");
	
	Lista *li;
	li=criar();
	
	struct pessoa pe1;
	pe1.id=1;
	strcpy(pe1.nome,"Pessoa1");
	strcpy(pe1.emprego,"Professor");
	
	struct pessoa pe2;
	pe2.id=2;
	strcpy(pe2.nome,"Pessoa2");
	strcpy(pe2.emprego,"Padeiro");
	
	struct pessoa pe3;
	pe3.id=3;
	strcpy(pe3.nome,"Pessoa3");
	strcpy(pe3.emprego,"Psicologo");
	
	printf("Lista: \n");
	inserir_inicio(li,pe1);
	inserir_inicio(li,pe2);
	inserir_inicio(li,pe3);
	imprimir(li);
	printf("\nTamanho: %d",tamanho(li));
	
	
	inserir_final(li,pe3);
	inserir_final(li,pe2);
	
	printf("\nLista: \n");
	imprimir(li);
	printf("\nTamanho: %d",tamanho(li));
	
	
	printf("\nLista removendo o primeiro: \n");
	remover_inicio(li);
	imprimir(li);
	printf("\nTamanho: %d",tamanho(li));
	
	printf("\nLista removendo o último: \n");
	remover_final(li);
	imprimir(li);
	printf("\nTamanho: %d",tamanho(li));
	
	printf("\nLista inserido 1 ordenado: \n");
	inserir_ordenado(li,pe1);
	imprimir(li);
	printf("\nTamanho: %d",tamanho(li));
	
	
	printf("\nRemovendo o 2 \n");
	int x=2;
	remover_valor(li,x);
	imprimir(li);
	printf("\nTamanho: %d",tamanho(li));
	
	destruir(li);
	return 0;
}
