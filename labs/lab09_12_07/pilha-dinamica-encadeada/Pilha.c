#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "Pilha.h"

struct pilha{
    int info;
    struct pilha *prox;
};
typedef struct pilha *Pilha;

Pilha cria_pilha(){
    return NULL;
}

int pilha_vazia(Pilha p){
    if(p==NULL)
        return 1;
    else
        return 0;
}

int push(Pilha *p, int elem){
    Pilha N = (Pilha) malloc(sizeof(struct pilha));
    N->info = elem;
    if(N==NULL){return 0;}
    N->info = elem;
    N->prox = *p;
    *p = N;
    return 1;
}

int pop(Pilha *p, int *elem){
    if(pilha_vazia(*p)==1)
        return 0;
    Pilha aux = *p;
    *elem = aux->info;
    *p = aux->prox;
    free(aux);
    return 1;
}

int le_topo(Pilha *p, int *elem){
    if(pilha_vazia(*p)==1)
        return 0;
    *elem = (*p)->info;
    return 1;
}


