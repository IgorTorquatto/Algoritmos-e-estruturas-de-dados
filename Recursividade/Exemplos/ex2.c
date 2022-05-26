#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int soma(int x){
	if(x<0){
		printf("valor inválido");
		exit(0);
	}
	if(x==0){
		return 0;
	}
	return x+soma(x-1);
	
}

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"Portuguese");
	int x;
	printf("Digite um número inteiro: ");
	scanf("%d",&x);
	int valor=soma(x);
	printf("Soma dos %d primeiros números inteiros: %d",x,valor);

}