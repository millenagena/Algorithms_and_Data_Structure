typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_ord(Lista *lst, int elem);
int remove_ord(Lista *lst, int elem);
int obtem_valor_elem(Lista lst, int pos, int *elem);
void imprime_lista(Lista lst);
int tamanho(Lista lst, int *tam);
int media(Lista lst, double *med);
int igualdade(Lista lst1, Lista lst2);
int remove_todos(Lista *lst, int elemento_repetido);
int maior(Lista lst, int *valor_maior);
int remove_maior(Lista *lst, int maior_elemento);
int get_mult_3(Lista lst, Lista *lst2);