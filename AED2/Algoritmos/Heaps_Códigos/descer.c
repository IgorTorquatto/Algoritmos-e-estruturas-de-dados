#include <stdio.h>

// Função para realizar a operação de descer no heap
void descer(int vetor[], int i, int n) {
    int j = 2 * i + 1; // Índice do filho esquerdo

    if (j <= n) {
        if (j < n && vetor[j + 1] > vetor[j]) {
            j++; // Escolhe o filho direito se ele for maior
        }

        if (vetor[i] < vetor[j]) { // Se o valor do elemento for menor que o do filho
            // Trocar os elementos
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;

            // Chamar recursivamente para continuar descendo
            descer(vetor, j, n);
        }
    }
}

int main() {
    int vetor[8] = {95, 60, 78, 39, 28, 98, 70, 33};
    int n = 7; // Índice do último elemento no heap
    int i;

    printf("Lista antes de aplicar o descer():\n");
    for (i = 0; i <= n; i++) {
        printf("%d - ", vetor[i]);
    }
    printf("\n");

    // Aplicar a operação de descer no vetor para transformá-lo em um max-heap
    for (i = n / 2; i >= 0; i--) {
        descer(vetor, i, n);
    }

    printf("Lista depois de aplicar o descer() (max-heap):\n");
    for (i = 0; i <= n; i++) {
        printf("%d - ", vetor[i]);
    }
    printf("\n");

    return 0;
}

