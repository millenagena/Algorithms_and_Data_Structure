#include <stdio.h>
#include <stdlib.h>

int main(){

    int i=0, j=0, m=6, n=6, num=1;
    int mat[m][n];

    printf("Preencha os valores da matriz: \n");
    ///////// para testar
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
           mat[i][j] = num++;
        }
    }
    ///////// para testar

    // matriz 01
    for(i = 0; i < m; i++){
        for(j = i+1; j < n; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

    // matriz 02
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(j < (n-1)-i){
                printf("%d ", mat[i][j]);
            }
        }
        printf("\n");
    }

        printf("\n\n");

    // matriz 03
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(j < (n-1)-i && j > i){
                printf("%d ", mat[i][j]);
            }
        }
        printf("\n");
    }

    printf("\n\n");

    // matriz 04 -- 
    for(i = 1; i < m; i++){
        for(j = 0; j < n; j++){
            if(j == 0 || j == 1 && j != i && j < ((n-1)-i)){
                printf("%d ", mat[i][j]);
            }
        }
        printf("\n");
    }

}