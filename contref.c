#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

lista *lixo = NULL;

void* malloc2(int tamanho){
    void *v = malloc(tamanho);
    inserir_endereco(&lixo, v);
    return v;
}

void atrib2(void){


}

void print_lixo(){
    print_lista(lixo);
}