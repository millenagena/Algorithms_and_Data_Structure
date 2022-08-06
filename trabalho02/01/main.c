#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include "Pilha.h"

int main()
{
    int op, res, elem, tam;
    char palavra[25];
    Pilha p, p2;

    do{
        system("CLS || clear");
        do{
            printf(" --- PILHAS ESTATICAS SEQUENCIAIS --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar pilha\n");
            printf(" 2. Verificar pilha vazia\n");
            printf(" 3. Verificar pilha cheia\n");
            printf(" 4. Empilhar\n");
            printf(" 5. Desempilhar\n");
            printf(" 6. Ler elemento no topo\n");
            printf(" 7. Imprime elementos\n");
            printf(" 8. Palindromo\n");
            printf(" 9. Elimina elemento\n");
            printf(" 10. Pares e impares\n");
            printf(" 11. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);
            if((op < 1) || (op > 11)) {

                printf("\n\n Opcao Invalida! Tente novamente...");
                getch();
                system("CLS || clear");
            }
        } while((op < 1) || (op > 11));

        switch(op){
            case 1:
                p = cria_pilha();
                printf("\n\n Pilha criada com sucesso");
                getch();
                break;

            case 2:
                res = pilha_vazia(p);
                if(res == 1)
                    printf("\n\n Pilha vazia");
                else
                    printf("\n\n Pilha nao vazia");
                getch();
                break;

            case 3:
                res = pilha_cheia(p);
                if(res == 1)
                    printf("\n\n Pilha cheia");
                else
                    printf("\n\n Pilha nao cheia");
                getch();
                break;

            case 4:
                printf("\n\n Informe o elemento a ser inserido: ");
                scanf("%d", &elem);
                res = push(p, elem);
                if(res == 1)
                    printf("\n\n Elemento empilhado com sucesso");
                else
                    printf("\n\n Elemento nao empilhado");

                getch();
                break;

            case 5:
                res = pop(p, &elem);
                if(res == 1)
                    printf("\n\n Elemento %d desempilhado com sucesso", elem);
                else
                    printf("\n\n Elemento nao desempilhado");

                getch();
                break;

            case 6:
                res = le_topo(p, &elem);
                if(res == 1)
                    printf("\n\n Elemento no topo: %d", elem);
                else
                    printf("\n\n Nao foi possivel realizar a leitura");

                getch();
                break;
            
            case 7:
                imprime(p);
                getch();
                break;
            
            case 8:
                printf("\n\n Informe a palavra: ");
                fflush(stdin);
                gets(palavra);
                res = eh_palindromo(palavra);
                if(res == 1)
                    printf("\n\n Essa palavra eh palindromo!");
                else
                    printf("\n\n Essa palavra NAO eh palindromo!");

                getch();
                break;
            
            case 9:
                printf("\n\n Informe o elemento a ser removido: ");
                scanf("%d", &elem);
                res = elimina(p, elem);
                if(res == 1)
                    printf("\n\n Elemento removido com sucesso");
                else
                    printf("\n\n Elemento nao removido");

                getch();
                break;
            
            case 10:
                p2 = cria_pilha();
                printf("\n\n Informe a quantidade de elementos que deseja inserir: ");
                scanf("%d", &tam);
                for(int i=0; i<tam; i++){
                    printf("\n Elemento %d: ", i+1);
                    scanf("%d", &elem);
                    push(p2, elem);
                }
                res = pares_e_impares(p2);
                if(res == 0)
                    printf("\n\n FALHA");
                getch();
                break;

            default:
				printf("\n\n Pressione qualquer tecla para FINALIZAR...");
				getch();
        }
    } while(op != 11);

    return 0;
}
