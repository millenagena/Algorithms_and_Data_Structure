#include <stdio.h>
#include <stdlib.h>

int main(){

    int i=0, j=0, m=6, n=6;
    float mat[m][n], num=1.0, soma1=0, soma2=0, soma3=0, soma4=0, soma5=0, soma6=0, soma7=0, soma8=0;

    printf("Preencha os valores da matriz: \n");
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
           scanf("%f", &mat[i][j]);
        }
    }

    printf("\nA matriz digitada foi: \n");
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
           printf("%.2f ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    ///////// para testar
    // for(i = 0; i < m; i++){
    //     for(j = 0; j < n; j++){
    //        mat[i][j] = num++;
    //     }
    // }
    // for(i = 0; i < m; i++){
    //     for(j = 0; j < n; j++){
    //        printf("%.2f ", mat[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n\n");
    ///////// para testar

    // soma valores das partes hachuradas 1
    for(i = 0; i < m; i++){
        for(j = i+1; j < n; j++){
            soma1 = soma1 + mat[i][j];
        }
    }
    printf("\nSoma 1: %.2f", soma1);

    // soma valores das partes hachuradas 2
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(j < (n-1)-i){
                soma2 = soma2 + mat[i][j];
            }
        }
    }
    printf("\nSoma 2: %.2f", soma2);

    // soma valores das partes hachuradas 3
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(j < (n-1)-i && j > i){
                soma3 = soma3 + mat[i][j];
            }
        }
    }
    printf("\nSoma 3: %.2f", soma3);

    // soma valores das partes hachuradas 4 
    for(i = 1; i < m; i++){
        for(j = 0; j < n; j++){
            if(j < ((n-1)-i) && j < i){
                soma4 = soma4 + mat[i][j];
            }
        }
    }
    printf("\nSoma 4: %.2f", soma4);

    // soma valores das partes hachuradas 5 
    for(i = 1; i < m; i++){
        for(j = 0; j < n; j++){
            if(j < ((n-1)-i) && j < i || j > ((n-1)-i) && j > i){
                soma5 = soma5 + mat[i][j];
            }
        }
    }
    printf("\nSoma 5: %.2f", soma5);

    // soma valores das partes hachuradas 6
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(j > ((n-1)-i) && j < i || j < ((n-1)-i) && j > i){
                soma6 = soma6 + mat[i][j];
            }
        }
    }
    printf("\nSoma 6: %.2f", soma6);

    // soma valores das partes hachuradas 7
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(j < ((n-1)-i) && j > i || j < ((n-1)-i) && j < i){
                soma7 = soma7 + mat[i][j];
            }
        }
    } 
    printf("\nSoma 7: %.2f", soma7);

    // soma valores das partes hachuradas 8 
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(j < ((n-1)-i) && j < i || j > ((n-1)-i) && j < i){
                soma8 = soma8 + mat[i][j];
            }
        }
    }
    printf("\nSoma 8: %.2f", soma8);
}