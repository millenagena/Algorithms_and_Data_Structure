typedef struct pilha *Pilha;

Pilha cria_pilha();
int pilha_vazia(Pilha p);
int pilha_cheia(Pilha p);
int push(Pilha p, int elem);
int pop(Pilha p, int *elem);
int le_topo(Pilha p, int *elem);
void imprime(Pilha p);
void converte_dec_bin(int num);
int eh_palindromo(char *vet);
int elimina(Pilha p, int elem);
int pares_e_impares(Pilha p);