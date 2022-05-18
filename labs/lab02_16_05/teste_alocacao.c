#include <stdio.h>


int main(){
    double *produtos;
    int n, i;
    printf("Informe o número de produtos");
    scanf("%d",&n);

    // é necessário usar o comando malloc para alocar a memória
    produtos = (double *) malloc(n*sizeof(double));
    for (i = 0; i < n; i++){
        printf("Informe o valor do produto %d R$:",i+1);
        scanf("%lf", &produtos[i]);
    }
    printf("\nProdutos cadastrados\n");
    for (i = 0; i < n; i++){
        printf("Produto %d - R$: %f\n",i+1, produtos[i]);
    }
    // ao terminar de usar o vetor, devemos liberar a memória
    free(produtos);
    return 0;
}
