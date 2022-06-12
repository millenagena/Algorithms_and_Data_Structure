#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "listaNaoOrdenada.h"

#define max 20
struct lista {
    int no[max];
    int Fim;
};
typedef struct lista Lista;

Lista* cria_lista() {
    Lista *list;
    list = (Lista*) malloc(sizeof(struct lista));

    if(list != NULL) {
        list->Fim = 0;
    }
    return list;
}

int lista_vazia(Lista *lst) {
    if(lst->Fim == 0){
        return 1; // lista vazia
    }else{
        return 0; // lista NAO vazia
    }
}

int lista_cheia(Lista *lst){
    if(lst->Fim == max) {
        return 1; // lista cheia
    }else{
        return 0; // lista NAO cheia
    }
}

int insere_elem(Lista *lst, int elem){
    if(lst == NULL || lista_cheia(lst) == 1){
        return 0;
    }
    lst->no[lst->Fim] = elem; // insere elem
    lst->Fim++; // incrementa o Fim
    return 1;
}

int remove_elem(Lista *lst, int elem){
    if(lst == NULL || lista_vazia(lst) == 1){
        return 0; // Falha
    }
    int i, aux=0;

    // percorrendo ate achar o elem ou final da lista
    while(aux<lst->Fim && lst->no[aux] != elem){
        aux++;
        if(aux == lst->Fim){
            return 0;
        }
    }

    // deslocamento a esquerda
    for(i=aux+1; i<lst->Fim; i++){
        lst->no[i-1] = lst->no[i];
    }
    lst->Fim--;
    return 1;
}

int obtem_valor_elem(Lista *lst, int pos){
    if(lst == NULL || lista_vazia(lst) == 1){
        return 0; // Falha
    }
    for(int i=0; i<lst->Fim; i++){
        if(i == pos){
            return lst->no[i];
        }
    }
}

void imprime_lista(Lista *lst){
    if(lst == NULL || lista_vazia(lst) == 1){
        printf("\n Lista nula ou sem registros");
    }else{
        for(int i=0; i<lst->Fim; i++){
            printf("%d ", lst->no[i]);
        }
    }
}

void libera_lista(Lista **lst){
    free(*lst);
    *lst = NULL;
}





