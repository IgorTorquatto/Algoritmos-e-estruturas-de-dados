#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void findLargestElements(int vetor[], int tamanho, int *maior, int *segundo_maior) {
	
	int i;
	
    if (tamanho < 2) {
        printf("Erro: O vetor deve ter pelo menos 2 elementos.\n");
        return;
    }

    *maior = vetor[0];          // Inicializa 'maior' com o primeiro elemento do vetor
    *segundo_maior = vetor[1];  // Inicializa 'segundo_maior' com o segundo elemento do vetor

    for (i = 2; i < tamanho; i++) {
        if (vetor[i] > *maior) {
            *segundo_maior = *maior;  // Atualiza 'segundo_maior' com o valor anterior de 'maior'
            *maior = vetor[i];        // Atualiza 'maior' com o novo valor maior encontrado
        }
    }
}

int main() {
	setlocale(LC_ALL,"Portuguese");
    int vetor[] = {10, 5, 20, 15, 30, 25, 40};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    //A expressão sizeof(vetor) retorna o tamanho em bytes do vetor; sizeof(vetor[0]) retorna o tamanho em bytes do tipo de dado do primeiro elemento
    //Assim, a fórmula sizeof(vetor) / sizeof(vetor[0]) nos dá o número de elementos do vetor, pois a divisão do tamanho total do vetor pelo tamanho de um elemento individual resulta no número de elementos armazenados no vetor.
    int maior, segundo_maior;

    findLargestElements(vetor, tamanho, &maior, &segundo_maior);

    printf("O maior elemento do vetor é: %d\n", maior);
    printf("O segundo maior elemento do vetor é: %d\n", segundo_maior);

    return 0;
}

