#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
 struct matriz{
 	int linhas;
 	int colunas;
 	float **valores;
 };Matriz;
 
 Matriz* criar(int x,int y){
 	Matriz *m;
 	m=(Matriz*)malloc(sizeof(Matriz));
 	m->linhas=x;
 	m->colunas=y;
 	//Quando formos passar os parametros para criar uma matriz temos que passar dois ints (linhas e colunas).
 	//Mas não queremos passar nenhum valor de inicio .
 	//Porém, temos que criar no ponteiro da variavel m, espaços para depois colocar os valores de cada elemento da matriz.
 	m->valores=(float**)malloc(x*sizeof(float*));
 	//Como o tipo de valores é float, com dois asteriscos, agora o float tipo do malloc (primeiro) deve ter dois ** e o segundo ( so sizeof) um *.
 	//Devemos ,ainda, multiplicar pelo numero de linhas (m->linhas , que agora é x).
 	
 	int i;
 	for(i=0;i<x;i++){
 		m->valores[i]=(float*)malloc(y*sizeof(float));
	 }
 	return m;
 }
 
 void preencher_aleatorio(Matriz *m){
 	int i,j;
 	for(i=0;i<m->linhas;i++){
 		for(j=0;j<m->colunas;j++){
 			m->valores[i][j]=rand()%100;
		 }
	 }
 }
 void mostrar(Matriz *m){
 	int i,j;
 	for(i=0;i<m->linhas;i++){
 		for(j=0;j<m->colunas;j++){
 			printf("%.1f\t",m->valores[i][j]);
		 }
		 printf("\n");
	 }
 	
 }
 void destruir(Matriz *m){
 	int i;
 	for(i=0;i<m->linhas;i++){
 		free(m->valores[i]);
 		free(m->valores);
 		free(m);
	 }
 }