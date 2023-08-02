#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 10;
    int *ponteiroX = &x;

    printf("Valor de x: %d\n", x);             // Valor de x antes da alteração
    printf("Valor apontado por ponteiroX: %d\n", *ponteiroX);  // Valor apontado pelo ponteiroX (conteúdo de x)

    *ponteiroX = 20;  // Alterando o valor de x através do ponteiro

    printf("Valor de x após a alteração: %d\n", x);  // Valor de x após a alteração
    printf("Valor apontado por ponteiroX: %d\n", *ponteiroX);  // Valor apontado pelo ponteiroX após a alteração

    return 0;
}

