#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float m, h, imc;

    printf("Informe a massa: \n");
    scanf("%f", &m);
    printf("\nInforme a altura: \n");
    scanf("%f", &h);

    imc = (m/(pow(h,2)));
    printf("\nValor do imc: %.2f\n\n", imc);

    if(imc < 18.5){
        printf("Magreza");
    }else if(imc < 24.9){
        printf("Saudavel");
    }else if(imc < 29.9){
        printf("Sobrepeso");
    }else if(imc < 34.9){
        printf("Obesidade Grau I");
    }else if(imc < 39.9){
        printf("Obesidade Grau II (severa)");
    }else{
        printf("Obesidade Grau III (morbida)");
    }
    return 0;
}
