#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
//#include "listaDupla.h"

struct no{
    int info;
    struct no *prox;
    struct no *ant;
};
typedef struct no *Lista;

Lista cria_lista(){
    return NULL;
}

int lista_vazia(Lista lst){
    if(lst == NULL){
        return 1;
    }else{
        return 0;
    }
}

int insere_elem(Lista *lst, int elem){
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL){return 0;}
    N->info = elem;
    N->ant = NULL;
    N->prox = *lst;
    if(lista_vazia(*lst) == 0) // se lista nao vazia
        (*lst)->ant = N;
    *lst = N;
    return 1;
}

int remove_elem(Lista *lst, int elem){
    if(lista_vazia(*lst)) // trata lista vazia
        return 0;
    Lista aux = *lst; // faz aux apontar para 1 no
    while(aux->prox != NULL && aux->info != elem)
        aux = aux->prox;
    if(aux->info != elem) // elemento nao esta na lista
        return 0;
    if(aux->prox != NULL)
        aux->prox->ant = aux->ant;
    if(aux->ant != NULL)
        aux->ant->prox = aux->prox;
    if(aux == *lst)
        *lst = aux->prox;
    free(aux);
    return 1;
}
