#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include <locale.h>


int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"Portuguese");
	Lista *li ,*ld;
	li=criar();
	ld=criar();
	
	struct aluno al1;
	al1.matricula=1;
	strcpy(al1.nome,"Igor");

	struct aluno al2;
	al2.matricula=2;
	strcpy(al2.nome,"Juvenal");
	
	struct aluno al3;
	al3.matricula=3;
	strcpy(al3.nome,"Floriano");
	
	struct aluno al4;
	al4.matricula=4;
	strcpy(al4.nome,"Deodoro");

	struct aluno al5;
	al5.matricula=5;
	strcpy(al5.nome,"Richard");

	inserir_ordenado(li,al3);
	inserir_ordenado(li,al5);
	inserir_ordenado(li,al2);
	inserir_ordenado(li,al1);
	inserir_ordenado(li,al4);
	
	
	inserir_ordenado(ld,al3);
	inserir_ordenado(ld,al5);
	inserir_ordenado(ld,al2);

	imprimir(li);
	printf("\nTamanho: %d\n",tamanho(li));
	informacoes(li);
	
	imprimir(ld);
	printf("\nTamanho: %d\n",tamanho(ld));
	informacoes(ld);
	
	printf("\nConcatenando:\n");
	Lista *ln;
	ln=concatenar(li,ld);
	imprimir(ln);
	
	printf("\n\nCópia da lista 2: \n");
	Lista* cp;
	cp=copia(ld);
	imprimir(cp);
	
	
	destruir(li);
	return 0;
}