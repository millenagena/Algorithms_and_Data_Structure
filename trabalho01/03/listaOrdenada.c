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
    return NULL;
}

int lista_vazia(Lista lst){
    if(lst == NULL)
        return 1;
    else
        return 0;
}

int insere_ord(Lista *lst, int elem){
    // aloca um novo no
    Lista N = (Lista) malloc(sizeof(struct no));
    if (N == NULL){
        return 0; // Nó nao alocado
    }
    N->info = elem;
    if (lista_vazia(*lst) == 1 || elem <= (*lst)->info){
        N->prox = *lst;
        *lst = N;
        return 1;
    }
    Lista aux = *lst;
    while (aux->prox != NULL && aux->prox->info < elem){
        aux = aux->prox;
    }
    N->prox = aux->prox;
    aux->prox = N;
    return 1;
}

int remove_ord(Lista *lst, int elem){
    if (lista_vazia(*lst) == 1 || elem < (*lst)->info){
        return 0; // falha
    }
    Lista aux = *lst;
    if (elem == (*lst)->info){
        *lst = aux->prox;
        free(aux);
        return 1;
    }

    while (aux->prox != NULL && aux->prox->info < elem){
        aux = aux->prox;
    }
    if(aux->prox == NULL || aux->prox->info > elem){
        return 0;
    }
    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    return 1;
}

int tamanho(Lista lst){
    int tam=0;
    for(lst; lst != NULL; lst = lst->prox)
        tam += 1;
    return tam;
}

int media(Lista lst, double *med){
    double soma=0;
    int tam=0;
       
    for(lst; lst != NULL; lst = lst->prox)
        soma += lst->info;
    
    tam = tamanho(lst);
    *med = soma/tam;
    
    printf("%lf", *med);
    return 1;
}

// double media(Lista lst){
//     double soma=0.0, med;

//     for(lst; lst != NULL; lst = lst->prox){
//         soma += lst->info;
//     }
//     int tam_lista = tamanho(lst);
//     med = soma/tam_lista;

//     printf("\n media: %lf\n", med);
//     return med;
// }



int igualdade(Lista *lst1, Lista *lst2){
    if(lista_vazia(*lst1) && lista_vazia(*lst2))
        return 1;
    if(lista_vazia(*lst1) || lista_vazia(*lst2))
        return 0;
    if(tamanho(*lst1) != tamanho(*lst2))
        return 0;
    else{
        for(*lst1, *lst2; *lst1 != NULL, *lst2 != NULL; 
            *lst1 = (*lst1)->prox, *lst2 = (*lst2)->prox){

            if((*lst1)->info != (*lst2)->info)
                return 0;
        }
        return 1;
    }    
}

int intercala(Lista *lst1, Lista *lst2){
    int res;
    if(lista_vazia(*lst1) || lista_vazia(*lst2))
        return 0;
    Lista aux = *lst2;
    while(aux->prox != NULL){
        res = insere_ord(lst1, aux->info);
        aux = aux->prox;
        if(res == 0)
            return 0;
    }
    if(aux->prox == NULL) // intercalando o ultimo elemento
        res = insere_ord(lst1, aux->info);
        return 1;
}

int inverte(Lista lst1, Lista *lst2){
    for(lst1; lst1 != NULL; lst1 = lst1->prox){
        Lista N = (Lista) malloc(sizeof(struct no));
        if(N == NULL){
            return 0;
        }
        N->info = lst1->info;
        N->prox = *lst2;
        *lst2 = N;
    }
    return 1;
}

int get_impares(Lista lst1, Lista *lst2){
    int res;
    for(lst1; lst1 != NULL; lst1 = lst1->prox){
        if(lst1->info % 2 != 0){
            res = insere_ord(lst2, lst1->info);
            if(res == 0)
                return 0;
        }
    }
    return 1;
}

void imprime_lista(Lista lst){
    for(lst; lst != NULL; lst = lst->prox){
        printf("%d ", lst->info);
    }
}

void libera_lista(Lista *lst){
    free(*lst);
    *lst = NULL;
    printf("\nLISTA LIBERADA");
}
