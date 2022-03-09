#include <stdio.h>
#include <stdlib.h>
//A intenção é receber valores digitados pelo usuário até que o usuário digite 0.
//Criando, dessa forma, uma memória dinâmica para que receba cada valor digitado pelo usuário e depois, esse valor , deve ser impresso na tela.

int main()
{
    //Criação das variáveis inteiras:
    int i, tam;
    //Criação do ponteiro char e da variável char val:
    char *v, val;
    //Tamanho iniciando por 0:
    tam = 0;
    //Atribuição ,ao ponteiro , da função malloc que irá reservar um espaço de memória para um char, inicialmente.
    // O (char *) serve para que o valor recebido seja convertido para o tipo char e não ocorra nenhum erro posteriormente.
    v = (char *)malloc(sizeof(char));
    //Scanf para receber o(s) valor(es) digitado(s) pelo usuário e colocado dentro da variável val:
    scanf("%c", &val);
    //Criação do laço de repetição , ele irá rodar até que o valor digitado seja 0:
    while (val != '0') {
    tam++;
    //Uso da função realloc para que seja alocado , cada vez que o usuário digite um valor, um novo espaço de memória:
    //A variável tam multiplica o sifeof de char, assim , ela ( tam) é muito importante para que seja realocado um número de espaços de memória certo para a alocação dinâmica.
    v = (char *)realloc(v, tam *sizeof(char));
    v[tam-1] = val;
    scanf("%c", &val);
    }
    for (i = 0 ; i < tam ; i++) {
    printf("[%c]", v[i]);
    }
    free(v);

    return 0;
}