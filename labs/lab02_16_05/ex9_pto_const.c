#include <stdio.h>
#include <stdlib.h>

struct Ponto{
    int x;
    int y;
};
typedef struct Ponto ponto;

void altera_pto(ponto *pto, int cnste){
    pto->x = (pto->x*cnste);
    pto->y = (pto->y*cnste);
}

int main(){
    int cnste, n=1;
    ponto *pto;
    pto = (ponto *) malloc(n*sizeof(ponto));

    printf("Entre com as coordenadas x e y do ponto: ");
    scanf("%d%d", &pto->x, &pto->y);
    printf("\nEntre com o valor da constante: ");
    scanf("%d", &cnste);

    printf("\nResultado: (%d,%d) * %d: ", pto->x, pto->y, cnste);
    altera_pto(pto, cnste);
    printf("(%d,%d)", pto->x, pto->y);

    free(pto);
    return 0;
}