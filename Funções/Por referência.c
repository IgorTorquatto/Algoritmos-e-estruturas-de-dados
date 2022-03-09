#include <stdio.h>

//O segundo parâmetro da função é um ponteiro, ou seja, posteriormente irá receber um endereço de alguma variável.
//O valor que estiver no endereço da variável colocada no ponteiro será multiplicado por 2 e ,depois, o resultado será multiplicado pelo primeiro parâmetro.
int func (int x, int *y) {
    *y = *y * 2;
    return x * (*y);
}

int main () {
    int x = 2, y = 3;
    y = func(y,&x);
    printf("%d e %d", x, y);
    //Imprime 4 e 12.
    /* Como foi passado o endereço de x para o ponteiro, 2 multiplica 2, na função, e , agora , como foi pasado por referência,
    o valor dentro de x passar a ser 4. Esse quatro vai ser multiplicado pelo primeiro parâmetro , que é y=3, e resultará 12.
    Uma vez alterado o valor de x pelo ponteiro *y ( que incialmente era 2 e depois 2*2=4 ( por causa da função)
    O programa imprime o novo valor de x e o novo valor de y(4 e 12).*/
    return 0;
}