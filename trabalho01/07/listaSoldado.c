#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"listaSoldado.h"
#define max 30

struct soldado{
    char nome[max];
};
typedef struct soldado soldado;

struct no{
    soldado info;
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

int insere_soldado(Lista *lst, char *nome){
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL){return 0;}

    soldado s;
    strcpy(s.nome, nome);
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
    num = 0 + rand() % (11 - 0); // sorteando numeros de 0 a 10
    return num;
}

int remove_soldado(Lista *lst, char *nome){
    if(lista_vazia(*lst))
        return 0;
    
    Lista aux2; // ponteiro para o elem a ser removido
    if(strcmp(nome, (*lst)->prox->info.nome)==0){ // se for o primeiro da lista
        aux2 = (*lst)->prox;
        (*lst)->prox = aux2->prox;
        free(aux2);
        return 1;
    }
    Lista aux = (*lst)->prox; // aponta pro primeiro elemento
    while(aux->prox != (*lst)){
        if(strcmp(nome, aux->prox->info.nome)==0){
            aux2 = aux->prox; // aponta pro elem a ser removido
            aux->prox = aux2->prox;
            free(aux2); // libera memoria
        }
        aux = aux->prox; // proximo elemento
    }
    if(strcmp(nome, aux->prox->info.nome)==0){
        aux2 = aux->prox; // aponta pro elem a ser removido (ultimo)
        aux->prox = aux2->prox; // aponta pro prox elem
        (*lst) = aux; // lista aponta para o penultimo elem
        free(aux2);
    }
    return 1;
}

void imprime_lista(Lista lst){
    if(lista_vazia(lst))
        printf("\nLISTA VAZIA!");
    Lista aux = lst->prox;
    while(aux != lst){ // printando do primeiro ao penultimo elemento
        printf("%s ", aux->info.nome);
        aux = aux->prox;
    }
    printf("%s", aux->info.nome); // printando o ultimo elemento
}

int inicia_cont_primeiro(Lista *lst){
    if(lista_vazia(*lst))
        return 0;

    Lista aux = (*lst)->prox; // selecionando o primeiro soldado
    Lista aux2;

    int num=0, tam, res;
    tam = tamanho(*lst);
    
    while(tam > 1){
        num = sorteia_num();
        for(int i=0; i < num; i++)
            aux = aux->prox;
        
        aux2 = aux->prox; // armazena o soldado dps do eliminado

        printf("\n\nNumero sorteado: %d", num);
        printf("\nSoldado eliminado: %s", aux->info.nome);

        res = remove_soldado(lst, aux->info.nome);
        if(res == 0){return 0;}
        aux = aux2;
        tam--;
    }
    printf("\n\n");
    printf("============");
    printf("\nSOLDADO SOBREVIVENTE: %s", aux->info.nome);
    printf("\n============");
    return 1;
}

int inicia_cont_aleatorio(Lista *lst){
    if(lista_vazia(*lst))
        return 0;

    int num=0, tam, res;
    tam = tamanho(*lst);

    Lista aux = (*lst)->prox; // selecionando o primeiro soldado
    Lista aux2;

    // sorteando um soldado para começar a partir do primeiro soldado
    num = sorteia_num();
    for(int i=0; i < num; i++)
        aux = aux->prox;
    printf("\n\nSOLDADO INICIAL: %s", aux->info.nome);
    
    while(tam > 1){
        num = sorteia_num();
        for(int i=0; i < num; i++)
            aux = aux->prox;
        
        aux2 = aux->prox; // armazena o soldado dps do eliminado

        printf("\n\nNumero sorteado: %d", num);
        printf("\nSoldado eliminado: %s", aux->info.nome);

        res = remove_soldado(lst, aux->info.nome);
        if(res == 0){return 0;}
        aux = aux2;
        tam--;
    }
    printf("\n\n");
    printf("============");
    printf("\nSOLDADO SOBREVIVENTE: %s", aux->info.nome);
    printf("\n============");
    return 1;
}

int inicia_cont_nome(Lista *lst, char nome[]){
    if(lista_vazia(*lst))
        return 0;

    int num=0, tam, res;
    tam = tamanho(*lst);

    Lista aux = (*lst)->prox; // selecionando o primeiro soldado
    if(strcmp(nome, aux->info.nome) != 0){
        while(aux->prox != (*lst)){
            if(strcmp(nome, aux->prox->info.nome)==0){
                aux = aux->prox;
                break;
            }
            aux = aux->prox; // proximo elemento
        }
        if(strcmp(nome, aux->prox->info.nome)==0){
            aux = aux->prox;
        }
    }

    printf("\n\nSOLDADO INICIAL: %s", aux->info.nome);
    
    Lista aux2;

    while(tam > 1){
        num = sorteia_num();
        for(int i=0; i < num; i++)
            aux = aux->prox;
        
        aux2 = aux->prox; // armazena o soldado dps do eliminado

        printf("\n\nNumero sorteado: %d", num);
        printf("\nSoldado eliminado: %s", aux->info.nome);

        res = remove_soldado(lst, aux->info.nome);
        if(res == 0){return 0;}
        aux = aux2;
        tam--;
    }
    printf("\n\n");
    printf("============");
    printf("\nSOLDADO SOBREVIVENTE: %s", aux->info.nome);
    printf("\n============");
    return 1;
}