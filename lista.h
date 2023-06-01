#ifndef __LISTA_
#define __LISTA_

typedef struct lista{
    void* endereco;
    int qtdPtr;
    struct lista* prox;
}lista;

void inserir_endereco(lista **l, void* endereco);
lista* busca_endereco(lista *l, void* endereco);
void remover_elemento(lista** l, void* endereco);
void print_lista(lista *l);
#endif