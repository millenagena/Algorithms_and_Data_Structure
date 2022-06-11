#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>
#include "listaNoOrdBebidas.h"

#define MAX 10

struct Registro{
    char nome[20];
    int volume;
    float preco;
};
typedef struct Registro registro;

struct listaBebidas{
    registro no[MAX];
    int fim;
};
typedef struct listaBebidas listaBebidas;

listaBebidas *cria_lista(){
    listaBebidas *lst;
    lst = (listaBebidas*) malloc(sizeof(listaBebidas));

    if(lst != NULL){
        lst->fim = 0;
    }
    return lst;
}

int lista_vazia(listaBebidas *lst){
    if(lst->fim == 0)
        return 1;
    else
        return 0;
}

int lista_cheia(listaBebidas *lst){
    if(lst->fim == MAX)
        return 1;
    else
        return 0;
}

int insere_registro(listaBebidas *lst, char *nome, int vol, float preco){
    registro reg;
    if(lst == NULL || lista_cheia(lst) == 1){
        return 0;
    }
    strcpy(reg.nome, nome);
    reg.volume = vol;
    reg.preco = preco;
    lst->no[lst->fim] = reg;
    lst->fim++;
    return 1;
}

int apagar_ultimo_registro(listaBebidas *lst){
    if(lst == NULL || lista_vazia(lst) == 1){
        return 0;
    }
    lst->fim--;
    return 1;
}

void imprime_tabela(listaBebidas *lst){
    if(lst == NULL || lista_vazia(lst) == 1){
        printf("\n Lista nula ou sem registros");
    }else{
        for(int i=0; i<lst->fim; i++){
            printf("\n Nome bebida: %s -", lst->no[i].nome);
            printf(" Volume: %d -", lst->no[i].volume);
            printf(" Preco: %.2f", lst->no[i].preco);
        }
    }
}

void libera_registros(listaBebidas **lst){
    free(*lst);
    *lst = NULL;
}

