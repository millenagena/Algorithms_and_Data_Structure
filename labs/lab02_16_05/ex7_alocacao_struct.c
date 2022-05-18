#include <stdio.h>
#include <stdlib.h>

struct Coordenadas{
    int x;
    int y;
};
typedef struct Coordenadas coord;

int main(){

    int n;
    coord *ptos;

    printf("Entre com a quantidade de pontos: ");
    scanf("%d", &n);
    ptos = (coord *) malloc(n*sizeof(coord));

    for(int i=0; i<n; i++){
        printf("\nEntre com as coordenadas x e y do ponto %d: ", i+1);
        scanf("%d%d", &ptos[i].x, &ptos[i].y);
    }
    printf("\n\nPontos digitados: ");
    for(int i=0; i<n; i++){
        printf("\n(%d,%d)", ptos[i].x, ptos[i].y);
    }

    free(ptos);
    return 0;
}
