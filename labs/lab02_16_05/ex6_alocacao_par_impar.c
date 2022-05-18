#include <stdio.h>

int main(){

    int n, *num, contp=0, conti=0;

    printf("Informe a quantidade de numeros a serem lidos: ");
    scanf("%d", &n);
    num = (int *) malloc(n*sizeof(int));

    for(int i=0; i<n; i++){
        printf("\n%d) Numero inteiro: ", i+1);
        scanf("%d", &num[i]);

        if(num[i]%2 == 0){
            contp += 1;
        }else{
            conti += 1;
        }
    }

    printf("\n\nDos %d numeros, %d sao pares", n, contp);
    printf("\nDos %d numeros, %d sao impares", n, conti);

    free(num);
    return 0;
}
