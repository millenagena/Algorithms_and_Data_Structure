typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_ord(Lista *lst, int elem);
int remove_ord(Lista *lst, int elem);
int obtem_valor_elem(Lista lst, int pos, int *elem);
void imprime_lista(Lista lst);