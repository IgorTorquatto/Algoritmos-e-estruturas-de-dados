#include <stdio.h>
//Exemplo de passagem de struct como parâmetro:
struct ponto{
    int x,y;
};

void imprime_valor(int n){
    printf("Valor = %d \n",n);
}

int main(){
    
    struct ponto p1;
    p1.x=10;
    p1.y=20;
    imprime_valor(p1.x);
    imprime_valor(p1.y);
    
    return 0;
}
