#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include "Fila.h"

int main()
{
    int op, res, elem;
    Fila f;

    do{
        system("CLS || clear");
        do{
            printf(" --- FILAS ESTATICAS SEQUENCIAIS --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar fila\n");
            printf(" 2. Verificar fila vazia\n");
            printf(" 3. Inserir no final\n");
            printf(" 4. Remover no inicio\n");
            printf(" 5. Ler elemento no final\n");
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
                f = cria_fila();
                printf("\n\n Fila criada com sucesso");
                getch();
                break;

            case 2:
                res = fila_vazia(f);
                if(res == 1)
                    printf("\n\n Fila vazia");
                else
                    printf("\n\n Fila nao vazia");
                getch();
                break;

            case 3:
                printf("\n\n Informe o elemento a ser inserido: ");
                scanf("%d", &elem);
                res = insere_fim(f, elem);
                if(res == 1)
                    printf("\n\n Elemento enfileirado com sucesso");
                else
                    printf("\n\n Elemento nao enfileirado");

                getch();
                break;

            case 4:
                res = remove_ini(f, &elem);
                if(res == 1)
                    printf("\n\n Elemento %d removido com sucesso", elem);
                else
                    printf("\n\n Elemento nao removido");

                getch();
                break;

            case 5:
                res = le_final(f, &elem);
                if(res == 1)
                    printf("\n\n Elemento no final: %d", elem);
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
