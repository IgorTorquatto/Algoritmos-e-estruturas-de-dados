#include <stdio.h>
#include <stdlib.h>
#include "li.h"
#include <locale.h>
#include <string.h>

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"Portuguese");
	
	Lista *li;
	li=criar();
	
	struct aluno al1;
	al1.id=1;
	strcpy(al1.nome,"Carlos");
	inserir_inicio(li,al1);
	
	
	struct aluno al2;
	al2.id=2;
	strcpy(al2.nome,"Pedro");
	inserir_inicio(li,al2);
	
	struct aluno al3;
	al3.id=3;
	strcpy(al3.nome,"Marcos");
	inserir_inicio(li,al3);
	
	struct aluno al4;
	al4.id=4;
	strcpy(al4.nome,"Beiçola");
	inserir_inicio(li,al4);
	
	struct aluno al5;
	al5.id=5;
	strcpy(al5.nome,"Lineu");
	inserir_inicio(li,al5);
	

	printf("Lista com 5 elementos: \n");
	imprimir(li);
	
	printf("\nRemovendo inicio: \n");
	remover_inicio(li);
	imprimir(li);
	
	struct aluno al6;
	al6.id=6;
	strcpy(al6.nome,"Turco");
	inserir_final(li,al6);
	printf("\nInserindo final: \n");
	imprimir(li);
	
	printf("\nRemovendo final: \n");
	remover_final(li);
	imprimir(li);
	
	liberar(li);
	return 0;
}