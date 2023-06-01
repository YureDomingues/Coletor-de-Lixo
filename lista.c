#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


lista* busca_endereco(lista *l, void* endereco){
    if(l != NULL){
        if(endereco == l->endereco){
            return l;
        }else{
            return busca_endereco(l->prox, endereco);
        }
    }
    return NULL;
}

void inserir_endereco(lista **l, void* endereco){
    lista *p = busca_endereco(*l, endereco);

    if(p != NULL){
        p->qtdPtr++;
    }else{
        lista *new = (lista*) malloc(sizeof(lista));

        new->endereco = endereco;
        new->qtdPtr = 1;
        new->prox = *l;

        *l = new;
    }
}

void remover_elemento(lista** l, void* endereco){
	if(*l != NULL){

		if((*l)->endereco == endereco){
			lista *p = *l;
			*l = (*l)->prox;
			free(p);
		}else{
			remover_elemento(&((*l)->prox), endereco);
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