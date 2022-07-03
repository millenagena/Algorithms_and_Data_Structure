#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include "listaNaoOrdenada.h"

int main()
{
    int op, res, elem, tam, tam_lista;
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
            printf(" 5. Remover elemento no inicio\n");
            printf(" 6. Remover elemento no final\n");
            printf(" 7. Imprimir lista\n");
            printf(" 8. Verificar igualdade de duas listas\n");
            printf(" 9. Intercalar duas listas\n");
            printf(" 10. Inverter a lista\n");
            printf(" 11. Retornar impares\n");
            printf(" 12. Liberar lista\n");
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
                res = remove_inicio(&lst, &elem);
                if(res == 1)
                    printf("\n\n Elemento %d removido com sucesso", elem);
                else
                    printf("\n\n Elemento nao removido");
                getch();
                break;

            case 6:
                
                getch();
                break;

            case 7:
                printf("\n\n LISTA\n");
                imprime_lista(lst);
                getch();
                break;
            
            case 8:
                
                getch();
                break;

            case 9:
                
                getch();
                break;
            
            case 10:
                
                getch();
                break;
            
            case 11:
                
                getch();
                break;
            
            case 12:
                //libera_lista(&lst);
                getch();
                break;

            default:
				printf("\n\n Pressione qualquer tecla para FINALIZAR...");
				getch();
        }
    } while(op != 13);

    return 0;
}
