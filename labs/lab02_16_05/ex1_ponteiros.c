#include <stdio.h>

int main(){
    int a = 40;
    int *p;
    p = &a;

    // letra a
    printf("Valor variavel a: %d\n", a);
    printf("Valor variavel a: %d\n", *p);

    // letra b
    printf("\n\nEntre com um novo valor para a: ");
    scanf("%d", p);
    printf("\nNovo valor variavel a: %d", a);

    return 0;
}
