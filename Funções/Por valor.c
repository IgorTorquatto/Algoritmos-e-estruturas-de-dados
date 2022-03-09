#include <stdio.h>

//Função declarada anteriormente a função  main:
/*A função irá multiplicar o segundo paramentro por dois e , depois, multiplicar o resultado anterior pelo primeiro parâmetro*/
int func (int x, int y) {
    y = y * 2;
    return x * y;
}
    
 int main () {
        int x = 2, y = 3;
        y = func(y,x);
        printf("%d e %d", x, y);
        //Imprime 2 e 12.
        return 0;
    }