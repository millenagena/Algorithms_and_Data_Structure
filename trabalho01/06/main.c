#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listaOrdenada.h"

int main()
{
    int op, elem, res, pos, tam, elemento_repetido, maior_valor;
    double med;
    Lista lst, lst2;
    do
    {
        do
        {
            printf("\n --- LISTAS DINAMICAS DUPLAMENTE ENCADEADAS --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar lista\n");
            printf(" 2. Verificar lista vazia\n");
            printf(" 3. Inserir elemento\n");
            printf(" 4. Excluir elemento\n");
            printf(" 5. Imprimir lista\n");
            printf(" 6. Obter valor do elemento\n");
            printf(" 7. Liberar lista\n");
            printf(" 8. Tamanho da lista\n");
            printf(" 9. media da lista\n");
            printf(" 10. verificar 2 listas iguais\n");
            printf(" 11. Remover todas ocorrencias de um mesmo elemento\n");
            printf(" 12. Remover todas ocorrencias de do maior elemento\n");
            printf(" 13. Multiplos de 3\n");
            printf(" 20. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);
            if ((op < 1) || (op > 20))
            {
                printf("\n\n Opcao Invalida! Tente novamente...");
            }
        } while ((op < 1) || (op > 20));

        switch (op)
        {
        case 1:
            lst = cria_lista();
            printf("\n\n Lista criada com sucesso!");
            break;

        case 2:
            res = lista_vazia(lst);
            if (res == 1)
                printf("\n\n Lista vazia");
            else
                printf("\n\n Lista nao vazia");
            break;

        case 3:
            printf("\n\n Informe o elemento a ser inserido: ");
            scanf("%d", &elem);
            res = insere_ord(&lst, elem);
            if (res == 1)
                printf("\n\n Elemento inserido com sucesso");
            else
                printf("\n\n Elemento nao inserido");

            break;

        case 4:
            printf("\n\n Informe o elemento a ser removido: ");
            scanf("%d", &elem);
            res = remove_ord(&lst, elem);
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
            printf("\n Informe a posicao do elemento: ");
            scanf("%d", &pos);
            res = obtem_valor_elem(lst, pos, &elem);
            if (res == 1)
                printf("\n\n O elemento na posicao %d eh: %d", pos, elem);
            else
                printf("\n\n Elemento nao encontrado");
            break;

        case 7:

            break;

        case 8:
            res = tamanho(lst, &tam);
            if (res == 1)
            {
                printf("\ntamanho da lista eh: %d", tam);
            }
            else
            {
                printf("\nLista vazia ou nao existe");
            }
            break;

        case 9:
            res = media(lst, &med);
            if (res == 1)
            {
                printf("\nmedia da lista eh: %.2lf", med);
            }
            else
            {
                printf("\nerro ao calcular a media, lista pode estar vazia ou nao existir");
            }
            break;

        case 10:
            lst2 = cria_lista();
            int tam_lista;
            int flag10;
            printf("\nQual o tamanho da lista? ");
            scanf("%d", &tam_lista);
            for (int i = 0; i < tam_lista; i++)
            {
                printf("\nInforme o elemento %d: ", i + 1);
                scanf("%d", &elem);
                flag10 = insere_ord(&lst2, elem);
            }
            flag10 = igualdade(lst, lst2);
            if (flag10 == 1)
                printf("\nLISTAS IGUAIS");
            else
                printf("\nLISTAS DIFERENTES");
            break;

        case 11:
            printf("\nQual o elemento: ");
            scanf("%d", &elemento_repetido);
            int flag11 = remove_todos(&lst, elemento_repetido);
            if (flag11 == 1)
                printf("\nSucesso");
            else
                printf("\nFalha");
            break;

        case 12:
            res = maior(lst, &maior_valor);
            if (res == 0)
                printf("\nFalha ao encontrar maior elemento");
            res = remove_maior(&lst, maior_valor);
            if (res == 1)
                printf("\nSucesso");
            else
                printf("\nFalha");
            break;

        case 13:
            lst2 = cria_lista();
            res = get_mult_3(lst, &lst2);
            if (res == 1)
            {
                printf("\nNUMEROS MULTIPLOS DE 3 DA LISTA:\n");
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