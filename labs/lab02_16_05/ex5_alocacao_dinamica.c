#include <stdio.h>

int main(){

    int *numeros, n=5;

    numeros = (int *) malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        printf("\n%d) Informe o numero: ", i+1);
        scanf("%d", &numeros[i]);
    }

    printf("\nOs numeros digitados foram: ");
    for(int i=0; i<n; i++){
        printf("%d ", numeros[i]);
    }

    free(numeros);
    return 0;
}
