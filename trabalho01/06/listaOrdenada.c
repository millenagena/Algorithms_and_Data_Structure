#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listaOrdenada.h"

struct no
{
    int info;
    struct no *prox;
    struct no *ant;
};
typedef struct no *Lista;

Lista cria_lista()
{
    return NULL;
}

int lista_vazia(Lista lst)
{
    if (lst == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int insere_ord(Lista *lst, int elem)
{
    Lista N = (Lista)malloc(sizeof(struct no));
    if (N == NULL)
    {
        return 0;
    }
    N->info = elem;
    // trata lista vazia e menor que primeiro elem
    if (lista_vazia(*lst) == 1 || elem < (*lst)->info)
    {
        N->ant = NULL;
        N->prox = *lst;
        if (lista_vazia(*lst) == 0)
        {
            (*lst)->ant = N;
        }
        *lst = N;
    }
    else
    { // trata elem maior que o primeiro
        Lista aux = *lst;
        while (aux->prox != NULL && aux->prox->info < elem)
            aux = aux->prox;
        if (aux->prox == NULL) // trata elem maior que ultimo
            N->prox = NULL;
        else
        { // trata elem inserido no meio de outros elementos
            N->prox = aux->prox;
            aux->prox->ant = N;
        }
        aux->prox = N;
        N->ant = aux;
    }
    return 1;
}

int remove_ord(Lista *lst, int elem)
{
    if (lista_vazia(*lst) == 1 || elem < (*lst)->info)
        return 0;

    Lista aux = *lst; // aponta primeiro elemento
    if (elem == aux->info)
    {
        aux->prox->ant = NULL;
        *lst = aux->prox;
        aux->prox = NULL; // teste
        free(aux);
    }
    else
    {
        while (aux->prox != NULL && aux->prox->info < elem)
            aux = aux->prox;
        Lista aux2 = aux->prox; // aponta pro elem a ser removido
        if (aux2->prox == NULL && aux2->info == elem)
        { // trata ultimo elemento
            aux->prox = NULL;
            aux2->ant = NULL; // teste
            free(aux2);
        }
        else
        {
            if (aux2 == NULL)
                return 0;
            if (aux2->info != elem) // elem nao esta na lista
                return 0;
            aux->prox = aux2->prox;
            aux->prox->ant = aux;
            free(aux2);
        }
    }
    return 1;
}

int obtem_valor_elem(Lista lst, int pos, int *elem)
{
    int cont = 0;
    if (lista_vazia(lst) == 1)
        return 0;
    for (lst; lst != NULL; lst = lst->prox)
    {
        if (cont == pos)
        {
            *elem = lst->info;
            return 1;
        }
        cont++;
    }
}

void imprime_lista(Lista lst)
{
    if (lista_vazia(lst) == 1)
        printf("Lista vazia!");
    for (lst; lst != NULL; lst = lst->prox)
    {
        printf("%d ", lst->info);
    }
}

int tamanho(Lista lst, int *tam)
{
    int tam_aux = 0;
    if (lista_vazia(lst))
    {
        return 0;
    }
    for (lst; lst != NULL; lst = lst->prox)
    {
        tam_aux++;
    }
    *tam = tam_aux;
    return 1;
}

int media(Lista lst, double *med)
{
    int sum = 0;
    int tam;
    int flag_tam = tamanho(lst, &tam);
    if (lista_vazia(lst))
    {
        return 0;
    }
    for (lst; lst != NULL; lst = lst->prox)
    {
        sum = sum + lst->info;
    }
    *med = (double)sum / tam;
    return 1;
}

int igualdade(Lista lst1, Lista lst2)
{
    if (lst1 == NULL && lst2 == NULL)
        return 1;

    int tam1, tam2;
    int flag_tam1 = tamanho(lst1, &tam1);
    int flag_tam2 = tamanho(lst2, &tam2);
    if (tam1 != tam2)
        return 0;
    else
    {
        for (lst1, lst2; lst1 != NULL, lst2 != NULL;
             lst1 = lst1->prox, lst2 = lst2->prox)
        {

            if (lst1->info != lst2->info)
                return 0;
        }
        return 1;
    }
}

int remove_todos(Lista *lst, int elemento_repetido)
{
    if (lista_vazia(*lst) == 1)
        printf("Lista vazia!");
    int flag_remove, cont = 0;
    Lista aux = *lst;
    for (aux; aux != NULL; aux = aux->prox)
    {
        if (aux->info == elemento_repetido)
        {
            cont++;
        }
    }
    printf("\nO elemento %d aparece %d vezes", elemento_repetido, cont);
    for (int i = 0; i < cont; i++)
    {
        flag_remove = remove_ord(lst, elemento_repetido);
        if (flag_remove == 0)
        {
            return 0;
        }
    }
    return 1;
}

int maior(Lista lst, int *valor_maior)
{
    if (lista_vazia(lst) == 1)
        return 0;

    int aux_maior = lst->info;
    for (lst; lst != NULL; lst = lst->prox)
    {
        if (lst->info > aux_maior)
            aux_maior = lst->info;
    }
    *valor_maior = aux_maior;
    return 1;
}

int remove_maior(Lista *lst, int maior_elemento)
{
    if (lista_vazia(lst) == 1)
        return 0;
    int flag_remove_todos, flag_maior;
    flag_remove_todos = remove_todos(lst, maior_elemento);
    if (flag_remove_todos == 0)
    {
        return 0;
    }
    return 1;
}

int get_mult_3(Lista lst1, Lista *lst2)
{
    int res;
    for (lst1; lst1 != NULL; lst1 = lst1->prox)
    {
        if (lst1->info % 3 == 0)
        {
            res = insere_ord(lst2, lst1->info);
            if (res == 0)
                return 0;
        }
    }
    return 1;
}