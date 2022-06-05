#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"
#include <string.h>
#include <locale.h>

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"Portuguese");
	Arvore *ab;
	ab=NULL;
	ab=criar();
	
	struct aluno al1;
	al1.matricula=1;
	al1.av=5.0;
	strcpy(al1.nome,"Aluno1");
	
	struct aluno al2;
	al2.matricula=2;
	al2.av=6.0;
	strcpy(al2.nome,"Aluno2");
	
	struct aluno al3;
	al3.matricula=3;
	al3.av=7.0;
	strcpy(al3.nome,"Aluno3");
	
	
	inserir(ab,al1);
	inserir(ab,al2);
	inserir(ab,al3);
	
	percorrer(ab,1);
	
	printf("\nQuantidade de nós: %d",quantidadeNos(ab));

	
	destruir(ab);
	return 0;
}