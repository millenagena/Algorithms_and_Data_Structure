#include <stdio.h>
#include <stdlib.h>

char nomeMaiusculo(char letra_nome){

    char letra_maiuscula;

    if(letra_nome >= 97 && letra_nome <= 122){
         letra_maiuscula = letra_nome - 32;
    }else{
        letra_maiuscula = letra_nome;
    }
    return letra_maiuscula;
}

int main(){

    int tam = 50;
    char nome[tam];

    printf("Entre com o seu nome: ");
    scanf("%s", nome);

    printf("\nO nome digitado eh: ");

    for(int i = 0; nome[i] != '\0'; i++){
        printf("%c", nomeMaiusculo(nome[i]));
    }
    
    return 0;
}