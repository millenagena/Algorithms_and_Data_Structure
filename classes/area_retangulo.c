#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");
    float area;

    struct ponto {
        int x, y;
    };

    struct retangulo {
        struct ponto inicio, fim;
    };

    // declarando uma struct
    struct retangulo r;

    printf("Entre com as coordenadas: ");
    printf("\nInicio: ");
    scanf("%d%d", &r.inicio.x, &r.inicio.y);
    printf("Fim: ");
    scanf("%d%d", &r.fim.x, &r.fim.y);

    printf("\nCoordenadas: inicio -> {%d, %d}, fim -> {%d, %d}", r.inicio.x, r.inicio.y, r.fim.x, r.fim.y);

    area = (r.fim.x - r.inicio.x) * (r.fim.y - r.inicio.y);
    printf("\nA area desse retangulo eh: %.2f\n\n", area);

    system("pause");
    return 0;
}