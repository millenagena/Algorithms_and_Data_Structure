#include <stdio.h>
#include <stdlib.h>

struct Ponto{
    int x;
    int y;
};
typedef struct Ponto ponto;

int area_ret(ponto *ptos){
    return (ptos[1].x - ptos[0].x) * (ptos[1].y - ptos[0].y);
}

int main(){
    int n = 2, area;
    ponto *ptos;
    ptos = (ponto *) malloc(n * sizeof(ponto));
    
    for(int i=0; i<n; i++){
        printf("\nEntre com as coordenadas x e y do ponto %d: ", i+1);
        scanf("%d%d", &ptos[i].x, &ptos[i].y);
    }

    area = area_ret(ptos);
    if(area < 0){
        area *= -1;
    }
    printf("\nA area do retangulo definido por (%d, %d) e (%d, %d) eh: %d", ptos[0].x, ptos[0].y, ptos[1].x, ptos[1].y, area);

    free(ptos);
    return 0;
}