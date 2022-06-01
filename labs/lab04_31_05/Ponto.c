#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "Ponto.h"

struct ponto{
    float x, y;
};
typedef struct ponto Ponto;

Ponto *gera_pto(){
    Ponto *p;
    p = (Ponto *) malloc(sizeof(Ponto));
    return p;
}

float set_pto(Ponto *p, float x, float y){
    if(p == NULL){
        return 0; // FALHA
    }
    p->x = x;
    p->y = y;
    return 1; //SUCESSO
}

float get_pto(Ponto *p, float *x, float *y){
    if(p == NULL){
        return 0; // FALHA
    }
    *x = p->x;
    *y = p->y;
    return 1; //SUCESSO
}

float distancia_pto(Ponto *pto1, Ponto *pto2){
    float dist;
    dist = sqrt( pow(pto1->x - pto2->x, 2) + pow(pto1->y - pto2->y, 2) );
    return dist;
}

void libera_pto(Ponto **p){
    free(*p); // Libera a memoria
    *p = NULL; // Limpa o ponteiro
}
