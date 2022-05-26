#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int fatorial(int x){
	if(x<0){
		printf("Fatorial não existe");
		exit(0);
	}
	if(x==0){
		return 1;
	}
	return x* fatorial(x-1);
}

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"Portuguese");
	int x;
	printf("Digite um número: ");
	scanf("%d",&x);
	int f=fatorial(x);
	printf("O fatorial de %d é %d.",x,f);
	return 0;
}