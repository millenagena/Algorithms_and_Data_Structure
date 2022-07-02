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
    int r;

    if(lista_vazia(*lst) || elem <= (*lst)->info){
        Lista N = (Lista) malloc(sizeof(struct no));
        if(N == NULL)
            return 0; // Nó nao alocado
        N->info = elem;
        N->prox = *lst;   
        *lst = N;
        return 1;    
    }else{
        r = insere_ord(&(*lst)->prox, elem);
        return r;
    }
}

int remove_ord(Lista *lst, int elem){
    Lista aux;
    int r;

    if(lista_vazia(*lst) || elem < (*lst)->info)
        return 0;
    else{
        if(elem == (*lst)->info){
            aux = *lst;
            *lst = aux->prox;
            free(aux);
            return 1;
        }else{
            r = remove_ord(&(*lst)->prox, elem);
            return r;
        }
    }
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

