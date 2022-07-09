#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//#include"listaSoldado.h"
#define max 30

struct soldado{
    char nome[max];
};
typedef struct soldado soldado;

struct no{
    soldado info;
    struct no *prox;
};
typedef struct no *Lista;

Lista cria_lista(){
    return NULL;
}

int lista_vazia(Lista lst){
    if(lst == NULL)
        return 1;
    else
        return 0;
}

int tamanho(Lista lst){
    int tam=0;
    Lista aux = lst->prox;

    if(lista_vazia(lst)) // trata lista vazia
        tam=0;
    else{ // percorre a lista
        for(aux; aux != lst; aux = aux->prox){
            tam++;
        }
        tam++; // contabilizando o ultimo elemento
    }
    return tam;
}

int insere_soldado(Lista *lst, soldado s){
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL){return 0;}
    N->info = s;

    // trata lista vazia
    if(lista_vazia(*lst)){
        N->prox = N;
        (*lst) = N;
    }
    else{
        N->prox = (*lst)->prox;
        (*lst)->prox = N;
    }
    return 1;
}

int sorteia_num(){
    int num;
    num = rand() % 10; // sorteando numeros de 0 a 10
    return num;
}

int remove_soldado(Lista *lst, soldado s){
    if(lista_vazia(*lst))
        return 0;
}

int inicia_cont_primeiro(Lista *lst){
    
    Lista aux_sold = (*lst); // selecionando o primeiro soldado

}