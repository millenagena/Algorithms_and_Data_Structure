#include <stdio.h>
#include <stdlib.h>
#include "listaNaoOrdenada.h"

int main()
{
  int op;
  Lista *lst;

  do
  {
    do
    {
      printf("\n --- LISTAS ESTATICAS SEQUENCIAIS --- \n\n");
      printf(" Escolha uma opcao\n");
      printf(" 1. Criar lista\n");
      printf(" 2. Verificar lista vazia\n");
      printf(" 3. Verificar lista cheia\n");
      printf(" 4. Inserir elemento\n");
      printf(" 5. Remover elemento\n");
      printf(" 6. Liberar lista\n");
      printf(" 7. Obter valor de um elemento\n");
      printf(" 8. Imprimir lista\n");
      printf(" 9. Remover impares\n");
      printf(" 10. Menor elemento\n");
      printf(" 11. Tamanho da lista\n");
      printf(" 12. Ordena lista\n");
      printf(" 13. Concatena\n");
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
      lst = inicializa_lista();
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

    case 3:
      printf("\n\n Ver se lista esta cheia");
      int flag2 = lista_cheia(lst);
      if (flag2 == 1)
      {
        printf("\nLista cheia");
      }
      if (flag2 == 0)
      {
        printf("\nLista nao cheia");
      }
      break;

    case 4:
      printf("\n\n Inserir elemento");
      int elem;
      printf("\n Qual elemento deseja inserir: ");
      scanf("%d", &elem);
      int flag3 = insere_elemento(lst, elem);
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
      int flag4 = remove_elemento(lst, elem2);
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
      printf("\n\n Remove impares");

      int flag9 = remove_impares(lst);
      if (flag9 == 1)
      {
        printf("\n Impares removido com sucesso");
      }
      if (flag9 == 0)
      {
        printf("\nFalha na remocao");
      }
      break;

    case 10:
      printf("\n\n Menor elemento");
      int menor = menor_elemento(lst);
      printf("\n Menor elemento: %d", menor);
      break;

    case 11:
      printf("\n\n Tamano da lista");
      int tamanho_lista = tamanho(lst);
      printf("\n Tamanho lista: %d", tamanho_lista);
      break;

    case 12:
      printf("\n\n ORDENA LISTA");
      int flag12 = ordena_lista(lst);
      if (flag12 == 1)
      {
        printf("\n Sucesso");
      }
      if (flag12 == 0)
      {
        printf("\nFalha");
      }
      break;

    case 13:
      printf("\n\n Concatena");
      // int flag13 = concatena(lst);
      // if (flag13 == 1)
      // {
      //   printf("\n Sucesso");
      // }
      // if (flag13 == 0)
      // {
      //   printf("\nFalha");
      // }
      break;

    default:
      printf("\n\n Pressione qualquer tecla para FINALIZAR...");
    }
  } while (op != 20);

  return 0;
}