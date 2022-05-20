#include <stdio.h>
#include <stdlib.h>

double *maior_menor_elem(double *vet, int n){
    double aux_min=vet[0], aux_max=vet[0], *resp;
    resp = (double *) malloc(2*sizeof(double));

    for(int i=1; i < n; i++){
        if(vet[i] < aux_min){
            aux_min = vet[i];
        }
        if(vet[i] > aux_max){
            aux_max = vet[i];
        }
    }
    resp[0] = aux_min;
    resp[1] = aux_max;
    return resp;
}

int main(){
    int tam;
    double *vet, *resp;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tam);
    vet = (double *) malloc(tam*sizeof(double));

    printf("\nEntre com os valores do vetor: ");
    for(int i=0; i < tam; i++){
        printf("\n%d) ", i+1);
        scanf("%lf", &vet[i]);
    }

    resp = maior_menor_elem(vet, tam);
    printf("\n\nMenor valor do vetor: %.2lf", resp[0]);
    printf("\nMaior valor do vetor: %.2lf", resp[1]);

    free(vet);
    free(resp);
    return 0;    
}