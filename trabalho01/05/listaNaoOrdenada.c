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

int tamanho(Lista lst){
    int tam=0;
    Lista aux = lst->prox;
    if(lista_vazia(lst))
        tam=0;
    else{
        tam = 1;
        for(aux; aux != lst; aux = aux->prox){
            tam++;
        }
    }
    return tam;
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

int insere_pos(Lista *lst, int pos, int elem){
    int cont=1, res;
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL){return 0;}
    N->info = elem;
    Lista aux = (*lst)->prox; // aponta para o primeiro elemento

    if(lista_vazia(*lst) || (pos == 0)){ // trata primeira posicao
        res = insere_inicio(lst, elem);
        if(res==0){return 0;}
    }
    else if(pos >= tamanho(*lst)){ // trata se a posicao for maior q a ultima posicao
        res = insere_final(lst, elem);
        if(res==0){return 0;}
    }
    else{
        while(aux->prox != (*lst) && cont < pos){
            aux = aux->prox;
            cont++;
        }
        N->prox = aux->prox;
        aux->prox = N;
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
    int cont=1;
    if(lista_vazia(*lst) == 1)// trata lista vazia
        return 0;
    
    // trata posicao maior que tamanho
    if(pos >= tamanho(*lst))
        return 0;
    
    Lista aux = (*lst)->prox; // faz aux apontar para o 1 no
    if(*lst == (*lst)->prox)// quando a lista tiver apenas um no
        *lst = NULL;
    // quando o elemento estiver na primeira posicao
    else if(pos == 0){
        *elem = aux->info;
        (*lst)->prox = aux->prox;
    }else{
        while(aux->prox != (*lst) && cont < pos){
            aux = aux->prox;
            cont++;
        }
        Lista aux2 = aux->prox;
        *elem = aux2->info;
        aux->prox = aux2->prox;
        if(aux2 == (*lst)){ // caso o elemento a ser removido seja o ultimo
            (*lst) = aux;
        }
        free(aux2);
    }
    return 1;
}

void imprime_lista(Lista lst){
    if(lista_vazia(lst))
        printf("\nLISTA VAZIA!");
    Lista aux = lst->prox;
    while(aux != lst){ // printando do primeiro ao penultimo elemento
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("%d", aux->info); // printando o ultimo elemento
}

int maior(Lista lst){
    Lista aux = lst->prox;
    int maior = aux->info;

    while(aux != lst){ // percorrendo a lista para encontrar o maior elemento
        if(aux->info > maior)
            maior = aux->info;
        aux = aux->prox;
    }
    if(aux->info > maior) // comparando com o ultimo elemento
        maior = aux->info;

    return maior;
}
