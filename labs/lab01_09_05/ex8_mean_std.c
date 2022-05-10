#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int tam = 5;
    float vet[tam], soma = 0, media, std, aux = 0;

    for(int i = 0; i < tam; i++){
        printf("\n%d) Entre com o um valor: ", i+1);
        scanf("%f", &vet[i]);

        soma = soma + vet[i];
    }

    // calculando a media
    media = soma/tam;

    for(int i = 0; i < tam; i++){
        aux = aux + (pow(vet[i] - media, 2));
    }

    // calculando desvio padrao
    std = sqrt( aux / (tam - 1) );

    printf("\nMedia: %.2f", media);
    printf("\nDesvio padrao: %.2f", std);

    return 0;
}