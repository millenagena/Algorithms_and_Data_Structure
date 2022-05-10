#include<stdio.h>

int main(void){
    float area, base, altura;
    printf("Entre com os valores: ");
    scanf("%f%f", &base, &altura);

    area = (base*altura)/2;
    printf("%.3f", area);
    return 0;
}