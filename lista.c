#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    void* endereco;
    int qtdPtr;
    struct lista* prox;
}lista;

void criar_lista(lista **l){
    l = NULL;
}

lista* busca_endereco(lista *l, void* endereco){
    if(l != NULL){
        if(endereco == l->endereco){
            return l;
        }else{
            return existe_endereco(l, endereco);
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

void remover_elemento(lista** l, int endereco){
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