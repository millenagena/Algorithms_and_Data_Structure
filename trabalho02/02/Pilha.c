#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Pilha.h"

struct pilha{
    int info;
    struct pilha *prox;
};
typedef struct pilha *Pilha;

Pilha cria_pilha(){
    return NULL;
}

int pilha_vazia(Pilha p){
    if(p==NULL)
        return 1;
    else
        return 0;
}

int push(Pilha *p, int elem){
    Pilha N = (Pilha) malloc(sizeof(struct pilha));
    N->info = elem;
    if(N==NULL){return 0;}
    N->info = elem;
    N->prox = *p;
    *p = N;
    return 1;
}

int pop(Pilha *p, int *elem){
    if(pilha_vazia(*p)==1)
        return 0;
    Pilha aux = *p;
    *elem = aux->info;
    *p = aux->prox;
    free(aux);
    return 1;
}

int le_topo(Pilha *p, int *elem){
    if(pilha_vazia(*p)==1)
        return 0;
    *elem = (*p)->info;
    return 1;
}

void imprime(Pilha p){
    int elem_removido;
    Pilha p2;
    p2 = cria_pilha();

    while(p != NULL){
        printf("%d ", p->info);
        push(&p2, p->info);
        pop(&p, &elem_removido);
    }

    if(pilha_vazia(p2) == 0){
        while(p2 != NULL){
            push(&p, p2->info); // adiciona o topo de p2 em p
            pop(&p2, &elem_removido); // remove o topo de p2
        }
    }
}

int eh_palindromo(char *vet){
    int tam, meio, elem, i;
    Pilha p;
    p = cria_pilha();
    tam = strlen(vet);
    meio = tam/2;

    for(i=0; i<meio; i++){
        push(&p, vet[i]);
    }
    if(tam%2 != 0)
        i++;
    while(vet[i] != '\0'){
        pop(&p, &elem);
        if(elem != vet[i])
            return 0;
        i++;
    }
    return 1;
}

int elimina(Pilha *p, int elem){
    if(pilha_vazia(*p))
        return 0;
    int elem_removido, tam, tam2;
    Pilha p2;
    p2 = cria_pilha(); // criando pilha auxiliar

    while((*p) != NULL){
        if((*p)->info == elem){
            pop(p, &elem_removido);
            break;
        }
        push(&p2, (*p)->info);
        pop(p, &elem_removido);
    }

    // voltando os elementos para a pilha inicial
    if(pilha_vazia(p2) == 0){
        while(p2 != NULL){
            push(p, p2->info);
            pop(&p2, &elem_removido);
        }
    }
    return 1;
}

int pares_e_impares(Pilha *p){
    if(pilha_vazia(*p))
        return 0;
    
    int elem_removido;
    Pilha p_par, p_impar;
    p_par = cria_pilha(); 
    p_impar = cria_pilha(); 

    while((*p) != NULL){
        if((*p)->info % 2 == 0){
            push(&p_par, (*p)->info);
        }else{
            push(&p_impar, (*p)->info);
        }
        pop(p, &elem_removido);
    }
    printf("\nPilha de numeros pares:\n");
    imprime(p_par);
    printf("\nPilha de numeros impares:\n");
    imprime(p_impar);

    return 1;
}

