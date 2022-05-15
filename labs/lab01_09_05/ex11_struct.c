#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include<locale.h>

struct Endereco{
    char rua[50];
    int num;
    char comp[50];
    char cidade[50];
    char estado[50];
    char pais[50];
};
typedef struct Endereco endereco;

struct Telefone{
    int ddd;
    int numero;
};
typedef struct Telefone telefone;

struct DataAniversario{
    int dia;
    int mes;
    int ano;
};
typedef struct DataAniversario aniver;

struct Pessoa{
    char nome[50];
    char email[50];
    endereco end;
    telefone tel;
    aniver data_niver;
    char obs[100];

}; 
typedef struct Pessoa pessoa;

void printa_string(char *str){

    for(int i=0; str[i] != '\0'; i++){
        printf("%c", str[i]);
    }
    printf("\n");
}

void printa_struct(pessoa *ag){
    printf("Nome: ");
    printa_string(ag->nome);
    printf("E-mail: ");
    printa_string(ag->email);
    printf("Endereco: \n");
    printf("Rua: ");
    printa_string(ag->end.rua);
    printf("Numero: %d\n", ag->end.num);
    printf("Complemento: ");
    printa_string(ag->end.comp);
    printf("Cidade: ");
    printa_string(ag->end.cidade);
    printf("Estado: ");
    printa_string(ag->end.estado);
    printf("Pais: ");
    printa_string(ag->end.pais);
    printf("Telefone: (%d)%d\n", ag->tel.ddd, ag->tel.numero);
    printf("Aniversario: %d/%d/%d\n", ag->data_niver.dia, ag->data_niver.mes, ag->data_niver.ano);
    printf("Obs especial: ");
    printa_string(ag->obs);
}

void mostra_dados(pessoa vetp[], int contador){
    for(int i=0; i < contador; i++){
        printa_struct(&vetp[i]);
        printf("\n");
    }
    getch();
}

void mostra_nome_tel_email(pessoa vetp[], int contador){

    for(int i=0; i < contador; i++){
        printf("Nome: ");
        printa_string(vetp[i].nome);
        printf("E-mail: ");
        printa_string(vetp[i].email);
        printf("Telefone: (%d)%d\n", vetp[i].tel.ddd, vetp[i].tel.numero);
        printf("\n");
    }
    getch();
}

char maiuscula(char letra){
    if(letra >= 'a' && letra <= 'z') {
        letra = letra -32;
    }   
    return letra;
}

void ordem_alf(pessoa vetp[], int qntd){
    int i, j;
    pessoa aux;

    for(i=0; i<=qntd; i++){

        for(j=i+1; j<=qntd; j++){

            if(strcmp(vetp[i].nome, vetp[j].nome) > 0){
                aux = vetp[i];
                vetp[i] = vetp[j];
                vetp[j] = aux;
            }
        }
    }
}

void insere_pessoa(pessoa vetp[], int contador){
    printf("\nNome: ");
    fflush(stdin);
    gets(vetp[contador].nome);
    vetp[contador].nome[0] = maiuscula(vetp[contador].nome[0]);
    printf("\nE-mail: ");
    fflush(stdin);
    gets(vetp[contador].email);
    printf("\nEndereco: ");
    printf("\n---------------");
    printf("\nRua: ");
    fflush(stdin);
    gets(vetp[contador].end.rua);
    printf("\nNumero: ");
    scanf("%d", &vetp[contador].end.num);
    printf("\nComplemento: ");
    fflush(stdin);
    gets(vetp[contador].end.comp);
    printf("\nCidade: ");
    fflush(stdin);
    gets(vetp[contador].end.cidade);
    printf("\nEstado: ");
    fflush(stdin);
    gets(vetp[contador].end.estado);
    printf("\nPais: ");
    fflush(stdin);
    gets(vetp[contador].end.pais);
    printf("\n---------------");
    printf("\nTelefone: ");
    printf("\n---------------");
    printf("\nDDD: ");
    scanf("%d", &vetp[contador].tel.ddd);
    printf("\nNumero: ");
    scanf("%d", &vetp[contador].tel.numero);
    printf("\n---------------");
    printf("\nAniversario: ");
    printf("\n---------------");
    printf("\nDia: ");
    scanf("%d", &vetp[contador].data_niver.dia);
    printf("\nMes: ");
    scanf("%d", &vetp[contador].data_niver.mes);
    printf("\nAno: ");
    scanf("%d", &vetp[contador].data_niver.ano);
    printf("\n---------------");
    printf("\nObs especial: ");
    fflush(stdin);
    gets(vetp[contador].obs);

    ordem_alf(vetp, contador);
}

int retira_pessoa(pessoa vetp[], int contador, char nome[]){

    int aux=0, indice_pessoa, op;
    for(int i=0; i<contador; i++){
        if(strcmp(nome, vetp[i].nome) == 0){
            aux = 1;
            indice_pessoa = i;
            printf("Nome: ");
            printa_string(vetp[i].nome);
            printf("E-mail: ");
            printa_string(vetp[i].email);
            printf("Telefone: (%d)%d\n", vetp[i].tel.ddd, vetp[i].tel.numero);
            printf("\n");
        }
    }
    if(aux == 1){
        printf("\n\nDeseja mesmo retirar essa pessoa? Digite: 1 - sim ou 2 - não: ");
		scanf("%d", &op);
		if(op == 1)
		{
			for(int i = indice_pessoa; i < contador; i++)
				vetp[i] = vetp[i+1];
			return contador - 1;	
		}
    }else{
        printf("\nPessoa não registrada.");	
		getch();
    }
    return contador;
}

void busca_nome(pessoa *p, char *nome){
    int aux=0;
    for(int i=0; p->nome[i] != '\0'; i++){
        if(p->nome[i] == ' '){
            break;
        }
        if(maiuscula(p->nome[i]) == nome[i]){
            aux = 1;
        } else {
            aux = 0;
        }
    }

    if(aux == 1){
        printa_struct(p);
    }
    getch();
}

void busca_mes(pessoa *p, int m){
    if(p->data_niver.mes == m){
        printa_struct(p);
    }
    getch();
}

void busca_dia_mes(pessoa *p, int d, int m){
    if(p->data_niver.dia == d && p->data_niver.mes == m){
        printa_struct(p);
    }
    getch();
}

int main(){
    setlocale(LC_ALL, "portuguese");
    int tam=100, cont=0, opcao, mes_info, dia_info, mes_info2;
    char nome_info[30], nome_ma[30], nome_info2[30];
    pessoa agenda[tam];

    do{
		system("cls");
		printf("Escolha a opcao desejada:\n ");
		
		printf("\n1 - Cadastrar pessoa na agenda");
		printf("\n2 - Buscar pelo primeiro nome");
		printf("\n3 - Buscar por mes de aniversario");
		printf("\n4 - Buscar por dia e mes de aniversario");
		printf("\n5 - Excluir pessoa da agenda");
		printf("\n6 - Mostrar nome, telefone e e-mail");
		printf("\n7 - Apresentar todos os dados");
		printf("\n8 - Encerrar o programa.\n  ");
		
		scanf("%d", &opcao);
		switch(opcao)
		{
			case 1:
				system("cls");
				insere_pessoa(agenda, cont);
				cont++;
				break;
			case 2:
				system("cls");
                printf("\nInforme o nome: ");
                fflush(stdin);
                gets(nome_info);
				for(int i=0; nome_info[i] != '\0'; i++){
                    nome_ma[i] = maiuscula(nome_info[i]);
                }
                for(int i=0; i < cont; i++){
                    busca_nome(&agenda[i], nome_ma);
                    printf("\n");
                }
				break;
			case 3:
				system("cls");
                printf("\n");
				printf("Informe o mes: ");
                scanf("%d", &mes_info);
                for(int i=0; i < cont; i++){
                    busca_mes(&agenda[i], mes_info);
                    printf("\n");
                }
				break;
			case 4:
				system("cls");
                printf("\n");
                printf("\nInforme o dia: ");
                scanf("%d", &dia_info);
                printf("\nInforme o mes: ");
                scanf("%d", &mes_info2);
				for(int i=0; i < cont; i++){
                    busca_dia_mes(&agenda[i], dia_info, mes_info2);
                    printf("\n");
                }
				break;
			case 5:
				system("cls");
                printf("\n");
                printf("Informe o nome da pessoa a ser retirada: ");
                fflush(stdin);
                gets(nome_info2);
                cont = retira_pessoa(agenda, cont, nome_info2);
				break;
			case 6:
				system("cls");
                printf("\n");
                mostra_nome_tel_email(agenda, cont);
				break;
			case 7:
				system("cls");
                printf("\n");
                mostra_dados(agenda, cont);
				break;
				
			default:
				if(opcao != 8)
				{
					printf("\n\nOpção inválida.");
					getch();
				}	
		}
	}while(opcao != 8);
	return 0;
}