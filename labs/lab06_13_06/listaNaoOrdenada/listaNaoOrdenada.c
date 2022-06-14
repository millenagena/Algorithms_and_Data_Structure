#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "listaNaoOrdenada.h"

struct no{
    int info;
    struct no *prox;
};
typedef struct no *Lista;


Lista cria_lista() {
    return NULL;
}

int lista_vazia(Lista *lst) {
    if(lst == NULL)
        return 1;
    else
        return 0;
}

int insere_elem(Lista *lst, int elem){
    // aloca um novo no
    Lista N = (Lista *) malloc(sizeof(struct no));
    if(N == NULL)
        return 0;
    N->info = elem;
    N->prox = *lst;
    *lst = N;
    return 1;

}

int remove_elem(Lista *lst, int elem){
    if(lista_vazia(lst) == 1)
        return 0;
    Lista aux = *lst; // ponteiro aux para o 1 no

    // trata elem = 1 no da lista
    if(elem == (*lst)->info){
        *lst = aux->prox; // lista aponta para 2 no
        free(aux); // libera memoria alocada
        return 1;
    }
    // percorrimento ate achar o elem ou final da lista
    while(aux->prox != NULL && aux->prox->info != elem){
        aux = aux->prox;
    }
    if(aux->prox == NULL) // trata final da lista
        return 0;

    // remove elemento diferente 1 no da lista
    Lista aux2 = aux->prox; // aponta o no a ser removido
    aux->prox = aux2->prox; // retira no da lista
    free(aux2); // libera memoria alocada
    return 1;

}

int obtem_valor_elem(Lista *lst, int pos, int *valor){
    Lista aux = *lst;
    for(int i=0; i != pos; i++){
        if(pos > i && aux->prox == NULL){
            return 0;
        }
        aux = aux->prox;
    }
    valor = aux->prox->info;
    return 1;
}

void imprime_lista(Lista *lst){
    if(lista_vazia(lst) == 1)
        return 0;

    Lista aux = *lst;
    while(aux->prox != NULL){
        printf(aux->info);
        aux = aux->prox;
    }
}

void libera_lista(Lista **lst){
    free(*lst);
    *lst = NULL;
}

