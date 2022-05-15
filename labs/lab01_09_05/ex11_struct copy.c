#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

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

void ordem_alf(pessoa vetp[], int qntd){
    int i, j;
    char aux[100];

    for(i=0; i<qntd; i++){

        for(j=0; j<qntd; j++){

            if(strcmp(vetp[j-1].nome, vetp[j].nome) > 0){

                strcpy(aux, vetp[j-1].nome);
                strcpy(vetp[j-1].nome, vetp[j].nome);
                strcpy(vetp[j].nome, aux);

            }
        }
    }

}

void insere_pessoa(pessoa vetp[], int contador){
    printf("\nNome: ");
    fflush(stdin);
    gets(vetp[contador].nome);
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
}

char maiuscula(char letra){
    if(letra >= 'a' && letra <= 'z') {
        letra = letra -32;
    }   
    return letra;
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
}

void busca_mes(pessoa *p, int m){
    if(p->data_niver.mes == m){
        printa_struct(p);
    }
}

void busca_dia_mes(pessoa *p, int d, int m){
    if(p->data_niver.dia == d && p->data_niver.mes == m){
        printa_struct(p);
    }
}

int main(){

    int tam=100, cont=0, opcao;
    char aux[30];
    pessoa agenda[tam];

    printa_string("Oi\n");

    strcpy(agenda[cont].nome, "Millena Gena Pereira");
    strcpy(agenda[cont].email, "millena@email");
    strcpy(agenda[cont].end.rua, "Amarela");
    agenda[cont].end.num = 12;
    strcpy(agenda[cont].end.comp, "Ao lado da Ju");
    strcpy(agenda[cont].end.cidade, "Abadia");
    strcpy(agenda[cont].end.estado, "MG");
    strcpy(agenda[cont].end.pais, "BR");
    agenda[cont].tel.ddd = 34;
    agenda[cont].tel.numero = 99999999;
    agenda[cont].data_niver.dia = 1;
    agenda[cont].data_niver.mes = 5;
    agenda[cont].data_niver.ano = 2014;
    strcpy(agenda[cont].obs, "Gosta de chocolate");

    cont = 1;
    strcpy(agenda[cont].nome, "Millena Moraes");
    strcpy(agenda[cont].email, "millena@email");
    strcpy(agenda[cont].end.rua, "Amarela");
    agenda[cont].end.num = 12;
    strcpy(agenda[cont].end.comp, "Ao lado da Ju");
    strcpy(agenda[cont].end.cidade, "Abadia");
    strcpy(agenda[cont].end.estado, "MG");
    strcpy(agenda[cont].end.pais, "BR");
    agenda[cont].tel.ddd = 34;
    agenda[cont].tel.numero = 99999999;
    agenda[cont].data_niver.dia = 1;
    agenda[cont].data_niver.mes = 2;
    agenda[cont].data_niver.ano = 2014;
    strcpy(agenda[cont].obs, "Odeia arroz");

    cont = 2;
    strcpy(agenda[cont].nome, "Ana da Silva");
    strcpy(agenda[cont].email, "millena@email");
    strcpy(agenda[cont].end.rua, "Amarela");
    agenda[cont].end.num = 12;
    strcpy(agenda[cont].end.comp, "Ao lado da Ju");
    strcpy(agenda[cont].end.cidade, "Abadia");
    strcpy(agenda[cont].end.estado, "MG");
    strcpy(agenda[cont].end.pais, "BR");
    agenda[cont].tel.ddd = 34;
    agenda[cont].tel.numero = 99999999;
    agenda[cont].data_niver.dia = 2;
    agenda[cont].data_niver.mes = 5;
    agenda[cont].data_niver.ano = 2014;
    strcpy(agenda[cont].obs, "Odeia arroz");

    cont = 3;
    strcpy(agenda[cont].nome, "Jonata Guimaraes");
    strcpy(agenda[cont].email, "millena@email");
    strcpy(agenda[cont].end.rua, "Amarela");
    agenda[cont].end.num = 12;
    strcpy(agenda[cont].end.comp, "Ao lado da Ju");
    strcpy(agenda[cont].end.cidade, "Abadia");
    strcpy(agenda[cont].end.estado, "MG");
    strcpy(agenda[cont].end.pais, "BR");
    agenda[cont].tel.ddd = 34;
    agenda[cont].tel.numero = 99999999;
    agenda[cont].data_niver.dia = 2;
    agenda[cont].data_niver.mes = 5;
    agenda[cont].data_niver.ano = 2014;
    strcpy(agenda[cont].obs, "Odeia arroz");

    cont = 4;

    // Insere pessoa
    insere_pessoa(agenda, cont);

    for(int i=0; i <= cont; i++){
        printa_struct(&agenda[i]);
        printf("\n");
    }


    // // busca por primeiro nome
    // printf("\n=========Busca mesmo primeiro nome=========\n");
    // char nome_info[30] = "Millena", nome_ma[30];
    // for(int i=0; nome_info[i] != '\0'; i++){
    //     nome_ma[i] = maiuscula(nome_info[i]);
    // }
    // for(int i=0; i < cont; i++){
    //     busca_nome(&agenda[i], nome_ma);
    //     printf("\n");
    // }

    // // busca por mês de niver
    // printf("\n\n=========Busca mesmo mes de aniversario=========\n");
    // int mes_info = 5;
    // for(int i=0; i < cont; i++){
    //     busca_mes(&agenda[i], mes_info);
    //     printf("\n");
    // }

    // // busca por dia e mês de niver
    // printf("\n\n=========Busca mesmo dia e mes de aniversario=========\n");
    // int dia_info = 2, mes_info2 = 5;
    // for(int i=0; i < cont; i++){
    //     busca_dia_mes(&agenda[i], dia_info, mes_info2);
    //     printf("\n");
    // }

    return 0;

}