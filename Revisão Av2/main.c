#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	Arvore* ab;
	ab=NULL;
	ab=criar();
	
	struct aluno al1;
	al1.matricula=6;
	
	struct aluno al2;
	al2.matricula=5;
	
	struct aluno al3;
	al3.matricula=4;
	
	struct aluno al4;
	al4.matricula=3;
	
	struct aluno al5;
	al5.matricula=2;
	
	struct aluno al6;
	al6.matricula=1;
	
	inserir(ab,al1);
	inserir(ab,al2);
	inserir(ab,al3);
	inserir(ab,al4);
	inserir(ab,al5);
	inserir(ab,al6);
	
	struct aluno al7;
	
	percorrer(ab,1);
	printf("\n%d",acessar(ab,3,&al7.matricula));
	printf("\n%d",al7.matricula);
	
	destruir(ab);
	return 0;
}