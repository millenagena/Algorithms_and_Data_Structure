#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include "listaSoldado.h"

int main()
{
    int op, res, elem, tam, sold;
    char nome[30];
    Lista lst;

    do{
        system("CLS || clear");
        do{
            printf(" --- LISTAS DINAMICAS ENCADEADAS --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar lista\n");
            printf(" 2. Verificar lista vazia\n");
            printf(" 3. Inserir soldados\n");
            printf(" 4. Iniciar contagem a partir do primeiro soldado\n");
            printf(" 5. Iniciar contagem a partir de um soldado aleatorio\n");
            printf(" 6. Informar o nome do soldado para iniciar a contagem\n");
            printf(" 7. Imprime a lista de soldados\n");
            printf(" 8. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);
            if((op < 1) || (op > 13)) {
                printf("\n\n Opcao Invalida! Tente novamente...");
                getch();
                system("CLS || clear");
            }
        } while((op < 1) || (op > 8));

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
                printf("\n\n Informe a quantidade de soldados que deseja inserir: ");
                scanf("%d", &tam);

                for(int i=0; i<tam; i++){
                    printf("\n Informe o nome do soldado %d: ", i+1);
                    fflush(stdin);
                    gets(nome);
                    res = insere_soldado(&lst, nome);
                    if(res==0){printf("\nSoldado nao inserido!!!");}
                }
                printf("\n SOLDADOS INSERIDOS COM SUCESSO!");
                getch();
                break;
            case 4:
                res = inicia_cont_primeiro(&lst);
                if(res==0){printf("\nFALHA!!!");}
                getch();
                break;

            case 5:
                res = inicia_cont_aleatorio(&lst);
                if(res==0){printf("\nFALHA!!!");}
                getch();
                break;

            case 6:
                printf("\n\n Informe o nome do soldado para iniciar a contagem: ");
                fflush(stdin);
                gets(nome);
                res = inicia_cont_nome(&lst, nome);
                if(res==0){printf("\nFALHA!!!");}
                getch();
                break;
            
            case 7:
                imprime_lista(lst);
                getch();
                break;

            default:
				printf("\n\n Pressione qualquer tecla para FINALIZAR...");
				getch();
        }
    } while(op != 8);

    return 0;
}
