//Utilizar a biblioteca <stdlib.h> para usar as funções de alocação dinâmica:
#include <stdio.h>
#include <stdlib.h>

int main(void){
    

    //declaração do ponteiro para armazenar o endereço do bloco alocado:
    int * pt; 
    //um modo de obter o tamanho que um tipo de dado representa é a partir do operador sizeof:
    //chamada da função malloc para reservar espaço para 10 elementos:
    pt = (int *) malloc(10*sizeof(int)); 
    //Também,funcionaria se fosse:
    //int * pt=(int *) malloc(10*sizeof(int)); 
    
    //verifica se o endereço de retorno é válido
    if(pt != NULL)
    {
    printf("10"); //…operações com o ponteiro
    }
    
    free(pt); //chama a função free para liberar o bloco indicado por pt

    return 0;
}