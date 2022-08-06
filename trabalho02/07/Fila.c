#include<stdio.h>
#include<stdlib.h>
#include"Fila.h"

struct no{
    int info;
    struct no *prox;
};

Fila cria_fila(){
    return NULL;
}

int fila_vazia(Fila f){
    if(f == NULL)
        return 1;
    else
        return 0;
}

int insere_fim(Fila *f, int elem){
    struct no *N;
    N = (struct no *) malloc(sizeof(struct no));
    if(N == NULL){return 0;}
    N->info = elem;
    if(fila_vazia(*f)==1)
        N->prox = N;
    else{
        N->prox = (*f)->prox;
        (*f)->prox = N;
    }
    (*f) = N;
    return 1;
}

int remove_ini(Fila *f, int *elem){
    if(fila_vazia(*f)==1)
        return 0;
    Fila aux = (*f)->prox;
    *elem = aux->info;
    if(*f == (*f)->prox) // se tem apenas um no
        *f = NULL;
    else
        (*f)->prox = aux->prox;
    free(aux);
    return 1;
}

int le_final(Fila f, int *elem){
    if(fila_vazia(f)==1)
        return 0;
    *elem = f->info;
    return 1;
}

void imprime(Fila *f){
    int elem_removido;
    Fila f2;
    
    f2 = cria_fila();

    while((*f)->prox != *f){
        printf("%d ", (*f)->prox->info);
        insere_fim(&f2, (*f)->prox->info);
        remove_ini(f, &elem_removido);
    }
    // removendo o ultimo elemento
    printf("%d ", (*f)->prox->info);
    insere_fim(&f2, (*f)->prox->info);
    remove_ini(f, &elem_removido);

    while(f2->prox != f2){
        insere_fim(f, f2->prox->info);
        remove_ini(&f2, &elem_removido);
    }
    // inserindo o ultimo elemento
    insere_fim(f, f2->prox->info);
    remove_ini(&f2, &elem_removido);
}

