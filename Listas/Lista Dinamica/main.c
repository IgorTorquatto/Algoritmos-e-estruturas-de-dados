#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Lista* li;
	li=criar();
	
	printf("%d \n",tamanho(li));
	printf("%d \n",vazia(li));
	
	struct aluno al;
	al.matricula=1;
	inserir_inicio(li,al);
	
	printf("%d \n",tamanho(li));
	printf("%d \n",vazia(li));
	
	liberar(li);
	return 0;
}