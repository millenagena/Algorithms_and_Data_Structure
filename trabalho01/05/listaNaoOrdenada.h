typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_final(Lista *lst, int elem);
int insere_inicio(Lista *lst, int elem);
int remove_inicio(Lista *lst, int *elem);
void imprime_lista(Lista lst);