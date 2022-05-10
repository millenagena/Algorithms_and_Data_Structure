// Laboratório 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// exercicio 1

int main(){
    float jog1, jog2, jog3, premio, soma_jog;

    printf("Bolao jogadores: \n");
    scanf("%f%f%f", &jog1, &jog2, &jog3);

    printf("Informe o valor do premio: \n");
    scanf("%f", &premio);

    soma_jog = jog1 + jog2 + jog3;

    printf("Jogador 1 recebera: %.2f\n", (jog1/soma_jog)*premio);
    printf("Jogador 2 recebera: %.2f\n", (jog2/soma_jog)*premio);
    printf("Jogador 3 recebera: %.2f\n", (jog3/soma_jog)*premio);

    return 0;
}





