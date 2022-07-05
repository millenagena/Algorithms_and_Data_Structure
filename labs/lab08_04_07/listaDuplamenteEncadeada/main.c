#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "listaOrdenada.h"

int main(){
    int op, elem, res;
    Lista lst;
    do{
        system("CLS || clear");
        do{
            printf(" --- LISTAS DINAMICAS DUPLAMENTE ENCADEADAS --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar lista\n");
            printf(" 2. Verificar lista vazia\n");
            printf(" 3. Inserir elemento\n");
            printf(" 4. Excluir elemento\n");
            printf(" 5. Imprimir lista\n");
            printf(" 6. Obter valor do elemento\n");
            printf(" 7. Liberar lista\n");
            printf(" 8. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);
            if((op < 1) || (op > 9)) {
                printf("\n\n Opcao Invalida! Tente novamente...");
                getch();
                system("CLS || clear");
            }
        }while((op < 1) || (op > 9));

        switch(op)
        {
            case 1:
                lst = cria_lista();
                printf("\n\n Lista criada com sucesso!");
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
                res = insere_ord(&lst, elem);
                if(res == 1)
                    printf("\n\n Elemento inserido com sucesso");
                else
                    printf("\n\n Elemento nao inserido");

                getch();
                break;

            case 4:
                printf("\n\n Informe o elemento a ser removido: ");
                scanf("%d", &elem);
                // res = remove_ord(&lst, elem);
                // if(res == 1)
                //     printf("\n\n Elemento removido com sucesso");
                // else
                //     printf("\n\n Elemento nao removido");
                getch();
                break;

            case 5:
                printf("\n\n LISTA\n");
                imprime_lista(lst);
                getch();
                break;

            case 6:
                
                getch();
                break;

            case 7:
                
                getch();
                break;

            default:
				printf("\n\n Pressione qualquer tecla para FINALIZAR...");
				getch();
        }
    } while(op != 8);

    return 0;

}