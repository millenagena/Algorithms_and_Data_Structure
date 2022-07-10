
// main.c
#include <stdio.h>
#include <stdlib.h>
#include "listaOrdenada.h"

int main()
{
  int op;
  Lista lst, lst2;

  do
  {
    do
    {
      printf("\n --- LISTAS DINAMICA ENCADEADA NO CABECALHO --- \n\n");
      printf(" Escolha uma opcao\n");
      printf(" 1. Criar lista\n");
      printf(" 2. Verificar lista vazia\n");
      printf(" 4. Inserir elemento\n");
      printf(" 5. Remover elemento\n");
      printf(" 6. Liberar lista\n");
      printf(" 7. Obter valor de um elemento\n");
      printf(" 8. Imprimir lista\n");
      printf(" 9. Tamanho da lista\n");
      printf(" 10. Media da lista\n");
      printf(" 11. Verificar igualdade de 2 listas\n");
      printf(" 12. Intercala 2 listas\n");
      printf(" 13. Inverte lista\n");
      printf(" 14. Impares\n");
      printf(" 20. SAIR\n");
      printf(" Opcao: ");
      scanf("%d", &op);
      if ((op < 1) || (op > 20))
      {

        printf("\n\n Opcao Invalida! Tente novamente...");
        system("CLS || clear");
      }
    } while ((op < 1) || (op > 20));

    switch (op)
    {
    case 1:
      printf("\n\n Criar lista");
      lst = cria_lista();
      break;

    case 2:
      printf("\n\n Ver se lista esta vazia");
      int flag = lista_vazia(lst);
      if (flag == 1)
      {
        printf("\nLista vazia");
      }
      if (flag == 0)
      {
        printf("\nLista nao vazia");
      }
      break;

    case 4:
      printf("\n\n Inserir elemento");
      int elem;
      printf("\n Qual elemento deseja inserir: ");
      scanf("%d", &elem);
      int flag3 = insere_ord(&lst, elem);
      if (flag3 == 1)
      {
        printf("\n Elemento inserido com sucesso");
      }
      if (flag3 == 0)
      {
        printf("\nFalha na insercao");
      }
      break;

    case 5:
      printf("\n\n Qual elemento deseja remover: ");
      int elem2;
      scanf("%d", &elem2);
      int flag4 = remove_ord(&lst, elem2);
      if (flag4 == 1)
      {
        printf("\n Elemento removido com sucesso");
      }
      if (flag4 == 0)
      {
        printf("\nFalha na remocao");
      }
      break;

    case 6:
      printf("\n\n Liberar lista");
      libera_lista(&lst);
      break;

    case 7:
      printf("\n\n Qual posicao do elemento que deseja: ");
      int pos;
      scanf("%d", &pos);
      int elemento_desejado = obtem_valor_elemento(lst, pos);
      printf("elemento desejado: %d", elemento_desejado);
      break;

    case 8:
      printf("\n\n Imprimir lista");
      imprime_lista(lst);
      break;

    case 9:
      printf("\n\n Tamanho da lista");
      int tam = tamanho(lst);
      printf("\n Tamanho da lista: %d", tam);
      break;

    case 10:
      printf("\n\n Media da lista");
      double med;
      int flag10 = media(lst, &med);
      if (flag10 == 1)
      {
        printf("\n Media: %.3lf", med);
      }
      if (flag10 == 0)
      {
        printf("\nFalha na remocao");
      }
      break;

    case 11:
      lst2 = cria_lista();
      int tam_lista;
      int flag11;
      printf("\nQual o tamanho da lista? ");
      scanf("%d", &tam_lista);
      for (int i = 0; i < tam_lista; i++)
      {
        printf("\nInforme o elemento %d: ", i + 1);
        scanf("%d", &elem);
        flag11 = insere_ord(&lst2, elem);
      }
      flag11 = igualdade(lst, lst2);
      if (flag11 == 1)
        printf("\nLISTAS IGUAIS");
      else
        printf("\nLISTAS DIFERENTES");
      break;

    case 12:
      lst2 = cria_lista();
      printf("\nQual o tamanho da lista? ");
      int tam_lista2, flag12;
      scanf("%d", &tam_lista2);
      for (int i = 0; i < tam_lista2; i++)
      {
        printf("\nInforme o elemento %d: ", i + 1);
        scanf("%d", &elem);
        flag12 = insere_ord(&lst2, elem);
      }
      flag12 = intercala(&lst, &lst2);
      if (flag12 == 1)
        printf("\nLISTAS INTERCALADAS COM SUCESSO");
      else
        printf("\nFALHA NA INTERCALACAO");
      break;

    case 13:
      lst2 = cria_lista();
      int flag13 = inverte(lst, &lst2);
      if (flag13 == 1)
      {
        printf("\nLISTA INVERTIDA:\n");
        imprime_lista(lst2);
      }
      else
      {
        printf("\nFALHA NA INVERSAO");
      }
      break;

    case 14:
      lst2 = cria_lista();
      int flag14 = get_impares(lst, &lst2);
      if (flag14 == 1)
      {
        printf("\nNUMEROS IMPARES DA LISTA:\n");
        imprime_lista(lst2);
      }
      else
      {
        printf("\nFALHA");
      }
      break;

    default:
      printf("\n\n Pressione qualquer tecla para FINALIZAR...");
    }
  } while (op != 20);

  return 0;
}