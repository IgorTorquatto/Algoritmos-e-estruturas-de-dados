#include <stdio.h>
#include <stdlib.h>
#include "fila.h"



int main(int argc, char *argv[]) {
	Fila* fi;
	fi=criar();
	tamanho(fi);
	
	
	libera(fi);	
	return 0;
}