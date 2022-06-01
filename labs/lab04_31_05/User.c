#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "Ponto.h"

int main(){
    Ponto *pto1, *pto2;
    float x, y, x1, y1, distancia;
    pto1 = gera_pto();
    pto2 = gera_pto();

    if(pto1 == NULL || pto2 == NULL){
        printf("\n----Erro ao criar os pontos!----");
        return -1;
    }

    printf("\nEntre com as coordenadas do ponto 1: ");
    scanf("%f%f", &x, &y);
    if(set_pto(pto1, x, y) == 0){
        printf("\n----Falha ao preencher o primeiro ponto----");
        return -1;
    }

    printf("\nEntre com as coordenadas do ponto 2: ");
    scanf("%f%f", &x1, &y1);
    if(set_pto(pto2, x1, y1) == 0){
        printf("\n----Falha ao preencher o segundo ponto----");
        return -1;
    }

    printf("\n\nAs coordenadas dos pontos sao: ");
    if(get_pto(pto1, &x, &y) == 0){
        printf("\n----Falha ao recuperar as coord do primeiro ponto----");
        return -1;
    }
    printf("\nPonto 1: (%.2f, %.2f)", x, y);

    if(get_pto(pto2, &x1, &y1) == 0){
        printf("\n----Falha ao recuperar as coord do segundo ponto----");
        return -1;
    }
    printf("\nPonto 2: (%.2f, %.2f)", x1, y1);

    distancia = distancia_pto(pto1, pto2);
    printf("\n\nA distancia entre os dois pontos eh: %.2f", distancia);

    libera_pto(&pto1);
    libera_pto(&pto2);

    return 0;
}
