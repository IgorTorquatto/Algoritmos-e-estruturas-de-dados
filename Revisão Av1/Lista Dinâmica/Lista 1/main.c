#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <string.h>
#include <locale.h>

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"Portuguese");
	
	Lista* li;
	li=criar();
	
	struct aluno al1;
	al1.matricula=1;
	strcpy(al1.nome,"André");
	
	struct aluno al2;
	al2.matricula=2;
	strcpy(al2.nome,"Ronaldo");
	
	struct aluno al3;
	al3.matricula=3;
	strcpy(al3.nome,"Edilson");
	
	struct aluno al4;
	al4.matricula=4;
	strcpy(al4.nome,"Juarez");
	
	struct aluno al5;
	al5.matricula=5;
	strcpy(al5.nome,"Romario");
	
	printf("Inserindo dois elementos: \n");
	inserir_inicio(li,al1);
	inserir_inicio(li,al2);
	imprimir(li);
	printf("\nTamanho: %d",tamanho(li));
	printf("\nVazia? %d ",vazia(li));
	
	printf("Inserindo no final: \n");
	inserir_final(li,al3);
	imprimir(li);
	printf("\nTamanho: %d",tamanho(li));
	
	printf("\nInserindo a matricula 4 ordenado: \n");
	inserir_ordenado(li,al4);
	imprimir(li);
	printf("\nTamanho: %d",tamanho(li));
	
	printf("\nRemovendo Inicio: \n");
	remover_inicio(li);
	imprimir(li);
	printf("\nTamanho: %d",tamanho(li));

	printf("\nRemovendo Final: \n");
	remover_final(li);
	imprimir(li);
	printf("\nTamanho: %d",tamanho(li));
	
	printf("\nRemovendo Matricula 3: \n");
	int y=3;
	remover_valor(li,y);
	imprimir(li);
	printf("\nTamanho: %d",tamanho(li));
	
	destruir(li);
	return 0;
}