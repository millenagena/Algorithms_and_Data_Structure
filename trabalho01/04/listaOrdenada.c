// ListaNaoOrdenaca.c

#include <stdio.h>
#include <stdlib.h>
#include "listaOrdenada.h"

struct no
{
  int info;
  struct no *prox;
};
typedef struct no *Lista;

Lista cria_lista()
{
  Lista cab;
  cab = (Lista)malloc(sizeof(struct no));
  if (cab != NULL)
  {
    cab->prox = NULL;
    cab->info = 0;
  }
  return cab;
}

int lista_vazia(Lista lst)
{
  if (lst->prox == NULL)
  {
    return 1; // lista vazia
  }
  else
  {
    return 0;
  }
}
/*
int lista_cheia(Lista lst)
{
  if (lst->fim == MAX)
  {
    return 1; // lista cheia
  }
  else
  {
    return 0; // lista nao cheia
  }
}
*/
int insere_ord(Lista *lst, int elemento)
{
  Lista N = (Lista)malloc(sizeof(struct no));
  if (N == NULL)
  {
    return 0; // Falha: Nó nao alocado
  }
  N->info = elemento;
  // if (lista_vazia(*lst) || elemento <= (*lst)->info)
  // {
  //   N->prox = *lst;
  //   *lst = N;
  //   return 1;
  // }
  Lista aux = *lst;
  while (aux->prox != NULL && aux->prox->info < elemento)
    aux = aux->prox;
  N->prox = aux->prox;
  aux->prox = N;
  (*lst)->info++;
  return 1;
}

int remove_ord(Lista *lst, int elemento)
{
  if (lista_vazia(*lst) == 1)
  {
    return 0; // falha
  }
  Lista aux = *lst;
  if (elemento == (*lst)->info)
  {
    *lst = aux->prox;
    free(aux);
    return 1;
  }
  while (aux->prox != NULL && aux->prox->info < elemento)
    aux = aux->prox;
  if (aux->prox == NULL || aux->prox->info > elemento)
    return 0;
  Lista aux2 = aux->prox;
  aux->prox = aux2->prox;
  free(aux2);
  (*lst)->info--;
  return 1;
}

int obtem_valor_elemento(Lista lst, int pos_elemento)
{
  if (lista_vazia(&lst))
  {
    return 9999;
  }
  int cont = 0;
  lst = lst->prox;
  if (lista_vazia(lst) == 1)
  {
    return 0; // falha
  }
  for (lst; lst != NULL; lst = lst->prox)
  {
    if (cont == pos_elemento)
    {
      return lst->info;
    }
    cont++;
  }
}

void imprime_lista(Lista lst)
{
  if (lista_vazia(&lst))
  {
    printf("\nLista vazia");
  }
  lst = lst->prox;
  printf("\n");
  for (lst; lst != NULL; lst = lst->prox)
  {
    printf("%d\t", lst->info);
  }
}

int tamanho(Lista lst)
{
  int tam = 0;
  if (lista_vazia(lst))
  {
    return tam;
  }
  tam = lst->info;
  return tam;
}

int media(Lista lst, double *med)
{
  int sum = 0;
  int tam = lst->info;
  if (lista_vazia(lst))
  {
    return 0;
  }
  lst = lst->prox;
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
  if (lst1->info != lst2->info)
    return 0;
  else
  {
    lst1 = lst1->prox;
    lst2 = lst2->prox;
    for (lst1, lst2; lst1 != NULL, lst2 != NULL;
         lst1 = lst1->prox, lst2 = lst2->prox)
    {

      if (lst1->info != lst2->info)
        return 0;
    }
    return 1;
  }
}

int intercala(Lista *lst1, Lista *lst2)
{
  int res;
  if (lista_vazia(*lst1) || lista_vazia(*lst2))
    return 0;
  *lst2 = (*lst2)->prox;
  Lista aux = *lst2;
  while (aux->prox != NULL)
  {
    res = insere_ord(lst1, aux->info);
    aux = aux->prox;
    if (res == 0)
      return 0;
  }
  if (aux->prox == NULL) // intercalando o ultimo elemento
    res = insere_ord(lst1, aux->info);
  return 1;
}

int insere_elemento(Lista lst, int elemento)
{
  Lista N = (Lista)malloc(sizeof(struct no));
  if (N == NULL)
  {
    return 0; // Falha: Nó nao alocado
  }
  N->info = elemento;
  N->prox = lst->prox;
  lst->prox = N;
  lst->info++;
  return 1;
}

int inverte(Lista lst1, Lista *lst2)
{
  int res;
  lst1 = lst1->prox;
  for (lst1; lst1 != NULL; lst1 = lst1->prox)
  {
    Lista N = (Lista)malloc(sizeof(struct no));
    if (N == NULL)
    {
      return 0;
    }
    res = insere_elemento(*lst2, lst1->info);
  }
  return 1;
}

int get_impares(Lista lst1, Lista *lst2)
{
  int res;
  lst1 = lst1->prox;
  for (lst1; lst1 != NULL; lst1 = lst1->prox)
  {
    if (lst1->info % 2 != 0)
    {
      res = insere_ord(lst2, lst1->info);
      if (res == 0)
        return 0;
    }
  }
  return 1;
}

void libera_lista(Lista **lst)
{
  free(*lst);
  *lst = NULL;
}