#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listaOrdenada.h"

int main()
{
  int op, res, exp, coef, tam, tam_lista, valor_x;
  double med, resultado;
  Lista lst, lst2;

  do
  {
    do
    {
      printf("\n --- LISTAS DINAMICAS ENCADEADAS --- \n\n");
      printf(" Escolha uma opcao\n");
      printf(" 1. Inicializar polinomio\n");
      printf(" 2. Verificar lista vazia\n");
      printf(" 3. Inserir elemento\n");
      printf(" 4. Excluir elemento\n");
      printf(" 5. Imprimir lista\n");
      printf(" 6. Obter tamanho da lista\n");
      printf(" 7. Reinicializar polinomio\n");
      printf(" 8. Calcular valor do polinomio\n");
      printf(" 13. SAIR\n");
      printf(" Opcao: ");
      scanf("%d", &op);
      if ((op < 1) || (op > 13))
      {
        printf("\n\n Opcao Invalida! Tente novamente...");
      }
    } while ((op < 1) || (op > 13));

    switch (op)
    {
    case 1:
      lst = cria_lista();
      res = insere_ord(&lst, 0, 0);
      printf("\n\n Polinomio criado com sucesso");

      break;

    case 2:
      res = lista_vazia(lst);
      if (res == 1)
        printf("\n\n Lista vazia");
      else
        printf("\n\n Lista nao vazia");

      break;

    case 3:
      printf("\n\n Informe o coeficiente: ");
      scanf("%d", &coef);
      printf("\n\n Informe o expoente: ");
      scanf("%d", &exp);
      res = insere_ord(&lst, exp, coef);
      if (res == 1)
        printf("\n\n Elemento inserido com sucesso");
      else
        printf("\n\n Elemento nao inserido");

      break;

    case 4:
      printf("\n\n Informe o expoente a ser removido: ");
      scanf("%d", &exp);
      res = remove_ord(&lst, exp);
      if (res == 1)
        printf("\n\n Elemento removido com sucesso");
      else
        printf("\n\n Elemento nao removido");

      break;

    case 5:
      printf("\n\n LISTA\n");
      imprime_lista(lst);

      break;

    case 6:
      tam = tamanho(lst);
      printf("\n\n Tamanho da lista: %d", tam);

      break;

    case 7:
      libera_lista(&lst);
      lst = cria_lista();
      res = insere_ord(&lst, 0, 0);
      if (res == 1)
      {
        printf("\nPolinomio reinicializado");
      }
      else
      {
        printf("\nErro");
      }

      break;

    case 8:
      printf("\nQual o valor para X: ");
      scanf("%d", &valor_x);
      res = calcular_polinomio(lst, valor_x, &resultado);
      if (res == 1)
      {
        printf("\nResultado: %.2lf", resultado);
      }
      else
      {
        printf("\nErro");
      }

      break;

    case 9:

      break;

    case 10:

      break;

    case 11:

      break;

    default:
      printf("\n\n Pressione qualquer tecla para FINALIZAR...");
    }
  } while (op != 13);

  return 0;
}