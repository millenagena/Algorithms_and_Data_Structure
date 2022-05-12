#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    int **matriz;
    int m = 5, n = 8;


    if((matriz = (int **) malloc(m * sizeof(int *))) == NULL) {
        return -1;
    }
    for(i = 0; i < m; i++) {
        if((matriz[i] = (int *) malloc(n * sizeof(int))) == NULL) {
            return -1;
        }
        for(j = 0; j < n; j++) {
            matriz[i][j] = 0;
        }
    }

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf(((j+1) == n) ? "%d" : "%d, ", matriz[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i < m; i++) {
        free(matriz[i]);
    }
    free(matriz);
    matriz = NULL;

    return 0;
}