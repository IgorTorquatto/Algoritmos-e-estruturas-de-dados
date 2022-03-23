#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int tamanho;
	Vetor *v;
	
	
	do{
		printf("Digite o tamanho do vetor que deseja ser criado:");
		scanf("%d",&tamanho);
		if(tamanho<=0){
			printf("Valor invalido, insira valores >=1.\n");
		}
	}while(tamanho<=0);
	v=criar(tamanho);
	
	
	preencher(v);
	imprimir(v);
	soma(v,2,3);
	destruir(v);
	return 0;
}