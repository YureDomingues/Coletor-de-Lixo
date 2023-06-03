#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


lista* buscar_elemento(lista *l, void* elemento){
    if(l != NULL){
        if(elemento == l->endereco){
            return l;
        }else{
            return buscar_elemento(l->prox, elemento);
        }
    }
    return NULL;
}

void inserir_elemento(lista **l, void* elemento){
    lista *new = (lista*) malloc(sizeof(lista));

    new->endereco = elemento;
    new->qtdPtr = 1;
    new->prox = *l;

    *l = new;
}


void remover_lixo(lista** l){
	if(*l != NULL){
        remover_lixo((&(*l)->prox));
        
		if((*l)->qtdPtr == 0){

			lista *p = *l;
			*l = (*l)->prox;
			free(p);
        
		}  
	}
}

void print_lista(lista *l){
    if(l != NULL){
        printf("[%p,%d] ",l->endereco,l->qtdPtr);
        print_lista(l->prox);
    }else{
        printf("\n");
    };
}