#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "listaOrdenada.h"

struct no{
    int info;
    struct no *prox;
};
typedef struct no *Lista;


Lista cria_lista() {
    return NULL;
}

int lista_vazia(Lista lst) {
    if(lst == NULL)
        return 1;
    else
        return 0;
}

int insere_ord(Lista *lst, int elem){
    // aloca um novo no
    Lista N = (Lista)malloc(sizeof(struct no));
    if (N == NULL){
        return 0; // Nó nao alocado
    }
    N->info = elem;
    if (lista_vazia(*lst) == 1 || elem <= (*lst)->info){
        N->prox = *lst;
        *lst = N;
        return 1;
    }
    Lista aux = *lst;
    while (aux->prox != NULL && aux->prox->info < elem){
        aux = aux->prox;
    }
    N->prox = aux->prox;
    aux->prox = N;
    return 1;
}

int remove_ord(Lista *lst, int elem){
    if (lista_vazia(lst) == 1 || elem < (*lst)->info){
        return 0; // falha
    }
    Lista aux = *lst;
    if (elem == (*lst)->info){
        *lst = aux->prox;
        free(aux);
        return 1;
    }

    while (aux->prox != NULL && aux->prox->info < elem){
        aux = aux->prox;
    }
    if(aux->prox == NULL || aux->prox->info > elem){
        return 0;
    }
    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    return 1;
}

int obtem_valor_elem(Lista lst, int pos){
    int c = 0;
    if (lista_vazia(lst) == 1){
        return 0; // falha
    }
    for (lst; lst != NULL; lst = lst->prox)
    {
        if (c == pos){
            return (*lst).info;
        }
        c++;
    }
}

void imprime_lista(Lista lst){
    printf("Lista: {");
    for(lst; lst != NULL; lst = lst->prox){
        printf((lst->prox != NULL) ? "%d, ": "%d", lst->info);
    }
    printf("}");
}

void libera_lista(Lista *lst){
    free(*lst);
    *lst = NULL;
}

