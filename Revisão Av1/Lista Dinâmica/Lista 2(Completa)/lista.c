#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct elemento{
	struct aluno dados;
	struct elemento *prox;
};

typedef struct elemento Elem;

Lista *criar(){
	Lista *li;
	li=(Lista*)malloc(sizeof(Lista));
	if(li!=NULL)
	*li=NULL;
	return li;
}

void destruir(Lista *li){
	if(li!=NULL){
		Elem *aux;
		while(*li!=NULL){
			aux=*li;
			*li=(*li)->prox;
			free(aux);
		}
		free(li);
	}
}

int vazia(Lista *li){
	if(li==NULL) return 1;
	if(*li==NULL) return 1;
	return 0;
}

int tamanho(Lista *li){
	if(li==NULL) return 0;
	if(*li==NULL) return 0;
	Elem *aux;
	aux=*li;
	int cont=0;
	while(aux!=NULL){
		cont++;
		aux=aux->prox;
	}
	return cont;
}

int imprimir(Lista *li){
	if(li==NULL) return 0;
	if(*li==NULL) return 0;
	Elem* aux;
	aux=*li;
	while(aux!=NULL){
		printf("(%d | %s)",aux->dados.matricula,aux->dados.nome);
		aux=aux->prox;
	}
	return 1;
}

int inserir_inicio(Lista *li,struct aluno al){
	if(li==NULL) return 0;
	Elem *no;
	no=(Elem*)malloc(sizeof(Elem));
	if(no==NULL) return 0;
	no->dados=al;
	no->prox=(*li);
	*li=no;
	return 1;
}

int inserir_final(Lista *li,struct aluno al){
	if(li==NULL) return 0;
	Elem *no;
	no=(Elem*)malloc(sizeof(Elem));
	no->dados=al;
	no->prox=NULL;
	
	if(*li==NULL){
		*li=no;
		return 1;
	}
	Elem *aux;
	aux=*li;
	while(aux->prox!=NULL){
		aux=aux->prox;
	}
	aux->prox=no;
	return 1;
}

int inserir_ordenado(Lista *li,struct aluno al){
	if(li==NULL) return 0;
	Elem *no;
	no=(Elem*)malloc(sizeof(Elem));
	if(no==NULL) return 0;
	no->dados=al;
	
	if(*li==NULL){
	no->prox=(*li);
	*li=no;
	return 1;
	}
	else{
		Elem *ant,*atual;
		atual=*li;
		while(atual!=NULL && atual->dados.matricula < al.matricula){
			ant=atual;
			atual=atual->prox;
		}
		if(atual==*li){
			no->prox=(*li);
		    *li=no;
		}
		else{
			no->prox=ant->prox;
			ant->prox=no;
		}
		return 1;
	
	}
		
}

int remover_inicio(Lista *li){
	if(li==NULL) return 0;
	if(*li==NULL) return 0;
	Elem *aux;
	aux=(*li);
	*li=(*li)->prox;
	free(aux);
	return 1;
}

int remover_final(Lista *li){
	if(li==NULL) return 0;
	if(*li==NULL) return 0;
	Elem *ant,*atual;
	atual=*li;
	
	while(atual->prox!=NULL){
		ant=atual;
		atual=atual->prox;
	}
	if(atual==*li){
		*li=atual->prox;
	}
	else{
	ant->prox=atual->prox;
	}
	free(atual);
	return 1;
}

int remover_valor(Lista *li,int x){
	if(li==NULL) return 0;
	if(*li==NULL) return 0;
	
	Elem *ant,*atual;
	atual=*li;
	while(atual!=NULL && atual->dados.matricula != x){
		ant=atual;
		atual=atual->prox;
	}
	if(atual==NULL) return 0;
	if(atual==*li){
		*li=atual->prox;
	}
	else{
		ant->prox=atual->prox;
	}
	free(atual);
	return 1;
}

int remover_dois_inicio(Lista *li){
	remover_inicio(li);
	remover_inicio(li);
}

int remover_dois_final(Lista *li){
	remover_final(li);
	remover_final(li);
}

int inserir_unico_inicio(Lista *li,struct aluno al){
	if(li==NULL) return 0;
	Elem *no;
	no=(Elem*)malloc(sizeof(Elem));
	if(no==NULL) return 0;
	no->dados=al;
	
	Elem *aux;
	aux=*li;
	while(aux!=NULL  && aux->dados.matricula != al.matricula){
		aux=aux->prox;
	}
	if(aux!=NULL) return 0;
	else{
		no->prox=(*li);
		*li=no;
	}
	return 1;
}

int informacoes(Lista *li){
	if(li==NULL) return 0;
	if(*li==NULL) return 0;
	int par=0,impar=0,maior,menor;
	Elem *aux;
	aux=*li;
	
	while(aux!=NULL){
		if(aux->dados.matricula % 2 == 0){
			par++;
		}
		else{
			impar++;
		}
		if(aux==*li){
			maior=aux->dados.matricula;
			menor=aux->dados.matricula;
		}
		else{
			if(aux->dados.matricula>maior){
				maior=aux->dados.matricula;
			}
			if(aux->dados.matricula <menor){
				menor=aux->dados.matricula;
			}
		}
		aux=aux->prox;
	}
	printf("Maior: %d ; Menor: %d ; Impares: %d; Pares: %d \n",maior,menor,impar,par);
}

int inverter(Lista *li){
    if(li == NULL) return 0;
    if(*li == NULL) return 0;
    Elem *ant = NULL;
    Elem*atual = *li;
    Elem *prox;
    while(atual != NULL){
        prox = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = prox;
    }
    *li = ant;
    return 1;
}

Lista* concatenar(Lista *li, Lista *ld){
   Lista *ln;
   ln=(Lista*)malloc(sizeof(Lista));
   if(ln==NULL) return 0;
   *ln=*li;
   Elem *no;
   no=*li;
   while(no->prox!=NULL){
   	no=no->prox;
   }
   no->prox=*ld;
   free(li);
   free(ld);
   return ln;
}

Lista* copia(Lista *li){
    if(li == NULL) return 0;
    if(*li == NULL) return 0;
    Lista *lf;
    lf = (Lista*)malloc(sizeof(Lista));
    if(lf==NULL) return 0;
    *lf=NULL;
    int i;
    for(i = 0; i < tamanho(li); i++){
        Elem *no = (Elem*)malloc(sizeof(Elem));
        if(no == NULL) return 0;
        if(*lf == NULL){
        	//Insere no inicio
            no->prox = *lf;
            *lf = no;
        }
        else{
        	//Insere no final
            Elem*aux = *lf;
            while(aux->prox != NULL){
                aux = aux->prox;
            }
            no->prox=NULL;
            aux->prox=no;
        }
    }
    Elem *aux = *li;
    Elem *aux2 = *lf;
    while(aux != NULL){
    	//Copia:
        aux2->dados = aux->dados;
        //Os dois andam:
        aux = aux->prox;
        aux2 = aux2->prox;
    }

    return lf;
}

Lista* segmentar(Lista *li, int n){
    if(li == NULL) return 0;
    if(*li == NULL) return 0;
    Lista *lf;
    lf = (Lista*)malloc(sizeof(Lista));
    if(lf ==NULL) return 0;
	*lf=NULL;
    Elem *aux = *li;
    int i;
    for(i = 0; i < n; i++){
        aux = aux->prox;
    }
    *lf = aux->prox;
    aux->prox = NULL;
    return lf;

}