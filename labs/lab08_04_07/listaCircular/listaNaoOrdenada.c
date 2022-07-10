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
    return NULL;
}

int lista_vazia(Lista lst){
    if(lst == NULL)
        return 1;
    else
        return 0;
}

int insere_final(Lista *lst, int elem){
    // aloca um novo no e preenche o campo info
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL){ return 0; }
    N->info = elem;

    // trata lista vazia
    if(lista_vazia(*lst) == 1){
        N->prox = N; // faz o novo no apontar pra ele mesmo
        *lst = N; // faz a lista apontar para o novo no (ultimo no)
    }
    // trata lista com 1 ou + elementos
    else{
        N->prox = (*lst)->prox; // faz o novo no apontar para o primeiro no
        (*lst)->prox = N; // faz o ultimo no apontar para o novo no
        *lst = N; // faz a lista apontar para o novo no (ultimo no)
    }
    return 1;
}

int insere_inicio(Lista *lst, int elem){
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL){ return 0; }
    N->info = elem;

    // trata lista vazia
    if(lista_vazia(*lst) == 1){
        N->prox = N;
        *lst = N;
    }
    // trata lista com 1 ou + elementos
    else{
        N->prox = (*lst)->prox;
        (*lst)->prox = N;
    }
    return 1;
}

int remove_inicio(Lista *lst, int *elem){
    // trata lista vazia
    if(lista_vazia(*lst) == 1)
        return 0;
    Lista aux = (*lst)->prox; // faz aux apontar para o 1 no
    *elem = aux->info; // retorna o valor do nó a ser removido
    if(*lst == (*lst)->prox) // trata lista com 1 unico no
        *lst = NULL;
    else // trata lista com + de 1 elemento
        (*lst)->prox = aux->prox;
    free(aux);
    return 1;
}

int remove_final(Lista *lst, int *elem){
    // trata lista vazia
    if(lista_vazia(*lst) == 1)
        return 0;
    Lista aux = (*lst)->prox; // faz aux apontar para o 1 no
    Lista aux2 = *lst;
    *elem = (*lst)->info; // retorna o valor do no a ser removido;
    if(*lst == (*lst)->prox) // trata lista com 1 unico no
        *lst = NULL;
    else{ // trata lista com mais de um elemento
        while(aux->prox != (*lst)) // percorrendo ate o ultimo elemento
            aux = aux->prox;
        aux->prox = (*lst)->prox; // penultimo elem aponta para primeiro elem
        *lst = aux;
    }
    free(aux2);
    return 1;
}

int obtem_valor_elem(Lista lst, int pos, int *elem){
    int cont=0;
    lst = lst->prox;

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
    if(lista_vazia(lst))
        printf("\nLISTA VAZIA!");
    else{
        Lista aux = lst->prox;
        while(aux != lst){ // printando do primeiro ao penultimo elemento
            printf("%d ", aux->info);
            aux = aux->prox;
        }
        printf("%d", aux->info); // printando o ultimo elemento
    }
}

void libera_lista(Lista *lst){
    if(lista_vazia(*lst))
        printf("\nLISTA VAZIA");
    else{
        Lista aux = (*lst)->prox;
        Lista aux2;
        
        while(aux != (*lst)){ // percorrendo a lista
            aux2 = aux;
            aux = aux->prox;
            free(aux2);
        }
        free(aux); // liberando o ultimo no
        *lst = NULL;
        printf("\nLISTA LIBERADA");
    }
}

