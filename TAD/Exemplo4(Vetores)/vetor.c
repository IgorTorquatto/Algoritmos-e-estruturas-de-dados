#include <stdio.h>
#include "vetor.h"
#include <stdlib.h>

struct vetor {
	int max;
	int qtd;
	int *valores;
};

//O tipo de criar() é Vetor* e ele recebe como parâmetro um tamanho , que será o tamanho do vetor.
Vetor* criar(int tamanho){
	//Com o tipo Vetor criamos uma variavel ponteiro v.
	Vetor *v;
	//Esse v deve receber espaço suficiente para que todos os elementos da struct sejam associados a algo depois.
	//Por isso o tipo do malloc é Vetor, dentro do vetor tem 3 ints.
	v=(Vetor*)malloc(sizeof(Vetor));
	//Associando cada elemento do ponteiro a um valor, sendo que o max é o tamanho.
	v->max=tamanho;
	v->qtd=0;
	//Quando aponta para int *valores, lá tem um ponteiro e não uma variavel.
	//Logo devemos criar espaço para esse lugar, e definir o tipo int que já está lá.
	v->valores=(int*)malloc(sizeof(int)*tamanho);
	//Devemos multiplicar pelo tamanho, porque se eu criasse apenas o sizeof de int , lá em int valores teria espaço somente para um tamananho (indice) do vetor
	//Como nós queremos que o usuario digite o tamanho, assiim a alocação é dinamica para o tamanho desejado pelo usuario.
	return v;
}
void preencher(Vetor*v){
	int i;
	int auxiliar;
	for(i=0;i<v->max;i++){
		printf("Digite o valor da posição %d do vetor:",i+1);
		scanf("%d",&v->valores[i]);
		v->qtd++;
	}
}
void imprimir(Vetor *v){
	int i;
	printf("Valores:");
	for(i=0;i<v->max;i++){
		printf("(%d)",v->valores[i]);
		
	}
	printf("\nQtd:");
	printf("%d",v->qtd);
}
int soma(Vetor*v,int posicao_1,int posicao_2){
	//As variaveis dentro da função não podem ter o mesmo nome das variáveis do parâmetro.
	int pos_1,pos_2;
	printf("\nDigite a posicao:");
	scanf("%d",&pos_1);
	printf("Digite a posicao2:");
	scanf("%d",&pos_2);
	
	
	if((pos_1<0)||(pos_2<0)){
		printf("Posições inválidas");
		return NULL;	
	}
	
	if((pos_1&&pos_2<=v->max)&&(pos_1&&pos_2!=0)){
		
		int soma;
		soma=v->valores[(pos_1-1)]+v->valores[(pos_2-1)];
		printf("Soma : %d",soma);
		return soma;
		(pos_1&&pos_2<=0);
			
	}
	
	else{
		printf("Posições inválidas");
		return NULL;	
	}
	
}
void destruir(Vetor*v){
	int i;
	for(i=0;i<v->max;i++){
		free(v->valores[i]);
	}
	free(v);
}