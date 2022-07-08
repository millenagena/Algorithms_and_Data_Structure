

// numero 5

struct no{
    int info;
    struct no *prox;
};
typedef struct no *Lista;

int insere_pos(Lista *lst, int pos, int elem){
    int cont=1;
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL){return 0;}
    N->info = elem;
    Lista aux = (*lst)->prox; // aponta para o primeiro elemento
    if(lista_vazia(*lst)){ // trata lista vazia
        N->prox = N;
        *lst = N;
    }
    if(pos == 0){ // trata primeira posicao
        N->prox = (*lst)->prox;
        (*lst)->prox = N;
    }
    else if(pos >= tamanho(*lst)){ // trata se a posicao for maior q a ultima posicao
        N->prox = (*lst)->prox;
        (*lst)->prox = N;
        *lst = N;
    }
    else{
        while(aux->prox != (*lst) && cont < pos){
            aux = aux->prox;
            cont++;
        }
        N->prox = aux->prox;
        aux->prox = N;
    }
    return 1;
}

void imprime_lista(Lista lst){
    Lista aux = lst->prox;
    Lista aux2 = aux->prox;

    printf("%d ", aux->info);
    while(aux != aux2){
        printf("%d ", aux2->info);
        aux2 = aux2->prox;
    }
}