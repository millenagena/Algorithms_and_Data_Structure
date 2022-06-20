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
typedef struct no *Lista;

Lista cria_lista() {
    return NULL;
}

int lista_vazia(Lista *lst) {
    if(lst == NULL)
        return 1;
    else
        return 0;
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
    N->prox = *lst;
    *lst = N;
    return 1;
}

int apagar_ultimo_registro(Lista *lst){
    if(lista_vazia(lst) == 1)
        return 0;
    Lista aux = *lst; // ponteiro aux para o 1 no

    // percorrimento ate achar o elem ou final da lista
    while(aux->prox != NULL){
        aux = aux->prox;
    }

    Lista aux2 = aux->prox; // aponta o no a ser removido
    aux->prox = aux2->prox; // retira no da lista
    free(aux2); // libera memoria alocada
    return 1;

}

void imprime_tabela(Lista lst){
    printf("Tabela de bebidas: {");
    for(lst; lst != NULL; lst = lst->prox){
        printf("\n Nome bebida: %s -", lst->info.nome);
        printf(" Volume: %d -", lst->info.volume);
        printf(" Preco: %.2f", lst->info.preco);
    }
    printf("}");
}

void libera_lista(Lista *lst){
    free(*lst);
    *lst = NULL;
}