#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ponto{
    int x;
    int y;
};
typedef struct Ponto ponto;

void inc_dir(ponto *pto, char dir){
    if(dir == 'l'){
        pto->x += 1;
    }else if(dir == 'o'){
        pto->x -= 1;
    }else if(dir == 'n'){
        pto->y += 1;
    }else if(dir == 's'){
        pto->y -= 1;
    }
}

int main(){
    int n=1;
    char dir[10];
    ponto *pto;
    pto = (ponto *) malloc(n*sizeof(ponto));

    printf("Entre com as coordenadas x e y do ponto: ");
    scanf("%d%d", &pto[0].x, &pto[0].y);
    printf("\nEntre com a direcao: ");
    scanf("%s", &dir[0]);

    printf("\nPonto inicial: (%d,%d)", pto[0].x, pto[0].y);
    inc_dir(&pto[0], dir[0]);
    printf("\nPonto depois do deslocamento: (%d,%d)", pto[0].x, pto[0].y);

    free(pto);
    return 0;

}