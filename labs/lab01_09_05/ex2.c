#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float x, y, dist;

    printf("Informe as coordenadas: \n");
    scanf("%f%f", &x, &y);

    dist = sqrt( (pow(x,2)) + (pow(y,2)) );
    printf("\nA distancia do ponto (%.1f,%.1f) da origem eh: %.1f\n", x, y, dist);

    return 0;
}
