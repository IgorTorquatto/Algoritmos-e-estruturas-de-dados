#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <locale.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"Portuguese");
	Lista *li;
	li=criar();
	
	struct aluno al1;
	al1.id=1;
	strcpy(al1.nome,"Kratos");
	inserir_inicio(li,al1);
	
	struct aluno al2;
	al2.id=2;
	strcpy(al2.nome,"Zeus");
	inserir_inicio(li,al2);
	
	struct aluno al3;
	al3.id=3;
	strcpy(al3.nome,"Odin");
	inserir_inicio(li,al3);
	
	imprimir(li);
	printf("\nTamanho : %d",tamanho(li));
	printf("\nVazia? : %d",vazia(li));
	remover_inicio(li);
	printf("\nRemovendo inicio: \n");
	imprimir(li);
	printf("\nTamanho : %d",tamanho(li));
	
	printf("\nInserindo final: \n");
	inserir_final(li,al3);
	imprimir(li);
	
	printf("\nInserindo final: \n");
	inserir_final(li,al2);
	imprimir(li);
	
	printf("\nInserindo final: \n");
	inserir_final(li,al1);
	imprimir(li);
	
	printf("\nRemovendo no inicio e no final:\n");
	remover_inicio(li);
	remover_final(li);
	imprimir(li);
	
	printf("\nInserindo elemento 2:\n");
	inserir_ordenado(li,al2);
	imprimir(li);
	printf("\nTamanho: %d",tamanho(li));
	
	printf("\nRemovendo final:\n");
	remover_final(li);
	imprimir(li);
	printf("\nTamanho: %d",tamanho(li));
	
	
	int x=2;
	printf("\nRemovendo valor 2:\n");
	remover_valor(li,x);
	imprimir(li);
	printf("\nTamanho: %d",tamanho(li));
	
	destruir(li);
	return 0;
}