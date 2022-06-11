#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "listaNaoOrdenada.h"


int main()
{
    int op, res, elem, pos;
    Lista *lst;

    do{
        system("CLS || clear");
        do{
            printf(" --- LISTAS ESTATICAS SEQUENCIAIS --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar lista\n");
            printf(" 2. Verificar lista vazia\n");
            printf(" 3. Verificar lista cheia\n");
            printf(" 4. Inserir elemento\n");
            printf(" 5. Excluir elemento\n");
            printf(" 6. Imprimir lista\n");
            printf(" 7. Obter valor do elemento\n");
            printf(" 8. Liberar lista\n");
            printf(" 9. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);
            if((op < 1) || (op > 9)) {
                printf("\n\n Opcao Invalida! Tente novamente...");
                getch();
                system("CLS || clear");
            }
        } while((op < 1) || (op > 9));

        switch(op)
        {
            case 1:
                lst = cria_lista();
                printf("\n\n Lista criada com sucesso");
                getch();
                break;

            case 2:
                res = lista_vazia(lst);
                if(res == 1)
                    printf("\n\n Lista vazia");
                else
                    printf("\n\n Lista nao vazia");
                getch();
                break;

            case 3:
                res = lista_cheia(lst);
                if(res == 1)
                    printf("\n\n Lista cheia");
                else
                    printf("\n\n Lista nao cheia");
                getch();
                break;

            case 4:
                printf("\n\n Informe o elemento a ser inserido: ");
                scanf("%d", &elem);
                res = insere_elem(lst, elem);
                if(res == 1)
                    printf("\n\n Elemento inserido com sucesso");
                else
                    printf("\n\n Elemento nao inserido");

                getch();
                break;

            case 5:
                printf("\n\n Informe o elemento a ser removido: ");
                scanf("%d", &elem);
                res = remove_elem(lst, elem);
                if(res == 1)
                    printf("\n\n Elemento removido com sucesso");
                else
                    printf("\n\n Elemento nao removido");
                getch();
                break;

            case 6:
                printf("\n\n LISTA\n");
                imprime_lista(lst);
                getch();
                break;

            case 7:
                printf("\n\n Informe a posicao desejada: ");
                scanf("%d", &pos);
                elem = obtem_valor_elem(lst, pos);
                printf("\n O elemento na posicao %d eh: %d", pos, elem);
                getch();
                break;

            case 8:
                libera_lista(&lst);
                printf("\n\nLISTA LIBERADA");
                break;

            default:
				printf("\n\n Pressione qualquer tecla para FINALIZAR...");
				getch();
        }
    } while(op != 9);

    return 0;
}
