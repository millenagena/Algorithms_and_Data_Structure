#include <stdio.h>
#include <stdlib.h>

int *aloca_inteiro(int n){
    int *pont;
    pont = (int *) malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        pont[i] = 0;
    }
    return pont;
}

void imprime_vet(int *p, int n){
    for(int i=0; i<n; i++){
        printf("%d ", *(p+i));
    }
}

int main(){
    int *p, n=10;
    p = aloca_inteiro(n);
    imprime_vet(p,n);
}