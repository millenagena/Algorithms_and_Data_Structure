#include<stdio.h>
#include<stdlib.h>
#include"Fila.h"

#define max 20
struct fila{
    int no[max];
    int ini, fim;
};

Fila cria_fila(){
    Fila f;
    f = (Fila) malloc(sizeof(struct fila));
    if(f != NULL){
        f->ini = 0;
        f->fim = 0;
    }
    return f;
}

int fila_vazia(Fila f){
    if(f->ini == f->fim)
        return 1;
    else
        return 0;
}

int fila_cheia(Fila f){
    if(f->ini == (f->fim+1)%max)
        return 1;
    else
        return 0;
}

int insere_fim(Fila f, int elem){
    if(fila_cheia(f)==1)
        return 0;
    // insere elemento no final
    f->no[f->fim] = elem;
    f->fim = (f->fim+1)%max; // incremento circular
    return 1;
}

int remove_ini(Fila f, int *elem){
    if(fila_vazia(f)==1)
        return 0;
    // remove elemento do inicio
    *elem = f->no[f->ini];
    f->ini = (f->ini+1)%max;
    return 1;
}

int le_final(Fila f, int *elem){
    if(fila_vazia(f)==1)
        return 0;
    *elem = f->no[f->fim-1];
    return 1;
}

void imprime(Fila f){
    int elem_removido;
    int tam = (f->fim-1) - f->ini;
    Fila f2 = cria_fila();

    for(int i=0; i<=tam; i++){
        printf("%d ", f->no[f->ini]);
        insere_fim(f2, f->no[f->ini]);
        remove_ini(f, &elem_removido);
    }

    if(fila_vazia(f2)==0){
        int tam2 = (f2->fim-1) - f2->ini;
        for(int i=0; i<=tam2; i++){
            insere_fim(f, f2->no[f2->ini]);
            remove_ini(f2, &elem_removido);
        }
    }
}
