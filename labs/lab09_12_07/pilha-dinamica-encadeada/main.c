#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include "Pilha.h"

int main()
{
    int op, res, elem;
    Pilha p;

    do{
        system("CLS || clear");
        do{
            printf(" --- PILHAS ESTATICAS SEQUENCIAIS --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar pilha\n");
            printf(" 2. Verificar pilha vazia\n");
            printf(" 3. Empilhar\n");
            printf(" 4. Desempilhar\n");
            printf(" 5. Ler elemento no topo\n");
            printf(" 6. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);
            if((op < 1) || (op > 6)) {

                printf("\n\n Opcao Invalida! Tente novamente...");
                getch();
                system("CLS || clear");
            }
        } while((op < 1) || (op > 6));

        switch(op)
        {
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
                printf("\n\n Informe o elemento a ser inserido: ");
                scanf("%d", &elem);
                res = push(&p, elem);
                if(res == 1)
                    printf("\n\n Elemento empilhado com sucesso");
                else
                    printf("\n\n Elemento nao empilhado");

                getch();
                break;

            case 4:
                res = pop(&p, &elem);
                if(res == 1)
                    printf("\n\n Elemento %d desempilhado com sucesso", elem);
                else
                    printf("\n\n Elemento nao desempilhado");

                getch();
                break;

            case 5:
                res = le_topo(&p, &elem);
                if(res == 1)
                    printf("\n\n Elemento no topo: %d", elem);
                else
                    printf("\n\n Nao foi possivel realizar a leitura");

                getch();
                break;


            default:
				printf("\n\n Pressione qualquer tecla para FINALIZAR...");
				getch();
        }
    } while(op != 6);

    return 0;
}
