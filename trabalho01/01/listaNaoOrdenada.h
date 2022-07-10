typedef struct lista Lista;

Lista *inicializa_lista();

int lista_vazia(Lista *lst);

int tamanho(Lista *lst);

int lista_cheia(Lista *lst);

int insere_elemento(Lista *lst, int elemento);

int remove_elemento(Lista *lst, int elemento);

int remove_impares(Lista *lst);

int concatena(Lista *lst1, Lista *lst2);

int ordena_lista(Lista *lst);

int obtem_valor_elemento(Lista *lst, int pos_elemento);

void imprime_lista(Lista *lst);

int menor_elemento(Lista *lst);

void libera_lista(Lista **lst);
