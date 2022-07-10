typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int tamanho(Lista lst);
int insere_soldado(Lista *lst, char *nome);
int remove_soldado(Lista *lst, char *nome);
void imprime_lista(Lista lst);
int inicia_cont_primeiro(Lista *lst);
int inicia_cont_aleatorio(Lista *lst);
int inicia_cont_nome(Lista *lst, char nome[]);
