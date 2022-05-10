#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int num, contl = 1, contc = 1;

    printf("Informe um numero inteiro: ");
    scanf("%d", &num);

    for(int i = 1; i <= num; i++){
        for(int j = 1; j <= i; j++){
            printf("%d ", contc);
            contc++;
        }
        printf("\n");
    }

    return 0;
}
