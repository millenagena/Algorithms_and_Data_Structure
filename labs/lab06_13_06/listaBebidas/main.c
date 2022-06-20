#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include "listaBebidas.h"

int main()
{
    int op, res, elem, pos, vol;
    char nome[20];
    float preco;
    Lista lst;

    do{
        system("CLS || clear");
        do{
            printf(" --- LISTAS DINAMICAS ENCADEADAS --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar lista de bebidas\n");
            printf(" 2. Verificar lista vazia\n");
            printf(" 3. Inserir registro\n");
            printf(" 4. Excluir ultimo registro\n");
            printf(" 5. Imprimir registros\n");
            printf(" 6. Liberar lista\n");
            printf(" 7. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);
            if((op < 1) || (op > 7)) {
                printf("\n\n Opcao Invalida! Tente novamente...");
                getch();
                system("CLS || clear");
            }
        } while((op < 1) || (op > 7));

        switch(op)
        {
            case 1:
                lst = cria_lista();
                printf("\n\n Lista criada com sucesso");
                getch();
                break;

            case 2:
                res = lista_vazia(&lst);
                if(res == 1)
                    printf("\n\n Lista vazia");
                else
                    printf("\n\n Lista nao vazia");
                getch();
                break;

            case 3:
                printf("\n\n Informe o registro a ser inserido: \n");
                printf(" Nome da bebida: ");
                scanf("%s", &nome);
                printf(" Volume: ");
                scanf("%d", &vol);
                printf(" Preco: ");
                scanf("%f", &preco);
                res = insere_registro(&lst, nome, vol, preco);
                if(res == 1)
                    printf("\n\n Registro inserido com sucesso");
                else
                    printf("\n\n Registro nao inserido");
                getch();
                break;

            case 4:
                res = apagar_ultimo_registro(&lst);
                if(res == 1)
                    printf("\n\n Elemento removido com sucesso");
                else
                    printf("\n\n Elemento nao removido");
                getch();
                break;

            case 5:
                printf("\n\n LISTA\n");
                imprime_tabela(lst);
                getch();
                break;

            case 6:
                libera_lista(&lst);
                printf("\n\nLISTA LIBERADA");
                break;

            default:
				printf("\n\n Pressione qualquer tecla para FINALIZAR...");
				getch();
        }
    } while(op != 7);

    return 0;
}
