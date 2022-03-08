#include <stdio.h>

int main(void)
{
  //valor é a variável que
  //será apontada pelo ponteiro
  int valor = 27;
  
  //declaração de variável ponteiro
  int *ptr;
  
  //atribuindo o endereço da variável valor ao ponteiro
  ptr = &valor;
  //Também funcionaria se fosse do seguinte modo:
  //int *ptr=&valor;
  
  printf("Utilizando ponteiros\n\n");
  printf ("Conteudo da variavel valor: %d\n", valor);
  //27 Conteúdo de "valor"
  printf ("Endereço da variavel valor: %x \n", &valor);
  //22ff44 Endereço de "valor"
  printf ("Conteudo da variavel ponteiro ptr: %x", ptr);
  //22ff44 Endereço de "valor", pois dentro do ponteiro "ptr" há o armazenamento desse endereço
  
  return(0);
}