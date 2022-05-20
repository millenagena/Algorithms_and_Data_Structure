#include<stdio.h>
#include <stdlib.h>

// função do ex13 utilizada apenas para preencher o vetor
int *aloca_inteiro(int n){
    int *pont;
    pont = (int *) malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        pont[i] = i+1;
    }
    return pont;
}

void imprime_vet(double *p, int n){
    for(int i=0; i<n; i++){
        printf("%.2lf ", *(p+i));
    }
}

double *to_double(int *vet, int n){
    double *vet_double;
    vet_double = (double *) malloc(n*sizeof(double));

    for(int i=0; i<n; i++){
        vet_double[i] = vet[i];
    }

    return vet_double;
}

int main(){
    int *p, n=10;
    double *p_double;
    p = aloca_inteiro(n);
    p_double = to_double(p, n);
    imprime_vet(p_double, n);
}