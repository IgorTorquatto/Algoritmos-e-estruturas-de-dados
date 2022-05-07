#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Fila* fi;
	fi=criar();
	
	
	destruir(fi);
	return 0;
}