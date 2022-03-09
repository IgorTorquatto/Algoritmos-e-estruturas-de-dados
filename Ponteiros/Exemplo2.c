#include <stdio.h>

int main()
{
    //Criação da variável:
    int x = 10;
    //Criação de dois ponteiros:
    int *pi, *pj;
    //Ponteiro pi recebe o endereço da variável x.
    pi = &x;
    //Ponteiro pj recebe pi , que ,por sua vez, tinha também o endereço de x.
    pj = pi;
    //Logo, consequentemente, pj também recebe o endereço de x.

    //Adicionamos um/Incrementamos o valor que está em x ,o qual o ponteiro *pi aponta:
    (*pi)++;
    //Adicionamos um novamente ao valor que está em x , o qual o ponteiro *pj também aponta:
    (*pj)++;
    printf("%d", x);
    //Por fim o programa imprime 12.

    return 0;
}
