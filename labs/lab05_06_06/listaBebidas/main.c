#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include "listaNoOrdBebidas.h"


int main()
{
    int op, res, vol;
    char nome[20];
    float preco;
    listaBebidas *lst;

    do{
        system("CLS || clear");
        do{
            printf(" --- LISTAS ESTATICAS SEQUENCIAIS --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar lista de bebidas\n");
            printf(" 2. Verificar lista vazia\n");
            printf(" 3. Verificar lista cheia\n");
            printf(" 4. Inserir registro\n");
            printf(" 5. Excluir ultimo registro\n");
            printf(" 6. Imprimir registros\n");
            printf(" 7. Liberar lista\n");
            printf(" 8. SAIR\n");
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
                printf("\n\n Lista de bebidas criada com sucesso");
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
                printf("\n\n Informe o registro a ser inserido: \n");
                printf(" Nome da bebida: ");
                scanf("%s", &nome);
                printf(" Volume: ");
                scanf("%d", &vol);
                printf(" Preco: ");
                scanf("%f", &preco);
                res = insere_registro(lst, nome, vol, preco);
                if(res == 1)
                    printf("\n\n Registro inserido com sucesso");
                else
                    printf("\n\n Registro nao inserido");
                getch();
                break;

            case 5:
                res = apagar_ultimo_registro(lst);
                if(res == 1)
                    printf("\n\n Elemento removido com sucesso");
                else
                    printf("\n\n Elemento nao removido");
                getch();
                break;

            case 6:
                printf("\n\n LISTA DE BEBIDAS \n");
                imprime_tabela(lst);
                getch();
                break;

            case 7:
                libera_registros(&lst);
                printf("\n\n Lista de bebidas liberarda com sucesso!");
                getch();
                break;

            default:
				printf("\n\n Pressione qualquer tecla para FINALIZAR...");
				getch();
        }
    } while(op != 8);

    return 0;
}
