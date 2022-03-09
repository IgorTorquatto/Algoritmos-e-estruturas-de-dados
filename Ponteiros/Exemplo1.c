#include <stdio.h>

int main()
{
    int x, *y;
    y = &x;
    printf("%p e %p", &x, y);
    //Irá imprimir os dois endereços de x , já que o ponteiro y é igual a &x .
    return 0;
}