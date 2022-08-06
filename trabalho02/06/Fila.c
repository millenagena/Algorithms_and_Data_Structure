#include<stdio.h>
#include<stdlib.h>
#include"Fila.h"

struct no{
    int info;
    struct no *prox;
};

struct fila{
    struct no *ini;
    struct no *fim;
};

Fila cria_fila(){
    Fila f;
    f = (Fila) malloc(sizeof(struct fila));
    if(f != NULL){
        f->ini = NULL;
        f->fim = NULL;
    }
    return f;
}

int fila_vazia(Fila f){
    if(f->ini == NULL)
        return 1;
    else
        return 0;
}

int insere_fim(Fila f, int elem){
    struct no *N;
    N = (struct no *) malloc(sizeof(struct no));
    if(N == NULL){return 0;}
    N->info = elem;
    N->prox = NULL;
    if(fila_vazia(f)==1)
        f->ini = N;// ini aponta pro no se vazio
    else
        (f->fim)->prox = N; // ultimo no da fila aponta p novo no
    f->fim = N; // campo fim aponta para novo no
    return 1;
}

int remove_ini(Fila f, int *elem){
    if(fila_vazia(f)==1)
        return 0;
    struct no *aux = f->ini;
    *elem = aux->info;
    if(f->ini == f->fim) // se tem apenas um no
        f->fim = NULL;
    f->ini = aux->prox;
    free(aux);
    return 1;
}

int le_final(Fila f, int *elem){
    if(fila_vazia(f)==1)
        return 0;
    *elem = f->fim->info;
    return 1;
}

void imprime(Fila f){
    int elem_removido;
    Fila f2;
    f2 = cria_fila();

    while(f->ini != NULL){
        printf("%d ", f->ini->info);
        insere_fim(f2, f->ini->info);
        remove_ini(f, &elem_removido);
    }

    while(f2->ini != NULL){
        insere_fim(f, f2->ini->info);
        remove_ini(f2, &elem_removido);
    }

}
