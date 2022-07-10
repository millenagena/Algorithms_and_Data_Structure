#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#include "listaNaoOrdenada.h"

struct lista
{
  int arr[MAX];
  int fim;
};
typedef struct lista Lista;

Lista *inicializa_lista()
{
  Lista *lst;
  lst = (Lista *)malloc(sizeof(Lista));

  if (lst != NULL)
  {
    lst->fim = 0; // lista vazia
  }
  return lst;
}

int lista_vazia(Lista *lst)
{
  if (lst->fim == 0)
  {
    return 1; // lista vazia
  }
  else
  {
    return 0; // lista nao vazia
  }
}

int tamanho(Lista *lst)
{
  if (lst == NULL)
  {
    return 0; // erro
  }
  int tam = lst->fim;

  return tam; // sucesso
}

int lista_cheia(Lista *lst)
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

int insere_elemento(Lista *lst, int elemento)
{
  if (lst == NULL || lista_cheia(lst) == 1)
  {
    return 0; // falha na insercao
  }
  lst->arr[lst->fim] = elemento;
  lst->fim++;
  return 1; // sucesso na insercao
}

int remove_elemento(Lista *lst, int elem)
{
  if (lst == NULL || lista_vazia(lst) == 1)
  {
    return 0; // Falha
  }
  int i, aux = 0;

  // percorrendo ate achar o elem ou final da lista
  while (aux < lst->fim && lst->arr[aux] != elem)
    aux++;
  if (aux == lst->fim)
    return 0;

  // deslocamento a esquerda
  for (i = aux + 1; i < lst->fim; i++)
    lst->arr[i - 1] = lst->arr[i];
  lst->fim--;
  return 1;
}

int remove_impares(Lista *lst)
{
  if (lst == NULL || lista_vazia(lst) == 1)
  {
    return 0; // falha na remocao
  }
  for (int i = 0; i <= lst->fim; i++)
  {
    if (lst->arr[i] % 2 != 0) // numero impar
    {
      remove_elemento(lst, lst->arr[i]);
    }
  }
  return 1; // sucesso
}

int concatena(Lista *lst1, Lista *lst2)
{
  if (lst1 == NULL || lista_vazia(lst1) == 1 || lst2 == NULL || lista_vazia(lst2) == 1)
  {
    return 0; // falha na remocao
  }
  if (lst1->fim + lst2->fim >= MAX)
  {
    return 0; // lista nao suporta concatenacao
  }

  for (int i = 0; i < lst2->fim; i++)
  {
    insere_elemento(lst1, lst2->arr[i]);
  }
}

int ordena_lista(Lista *lst)
{
  if (lst == NULL || lista_vazia(lst) == 1)
  {
    return 0; // falha
  }
  Lista *lst_aux;
  lst_aux = inicializa_lista();
  int menor, flag;
  int qty_elem = lst->fim;
  for (int i = 0; i < qty_elem; i++)
  {
    menor = menor_elemento(lst);
    flag = insere_elemento(lst_aux, menor);
    flag = remove_elemento(lst, menor);
  }
  *lst = *lst_aux;
  libera_lista(&lst_aux);
  return 1; // sucesso
}

int obtem_valor_elemento(Lista *lst, int pos_elemento)
{
  if (lst == NULL && pos_elemento > MAX)
  {
    return 0; // falha
  }

  for (int i = 0; i < MAX; i++)
  {
    if (i == pos_elemento)
    {
      return lst->arr[i];
    }
  }
}

void imprime_lista(Lista *lst)
{
  if (lst == NULL)
  {
    printf("\nLista nao existe");
  }
  else
  {
    for (int i = 0; i < lst->fim; i++)
    {
      printf("\n%d", lst->arr[i]);
    }
  }
}

int menor_elemento(Lista *lst)
{
  if (lst == NULL || lista_vazia(lst) == 1)
  {
    return 0; // erro
  }
  int menor = lst->arr[0];
  for (int i = 0; i < lst->fim; i++)
  {
    if (lst->arr[i] < menor)
    {
      menor = lst->arr[i];
    }
  }
  return menor; // sucesso
}

void libera_lista(Lista **lst)
{
  free(*lst);
  *lst = NULL;
}