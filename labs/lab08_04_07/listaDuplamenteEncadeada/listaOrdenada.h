typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_ord(Lista *lst, int elem);
void imprime_lista(Lista lst);