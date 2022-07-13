#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "Pilha.h"

#define max 20
struct pilha{
    int vet[max];
    int topo;
};

Pilha cria_pilha(){
    Pilha p;
    p = (Pilha) malloc(sizeof(struct pilha));
    if(p != NULL)
        p->topo = -1;
    return p;
}

int pilha_vazia(Pilha p){
    if(p->topo == -1)
        return 1;
    else
        return 0;
}

int pilha_cheia(Pilha p){
    if(p->topo == max-1)
        return 1;
    else
        return 0;
}

int push(Pilha p, int elem){
    if(p==NULL || pilha_cheia(p)==1)
        return 0;
    // insere o elem no topo
    p->topo++;
    p->vet[p->topo] = elem;
    return 1;
}

int pop(Pilha p, int *elem){
    if(p==NULL || pilha_vazia(p))
        return 0;
    *elem = p->vet[p->topo];
    p->topo--;
    return 1;
}

int le_topo(Pilha p, int *elem){
    if(p==NULL || pilha_vazia(p)==1)
        return 0;
    *elem = p->vet[p->topo]; // retorna o elemento
    return 1;
}

