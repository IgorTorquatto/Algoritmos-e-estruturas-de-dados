#include <stdio.h>
#include <stdlib.h>
#include "especificação.h"
#include <math.h>

typedef struct ponto{
	float x;
	float y;
}Ponto;
//Foi criado um novo tipo , o Ponto*
//O Ponto* tem , por nossa definição, espaço para dois ints.
Ponto* criar(float ponto1,float ponto2){
	//Para que possamos ter acesso aos dois ints de Ponto devemos criar uma variavel do tipo ponteiro que vai conseguir acessar os dois ints do strcut
	Ponto *m;
	//Temos sempre que alocar o tamanho para essa variavel
	m=malloc(sizeof(Ponto));
	//AGORA TEMOS ACESSO TANTO A X COMO A Y E , ASSIM, FAZEMOS UMA CORRELAÇÃO COM OS DOIS ARGUMENTOS PONTO1 E PONTO2.
	m->x=ponto1;
	m->y=ponto2;
	//Temos que retornar esse m.
	return m;
	
}

void mostrar(Ponto* m){
	printf("%.2f %.2f",m->x,m->y);
}

void destruir(Ponto* m){
	free(m);
}

float distancia(Ponto* m,Ponto* z){
	 
	 return sqrt(pow(z->y - m->y,2)+pow(z->x - m->x,2));
}