#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "listaOrdenada.h"

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

int insere_ord(Lista *lst, int elem){
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL){
        return 0;
    }
    N->info = elem;
    // trata lista vazia e menor que primeiro elem
    if(lista_vazia(*lst)==1 || elem < (*lst)->info){
        N->ant = NULL;
        N->prox = *lst;
        if(lista_vazia(*lst)==0) { 
            (*lst)->ant = N; 
        }
        *lst = N;
    }
    else{ // trata elem maior que o primeiro
        Lista aux = *lst;
        while(aux->prox != NULL && aux->prox->info < elem)
            aux = aux->prox;
        if(aux->prox == NULL) // trata elem maior que ultimo
            N->prox = NULL;
        else{ // trata elem inserido no meio de outros elementos
            N->prox = aux->prox;
            aux->prox->ant = N;
        }
        aux->prox = N;
        N->ant = aux; 
    }
    return 1;
}

int remove_ord(Lista *lst, int elem){
    if(lista_vazia(*lst)==1 || elem < (*lst)->info)
        return 0;

    Lista aux = *lst; // aponta primeiro elemento
    if(elem == aux->info){
        aux->prox->ant = NULL;
        *lst = aux->prox;
        aux->prox = NULL; // teste
        free(aux);
    }
    else{
        while(aux->prox != NULL && aux->prox->info < elem)
            aux = aux->prox;
        Lista aux2 = aux->prox; // aponta pro elem a ser removido
        if(aux2->prox == NULL && aux2->info == elem){ // trata ultimo elemento
            aux->prox = NULL;
            aux2->ant = NULL; // teste
            free(aux2);
        }else{
            if(aux2 == NULL)
                return 0;
            if(aux2->info != elem) // elem nao esta na lista
                return 0;
            aux->prox = aux2->prox;
            aux->prox->ant = aux;
            free(aux2);
        }
    }
    return 1;
}

int obtem_valor_elem(Lista lst, int pos, int *elem){
    int cont=0;
    if(lista_vazia(lst) == 1)
        return 0;
    for(lst; lst != NULL; lst = lst->prox){
        if(cont == pos){
            *elem = lst->info;
            return 1;
        }
        cont++;
    }
}

void imprime_lista(Lista lst){
    if(lista_vazia(lst) == 1)
        printf("Lista vazia!");
    for(lst; lst != NULL; lst = lst->prox){
        printf("%d ", lst->info);
    }
}

void libera_lista(Lista *lst){
    if(lista_vazia(*lst))
        printf("\nLISTA VAZIA");
    else{
        Lista aux = (*lst);
        Lista aux2;
        
        while(aux != NULL){ // percorrendo a lista
            aux2 = aux;
            aux = aux->prox;
            free(aux2);
        }
        free(aux); // liberando o ultimo no
        *lst = NULL;
        printf("\nLISTA LIBERADA");
    }
}

