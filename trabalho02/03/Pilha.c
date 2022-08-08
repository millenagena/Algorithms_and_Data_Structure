#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Pilha.h"

#define max 20
struct pilha{
    int vet[max];
    int topo;
};

Pilha cria_pilha(){
    Pilha p;
    p = (Pilha) malloc(sizeof(struct pilha));
    if(p != NULL)
        p->topo = -1;
    return p;
}

int pilha_vazia(Pilha p){
    if(p->topo == -1)
        return 1;
    else
        return 0;
}

int pilha_cheia(Pilha p){
    if(p->topo == max-1)
        return 1;
    else
        return 0;
}

int push(Pilha p, int elem){
    if(p==NULL || pilha_cheia(p)==1)
        return 0;
    // insere o elem no topo
    p->topo++;
    p->vet[p->topo] = elem;
    return 1;
}

int pop(Pilha p, int *elem){
    if(p==NULL || pilha_vazia(p))
        return 0;
    *elem = p->vet[p->topo];
    p->topo--;
    return 1;
}

int le_topo(Pilha p, int *elem){
    if(p==NULL || pilha_vazia(p)==1)
        return 0;
    *elem = p->vet[p->topo]; // retorna o elemento
    return 1;
}

void imprime(Pilha p){
    int elem_removido;
    Pilha p2;
    p2 = cria_pilha();

    while(p->topo != -1){
        printf("%d ", p->vet[p->topo]);
        push(p2, p->vet[p->topo]);
        pop(p, &elem_removido);
    }

    while(p2->topo != -1){
        push(p, p2->vet[p2->topo]);
        pop(p2, &elem_removido);
    }
}

void converte_dec_bin(int num){
    Pilha p = cria_pilha();
    int resto;

    do{
        resto = num%2;
        push(p, resto);
        num = num/2;
    }while(num != 0);

    imprime(p);
}

int eh_palindromo(char *vet){
    int tam, meio, elem, i;
    Pilha p;
    p = cria_pilha();
    tam = strlen(vet);
    meio = tam/2;

    for(i=0; i<meio; i++){
        push(p, vet[i]);
    }
    if(tam%2 != 0)
        i++;
    while(vet[i] != '\0'){
        pop(p, &elem);
        if(elem != vet[i])
            return 0;
        i++;
    }
    return 1;
}

int elimina(Pilha p, int elem){
    int elem_removido;
    if(pilha_vazia(p))
        return 0;
    Pilha p2;
    p2 = cria_pilha(); // criando pilha auxiliar

    while(p->topo != -1){
        if(p->vet[p->topo] == elem){
            pop(p, &elem_removido);
            break;
        }
        push(p2, p->vet[p->topo]);
        pop(p, &elem_removido);
    }

    // voltando os elementos para a pilha inicial
    if(pilha_vazia(p2) == 0){
        for(int i=0; p2->topo != -1; i++){
            push(p, p2->vet[p2->topo]); // adiciona o topo de p2 em p
            pop(p2, &elem_removido); // remove o topo de p2
        } 
    }
    return 1;
}

int pares_e_impares(Pilha p){
    int elem_removido;
    if(pilha_vazia(p))
        return 0;

    Pilha p_par, p_impar;
    p_par = cria_pilha(); 
    p_impar = cria_pilha(); 

    while(p->topo != -1){
        if(p->vet[p->topo] % 2 == 0){
            push(p_par, p->vet[p->topo]);
        }else{
            push(p_impar, p->vet[p->topo]);
        }
        pop(p, &elem_removido);
    }
    printf("\nPilha de numeros pares:\n");
    imprime(p_par);
    printf("\nPilha de numeros impares:\n");
    imprime(p_impar);

    return 1;
}
