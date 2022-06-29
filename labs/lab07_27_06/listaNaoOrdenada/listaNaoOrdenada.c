#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "listaNaoOrdenada.h"

struct no{
    int info;
    struct no *prox;
};

Lista cria_lista(){
    // Aloca o no cabecalho
    Lista cab;
    cab = (Lista) malloc(sizeof(struct no));

    // Coloca a lista no estado de vazia
    if(cab != NULL){
        cab->prox = NULL;
        cab->info = 0; // OPCIONAL: guardar qntd
    }
    return cab; // se falhar vai retornar NULL
}

int lista_vazia(Lista lst){
    if(lst->prox == NULL){
        return 1;
    }else{
        return 0;
    }
}

int insere_elem(Lista *lst, int elem){
    // aloca um novo no
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL)
        return 0;

    // preenche os campos do novo no
    N->info = elem; // insere elem
    N->prox = (*lst)->prox; // aponta para o 1 no atual da lista
    (*lst)->prox = N; // faz o no cabecalho apontar para o novo no
    (*lst)->info++;
    return 1;
}

int remove_elem(Lista *lst, int elem){
    if(lista_vazia(*lst) == 1)
        return 0;
    Lista aux = *lst;
    if(elem == (*lst)->info){
        *lst = aux->prox; // lista aponta para o 2 no
        free(aux);
        return 1;
    }
    // percorrimento at� achar o elem ou final de lista
    while(aux->prox != NULL && aux->prox->info != elem)
        aux = aux->prox;
    if(aux->prox == NULL)
        return 0;

    // remove o elem diferente do 1 no da lista
    Lista aux2 = aux->prox; // aponta para o no a ser removido
    aux->prox = aux2->prox; // retira o no da lista
    free(aux2);
    (*lst)->info--;
    return 1;
}


int obtem_valor_elem(Lista lst, int pos){
    int cont = 0;
    lst = lst->prox;

    if(lista_vazia(lst) == 1)
        return 0;
    for(lst; lst != NULL; lst = lst->prox){
        if(cont == pos){
            return lst->info;
        }
        cont++;
    }
}

void imprime_lista(Lista lst){
    if(lst == NULL){
        printf("Lista Inexistente");
    }
    lst = lst->prox;
    for(lst; lst != NULL; lst = lst->prox){
        printf("%d ", lst->info);
    }
}

void libera_lista(Lista *lst){
    free(*lst);
    *lst = NULL;
}


