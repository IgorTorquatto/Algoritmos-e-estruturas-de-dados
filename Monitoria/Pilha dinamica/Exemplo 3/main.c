#include <stdio.h>
#include <stdlib.h>
#include "pi.h"
#include <locale.h>
#include <string.h>

int main(int argc, char *argv[]) {
setlocale(LC_ALL, "Portuguese");

Pi* pi;
pi=criar();

//Teste vazia:
printf("A pilha está vazia ? %d \n",vazia(pi));

//Criando um elemento:
struct pessoa pe;
pe.id=1;
strcpy(pe.nome,"Nome1");
inserir(pi,pe);
imprimir(pi);
printf("\n");

struct pessoa pe2;
pe2.id=2;
strcpy(pe2.nome,"Nome2");
inserir(pi,pe2);
imprimir(pi);
printf("\nTamanho:%d \n",tamanho(pi));

struct pessoa pe3;
pe3.id=3;
strcpy(pe3.nome,"Nome3");
inserir(pi,pe3);
imprimir(pi);
printf("\nTamanho:%d \n",tamanho(pi));

printf("Removendo o elemento: \n");
remover(pi);
imprimir(pi);


return 0;
}