#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include "listaNaoOrdenada.h"

int main()
{
    int op, res, elem, tam, tam_lista, pos;
    double med;
    Lista lst, lst2;

    do{
        system("CLS || clear");
        do{
            printf(" --- LISTAS DINAMICAS ENCADEADAS --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar lista\n");
            printf(" 2. Verificar lista vazia\n");
            printf(" 3. Inserir elemento no final\n");
            printf(" 4. Inserir elemento no inicio\n");
            printf(" 5. Inserir em posicao\n");
            printf(" 6. Remover elemento no inicio\n");
            printf(" 7. Remover em posicao\n");
            printf(" 8. Tamanho da lista\n");
            printf(" 9. Imprimir lista\n");
            printf(" 10. Maior elemento da lista\n");
            printf(" 11. Remover pares\n");
            printf(" 12. Libera lista\n");
            printf(" 13. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);
            if((op < 1) || (op > 13)) {
                printf("\n\n Opcao Invalida! Tente novamente...");
                getch();
                system("CLS || clear");
            }
        } while((op < 1) || (op > 13));

        switch(op){
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
                printf("\n\n Informe o elemento a ser inserido: ");
                scanf("%d", &elem);
                res = insere_final(&lst, elem);
                if(res == 1)
                    printf("\n\n Elemento inserido com sucesso");
                else
                    printf("\n\n Elemento nao inserido");

                getch();
                break;

            case 4:
                printf("\n\n Informe o elemento a ser inserido: ");
                scanf("%d", &elem);
                res = insere_inicio(&lst, elem);
                if(res == 1)
                    printf("\n\n Elemento inserido com sucesso");
                else
                    printf("\n\n Elemento nao inserido");
                getch();
                break;

            case 5:
                printf("\n\n Informe o elemento a ser inserido: ");
                scanf("%d", &elem);
                printf("\n\n Informe a posicao a ser inserida: ");
                scanf("%d", &pos);
                res = insere_pos(&lst, pos, elem);
                if(res == 1)
                    printf("\n\n Elemento inserido com sucesso");
                else
                    printf("\n\n Elemento nao inserido");
                getch();
                break;

            case 6:
                res = remove_inicio(&lst, &elem);
                if(res == 1)
                    printf("\n\n Elemento %d removido com sucesso", elem);
                else
                    printf("\n\n Elemento nao removido");
                getch();
                break;

            case 7:
                printf("\nInforme a posicao do elemento a ser removido: ");
                scanf("%d", &pos);
                res = remove_pos(&lst, &elem, pos);
                if(res == 1)
                    printf("\n\n Elemento %d removido com sucesso", elem);
                else
                    printf("\n\n Elemento nao removido");
                getch();
                break;

            case 8:
                tam = tamanho(lst);
                printf("\n\n O tamanho da lista eh: %d", tam);
                getch();
                break;

            case 9:
                printf("\n\n LISTA\n");
                imprime_lista(lst);
                getch();
                break;
            
            case 10:
                printf("\n\n MAIOR ELEMENTO DA LISTA: %d", maior(lst));
                getch();
                break;
            
            case 11:
                res = remove_pares(&lst);
                if(res == 1)
                    printf("\n\n Elementos pares removidos com sucesso");
                else
                    printf("\n\n Elementos nao removidos");
                getch();
                break;
            
            case 12:
                libera_lista(&lst);
                getch();
                break;

            default:
				printf("\n\n Pressione qualquer tecla para FINALIZAR...");
				getch();
        }
    } while(op != 13);

    return 0;
}
