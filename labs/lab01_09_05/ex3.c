#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float m, h, imc;

    printf("Informe os 4 bits do numero binario: \n");
    scanf("%d%d%d%d", &b1, &b2, &b3, &b4);

    n_int = (pow(2,3) * b1) + (pow(2,2) * b2) + (pow(2,1) * b3) + (pow(2,0) * b4);
    printf("\nO numero binario %d%d%d%d corresponde ao numero decimal %d\n", b1, b2, b3, b4, n_int);

    return 0;
}
