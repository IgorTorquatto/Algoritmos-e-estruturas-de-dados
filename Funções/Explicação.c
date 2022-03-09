#include <stdio.h>
#include <math.h>

int main()
{
    //Criar a função func com tipo da saída, nome da função, parâmetro 1  e parâmetro 2:
    float func (float x, int n){
    float resultado = pow(x,n);
    //Fazer o return da variável:
    return resultado;
    }
    //Utilizar a função:
    printf("%2.f",func(5.0,2));

    return 0;
}
