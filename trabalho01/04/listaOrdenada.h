typedef struct no *Lista;

Lista cria_lista();

int lista_vazia(Lista lst);

int insere_ord(Lista *lst, int elemento);

int remove_ord(Lista *lst, int elemento);

int obtem_valor_elemento(Lista lst, int pos_elemento);

void libera_lista(Lista **lst);

void imprime_lista(Lista lst);

int tamanho(Lista lst);

int media(Lista lst, double *med);

int intercala(Lista *lst1, Lista *lst2);

int inverte(Lista lst1, Lista *lst2);

int get_impares(Lista lst1, Lista *lst2);

int igualdade(Lista lst1, Lista lst2);
