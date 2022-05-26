#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct individuo {
    int codigo_genetico[10]; // valores binarios aleatorios
    float aptidao_abs;// pontencial de cada individuo (0.0 <= aptidao <= 10.0)
    float aptidao_relativa; // deve ser calculada em tempo de execucao...
};
typedef struct individuo individuo;

struct populacao {
    struct individuo *pop; // um vetor de N individuos
    int tamanho; // tamanho N da populacao (N = 100)
};
typedef struct populacao populacao;


float num_aleatorio(float num){
    float sorteio;
    sorteio = ((float) rand()) / ((float) RAND_MAX);
    return sorteio*num;
}

int sorteia_zero_um(){
    int s = (rand() % 100);
    return s%2;
}

void printa_struct(populacao *p){

    for(int i=0; i < p->tamanho; i++){
        printf("\n\nIndividuo %d", i+1);
        printf("\nCodigo genetico: ");
        for(int j = 0; j < 10; j++){
            printf("%d", p->pop[i].codigo_genetico[j]);
        }
        printf("\nAptidao absoluta: ");
        printf("%.2lf", p->pop[i].aptidao_abs);
        printf("\nAptidao relativa: ");
        printf("%.2lf", p->pop[i].aptidao_relativa);
    }
}

void printa_individuo(individuo *ind, int indice){

    printf("\n\nIndividuo %d", indice+1);
    printf("\nCodigo genetico: ");
    for(int j = 0; j < 10; j++){
        printf("%d", ind->codigo_genetico[j]);
    }
    printf("\nAptidao absoluta: ");
    printf("%.2lf", ind->aptidao_abs);
    printf("\nAptidao relativa: ");
    printf("%.2lf", ind->aptidao_relativa);
}

float soma_apt(populacao *p){
    float soma = 0;
    for(int i = 0; i < p->tamanho; i++){
        soma += p->pop[i].aptidao_abs;
    }
    return soma;
}

void calcula_apt_relativa(populacao *p){
    float s_apt;
    s_apt = soma_apt(p);
    for(int i=0; i < p->tamanho; i++){
        p->pop[i].aptidao_relativa = p->pop[i].aptidao_abs / s_apt;
    }
}

void metodo_roleta(populacao *p){
    int ind[2];
    float num_sort, soma;

    for(int i=0; i < 2; i++){
        num_sort = num_aleatorio(1);
        soma = 0;
        for(int j=0; j < p->tamanho; j++){
            soma += p->pop[j].aptidao_relativa;
            if(soma >= num_sort){
                ind[i] = j;
                printf("\nValor sorteado %d: %f\nValor soma %d: %f\n", i+1, num_sort, i+1, soma);
                break;
            }
        }
    }
    printa_individuo(&p->pop[ind[0]], ind[0]);
    printa_individuo(&p->pop[ind[1]], ind[1]);
}

int main(){

    float apt;
    populacao popu;

    srand(time(NULL));

    printf("Entre com a quantidade de individuos: ");
    scanf("%d", &popu.tamanho);
    popu.pop = (individuo *) malloc(popu.tamanho*sizeof(individuo));

    for(int i=0; i < popu.tamanho; i++){
        apt = num_aleatorio(10);
        popu.pop[i].aptidao_abs = apt;

        for(int j = 0; j < 10; j++){
            popu.pop[i].codigo_genetico[j] = sorteia_zero_um();
        }
    }
    calcula_apt_relativa(&popu);
    printa_struct(&popu);
    printf("\n\n======Individuos selecionados===");
    metodo_roleta(&popu);
    //printa_individuo(&popu.pop[1]);

    free(popu.pop);
    return 0;
}
