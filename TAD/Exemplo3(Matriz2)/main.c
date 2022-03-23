#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(int argc, char *argv[]) {
	Matriz *matriz;
	matriz=criar(4,4);
	preencher_aleatorio(matriz);
	mostrar(matriz);
	destruir(matriz);
	return 0;
}