#include<conio.h>

typedef struct listaBebidas listaBebidas;
listaBebidas *cria_lista();
int lista_vazia(listaBebidas *lst);
int lista_cheia(listaBebidas *lst);
int insere_registro(listaBebidas *lst, char *nome, int vol, float preco);
int apagar_ultimo_registro(listaBebidas *lst);
void imprime_tabela(listaBebidas *lst);
void libera_registros(listaBebidas **lst);