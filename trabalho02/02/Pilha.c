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
    Pilha aux = p;
    while(aux != NULL){
        printf("%d ", p->info);
        aux = aux->prox;
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
    int elem_removido, tam, tam2;
    if(pilha_vazia(*p))
        return 0;
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

// int pares_e_impares(Pilha p){
//     int tam;
//     if(pilha_vazia(p))
//         return 0;

//     Pilha p_par;
//     Pilha p_impar;
//     p_par = cria_pilha(); 
//     p_impar = cria_pilha(); 

//     tam = p->topo; // armazenando a quantidade de posicoes ocupadas

//     for(int i=0; i <= tam; i++){
//         if(p->vet[p->topo] % 2 == 0){
//             push(p_par, p->vet[p->topo]);
//         }else{
//             push(p_impar, p->vet[p->topo]);
//         }
//         p->topo--;
//     }
//     printf("\nPilha de numeros pares:\n");
//     imprime(p_par);
//     printf("\nPilha de numeros impares:\n");
//     imprime(p_impar);

//     p->topo = tam;
//     return 1;
// }

