#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 10;
    int *ponteiroX = &x;

    printf("Valor de x: %d\n", x);             // Valor de x antes da altera��o
    printf("Valor apontado por ponteiroX: %d\n", *ponteiroX);  // Valor apontado pelo ponteiroX (conte�do de x)

    *ponteiroX = 20;  // Alterando o valor de x atrav�s do ponteiro

    printf("Valor de x ap�s a altera��o: %d\n", x);  // Valor de x ap�s a altera��o
    printf("Valor apontado por ponteiroX: %d\n", *ponteiroX);  // Valor apontado pelo ponteiroX ap�s a altera��o

    return 0;
}

