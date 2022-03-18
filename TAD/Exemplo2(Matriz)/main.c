#include <stdio.h>
#include "matriz.h"
#include <stdlib.h>

int main(){
    Matriz *m;
    m=novaMatriz(2,2);
    exibirMatriz(m);
    return 0;
}