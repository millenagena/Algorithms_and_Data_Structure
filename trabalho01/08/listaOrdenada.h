typedef struct no *Lista;

Lista cria_lista();

int lista_vazia(Lista lst);

int insere_ord(Lista *lst, int exp, int coef);

int remove_ord(Lista *lst, int exp);

int tamanho(Lista lst);

void imprime_lista(Lista lst);

int calcular_polinomio(Lista lst, int valor_x, double *resultado);

void libera_lista(Lista *lst);