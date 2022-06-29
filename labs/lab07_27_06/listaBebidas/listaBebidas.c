#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include "listaBebidas.h"

struct Registro{
    char nome[20];
    int volume;
    float preco;
};
typedef struct Registro registro;

struct no{
    registro info;
    struct no *prox;
};

// Lista cria_lista(){
//     Lista cab;
//     cab = (Lista) malloc(sizeof(struct no));

//     if(cab != NULL){
//         cab->prox = NULL; // aponta pra NULL pra indicar que esta vazia
//         cab->info = 0; // guardar quantidade
//     }
// }

int lista_vazia(Lista lst){
    if(lst->prox == NULL){
        return 1;
    }else{
        return 0;
    }
}

int insere_registro(Lista *lst, char *nome, int vol, float preco){
    if(lst == NULL){
        return 0;
    }
    registro reg;
    strcpy(reg.nome, nome);
    reg.volume = vol;
    reg.preco = preco;

    // aloca um novo no
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL)
        return 0;
    N->info = reg;
    (*lst)->prox; // aponta para o 1 no atual da lista
    (*lst)->prox = N; // faz o no cabecalho apontar para o novo no

    //(*lst)->info++;
    return 1;
}

int apagar_ultimo_registro(Lista *lst){
    if(lista_vazia(*lst) == 1)
        return 0;
    Lista aux = *lst; // ponteiro aux para o 1 no

    // percorrimento ate achar o elem ou final da lista
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    Lista aux2 = aux->prox; // aponta para o no a ser removido
    aux->prox = aux2->prox; // retira o no da lista
    free(aux2);
    //(*lst)->info--;
    return 1;
}