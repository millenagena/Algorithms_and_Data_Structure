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

int remove_pos(Lista *lst, int *elem, int pos){
    int cont=0;
    if(lista_vazia(*lst) == 1)// trata lista vazia
        return 0;
    
    Lista aux = (*lst)->prox; // faz aux apontar para o 1 no

    if(*lst == (*lst)->prox)// quando a lista tiver apenas um no
        *lst = NULL;
    // quando o elemento estiver na primeira posicao
    else if(pos == 0){
        *elem = aux->info;
        (*lst)->prox = aux->prox;
    }
    // quando a lista tiver mais de um elemento
    // else{
    //     while(cont == pos || aux != (*lst)){ // percorrendo ate o ultimo elemento
    //         aux = aux->prox;
    //         cont++;
    //     }
    //     if(cont == pos){

    //     }

    free(aux);
    return 1;

}

void imprime_lista(Lista lst){
    Lista aux = lst->prox;
    Lista aux2 = aux->prox;

    printf("%d ", aux->info);
    while(aux != aux2){
        printf("%d ", aux2->info);
        aux2 = aux2->prox;
    }
}

