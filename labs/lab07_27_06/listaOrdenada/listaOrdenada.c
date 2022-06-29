#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "listaOrdenada.h"

struct no{
    int info;
    struct no *prox;
};

Lista cria_lista(){
    // Aloca o no cabecalho
    Lista cab;
    cab = (Lista) malloc(sizeof(struct no));

    // Coloca a lista no estado de vazia
    if(cab != NULL){
        cab->prox = NULL;
        cab->info = 0; // OPCIONAL: guardar qntd
    }
    return cab; // se falhar vai retornar NULL
}

int lista_vazia(Lista lst){
    if(lst->prox == NULL){
        return 1;
    }else{
        return 0;
    }
}

int insere_ord(Lista *lst, int elem){
    // aloca um novo no
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL){
        return 0;
    }
    N->info = elem; // insere o conteudo (valor do elem)

    // percorrimento da lista
    Lista aux = *lst; // faz apontar para o no do cabecalho
    while(aux->prox != NULL && aux->prox->info < elem)
        aux = aux->prox;

    // insere novo no na lista
    N->prox = aux->prox;
    aux->prox = N;
    (*lst)->info++; // incrementa qntd de nos na lista
    return 1;
}

int remove_ord(Lista *lst, int elem){
    if(lista_vazia(*lst) == 1)
        return 0;
    Lista aux = *lst; // ponteiro auxiliar para no cabecalho

    // percorrimento ate o final da lista, achar elem ou no maior
    while(aux->prox != NULL && aux->prox->info < elem)
        aux = aux->prox;
    if(aux->prox == NULL || aux->prox->info > elem)
        return 0;
    
    // remove elemento da lista
    Lista aux2 = aux->prox; // aponta o no a ser removido
    aux->prox = aux2->prox; // retira o no da lista
    free(aux2); // libera memoria alocada
    (*lst)->info--; // decrementa qntd de nos na lista
    return 1;
}

int obtem_valor_elem(Lista lst, int pos){
    int cont = 0;
    lst = lst->prox;

    for(lst; lst != NULL; lst = lst->prox){
        if(cont == pos){
            return lst->info;
        }
        cont++;
    }
}

void imprime_lista(Lista lst){
    if(lst == NULL){
        printf("Lista Inexistente");
    }
    lst = lst->prox;
    for(lst; lst != NULL; lst = lst->prox){
        printf("%d ", lst->info);
    }
}

void libera_lista(Lista *lst){
    free(*lst);
    *lst = NULL;
}
