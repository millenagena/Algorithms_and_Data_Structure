typedef struct no *Fila;

Fila cria_fila();
int fila_vazia(Fila f);
int insere_fim(Fila *f, int elem);
int remove_ini(Fila *f, int *elem);
int le_final(Fila f, int *elem);
void imprime(Fila *f);
