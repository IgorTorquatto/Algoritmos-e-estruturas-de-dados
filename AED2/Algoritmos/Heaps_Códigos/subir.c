#include <stdio.h>

// Função para realizar a operação de subir no vetor
void subir(int vetor[], int i) {
    int j = i/2;// Cálculo do índice do pai

    if (j >= 0) {
        if (vetor[i] > vetor[j]) { // Se o valor do elemento for maior que o do pai
            // Trocar os elementos
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;

            // Chamar recursivamente para continuar subindo
            subir(vetor, j);
        }
    }
}

int main(int argc, char *argv[]) {
    int vetor[8] = {95, 60, 78, 39, 28, 98, 70, 33};
    int i;

    printf("Lista antes de aplicar o subir():\n");
    for (i = 0; i < 8; i++) {
        printf("%d - ", vetor[i]);
    }
    printf("\n");

    // Aplicar a operação de subir no vetor para transformá-lo em um max-heap
    for (i = 7; i >= 0; i--) {
        subir(vetor, i);
    }

    printf("Lista depois de aplicar o subir() (max-heap):\n");
    for (i = 0; i < 8; i++) {
        printf("%d - ", vetor[i]);
    }
    printf("\n");

    return 0;
}

