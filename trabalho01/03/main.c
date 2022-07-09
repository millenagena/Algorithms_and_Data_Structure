#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include "listaOrdenada.h"

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
            printf(" 3. Inserir elemento\n");
            printf(" 4. Excluir elemento\n");
            printf(" 5. Imprimir lista\n");
            printf(" 6. Obter tamanho da lista\n");
            printf(" 7. Media dos valores da lista\n");
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
                res = remove_ord(&lst, elem);
                if(res == 1)
                    printf("\n\n Elemento removido com sucesso");
                else
                    printf("\n\n Elemento nao removido");
                getch();
                break;

            case 5:
                printf("\n\n LISTA\n");
                imprime_lista(lst);
                getch();
                break;

            case 6:
                tam = tamanho(lst);
                printf("\n\n Tamanho da lista: %d", tam);
                getch();
                break;

            case 7:
                res = media(lst, &med);
                printf("\n\n Media dos valores da lista: %lf", med);
                getch();
                break;
            
            case 8:
                lst2 = cria_lista();
                printf("\nQual o tamanho da lista? ");
                scanf("%d", &tam_lista);
                for(int i=0; i<tam_lista; i++){
                    printf("\nInforme o elemento %d: ", i+1);
                    scanf("%d", &elem);
                    res = insere_ord(&lst2, elem);
                }
                res = igualdade(lst, lst2);
                if(res == 1)
                    printf("\nLISTAS IGUAIS");
                else
                    printf("\nLISTAS DIFERENTES");
                getch();
                break;

            case 9:
                lst2 = cria_lista();
                printf("\nQual o tamanho da lista? ");
                scanf("%d", &tam_lista);
                for(int i=0; i<tam_lista; i++){
                    printf("\nInforme o elemento %d: ", i+1);
                    scanf("%d", &elem);
                    res = insere_ord(&lst2, elem);
                }
                res = intercala(&lst, &lst2);
                if(res == 1)
                    printf("\nLISTAS INTERCALADAS COM SUCESSO");
                else
                    printf("\nFALHA NA INTERCALACAO");
                getch();
                break;
            
            case 10:
                lst2 = cria_lista();
                res = inverte(lst, &lst2);
                if(res == 1){
                    printf("\nLISTA INVERTIDA:\n");
                    imprime_lista(lst2);
                }else{
                    printf("\nFALHA NA INVERSAO");
                }
                getch();
                break;
            
            case 11:
                lst2 = cria_lista();
                res = get_impares(lst, &lst2);
                if(res == 1){
                    printf("\nNUMEROS IMPARES DA LISTA:\n");
                    imprime_lista(lst2);
                }else{
                    printf("\nFALHA");
                }
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
