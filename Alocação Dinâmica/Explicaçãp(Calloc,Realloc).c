//Utilizar a biblioteca <stdlib.h> para usar as funções de alocação dinâmica:
#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int * pt; //declaração do ponteiro para armazenar o endereço do bloco alocado

    /*A função calloc tem a mesma operação malloc, isto é, reserva um bloco de memória com base na quantidade de bytes
     informada. A diferença está nos parâmetros recebidos. Essa função recebe no primeiro parâmetro a quantidade de
    elementos que serão alocados, já no segundo parâmetro é informado o tamanho do tipo de dado.
    */
    pt = (int *) calloc(10, sizeof(int)); //chamada da função calloc para reservar espaço para 10 elementos
    //Com malloc seria pt = (int *) malloc(10*sizeof(int)); 
    //Utilizar a biblioteca <stdlib.h> para usar as funções de alocação dinâmica:

 
    if (pt == NULL)
    {
    //memória insuficiente
    }
    else
    {
        pt = (int *) realloc(pt, 10*sizeof(int)); //chama a função realloc para reservar espaço para mais 10 elementos
    
        if (pt != NULL)
        {
        printf("Funcionando");
        }
    }
    
    free(pt); //chama a função free para liberar o bloco indicado por pt

    return 0;
}