/*
Nome: listaNaoOrdenada
Dados: numeros inteiros
Lista das operações: cria_lista, lista_vazia, lista_cheia, insere_elem, remove_elem, obtem_valor_elem, imprime_lista, libera_lista
*/
typedef struct no *Lista;

/*
Entradas: nenhuma
Pre-condicao: nenhuma
Processo: alocar espaço na memoria para uma lista e deixa-la vazia
Saida: endereco da lista criada
Pos-condicao: nenhuma
*/
Lista cria_lista();

/*
Entradas: endereco de uma lista
Pre-condicao: lista ser valida
Processo: verifica se a lista esta na condicao de vazia
Saida: 1 se vazia 0 caso contrario
Pos-condicao: nenhuma
*/
int lista_vazia(Lista lst);

/*
Entradas: endereco de uma lista e o registro a ser inserido (char, int, float)
Pre-condicao: lista ser valida e nao estar cheia
Processo: inserir o elemento no final da lista
Saida: 1 se sucesso ou 0 se falha
Pos-condicao: a lista de entrada com um elemento a mais
*/
int insere_registro(Lista *lst, char *nome, int vol, float preco);

/*
Entradas: endereco de uma lista
Pre-condicao: lista ser valida e nao estar vazia
Processo: remover o ultimo registro da lista e decrementar 
          o numero de registros na lista
Saida: 1 se sucesso e 0 se falha
Pos-condicao: a lista de entrada com 1 elemento a menos
*/
int apagar_ultimo_registro(Lista *lst);

/*
Entradas: endereco da lista
Pre-condicao: lista ser valida e nao estar vazia
Processo: percorrer a lista e imprimir cada um dos registros
Saida: nenhuma
Pos-condicao: nenhuma
*/
void imprime_tabela(Lista lst);

/*
Entradas: endereco de memoria do endereco da lista
Pre-condicao: nenhuma
Processo: limpar a memoria utilizada pela lista e 
          limpar seu endereco
Saida: nenhuma
Pos-condicao: memoria liberada
*/
void libera_lista(Lista *lst);