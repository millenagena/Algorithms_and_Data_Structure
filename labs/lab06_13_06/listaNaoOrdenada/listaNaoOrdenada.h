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
Entradas: endereco de uma lista e o elemento a ser inserido
Pre-condicao: lista ser valida e nao estar cheia
Processo: inserir o elemento no final da lista
Saida: 1 se sucesso ou 0 se falha
Pos-condicao: a lista de entrada com um elemento a mais
*/
int insere_elem(Lista *lst, int elem);

/*
Entradas: endereco de uma lista e o elemento a ser removido
Pre-condicao: lista ser valida e nao estar vazia
Processo: percorrer a lista ate encontrar o elemento desejado ou chegar ao seu final.
          Se o elemento existe, remova-o da lista
Saida: 1 se sucesso e 0 se falha
Pos-condicao: a lista de entrada com 1 elemento a menos
*/
int remove_elem(Lista *lst, int elem);

/*
Entradas: endereco da lista e posicao do elemento a ser localizado
Pre-condicao: lista ser valida e nao estar vazia
Processo: percorrer a lista ate encontrar a posicao desejada ou chegar ao seu final.
          Se a posicao existe, retorna o elemento dessa posicao.
Saida: elemento na posicao informada
Pos-condicao: nenhuma
*/
int obtem_valor_elem(Lista lst, int pos);

/*
Entradas: endereco da lista
Pre-condicao: lista ser valida e nao estar vazia
Processo: percorrer a lista e imprimir cada um dos elementos
Saida: nenhuma
Pos-condicao: nenhuma
*/
void imprime_lista(Lista lst);

/*
Entradas: endereco de memoria do endereco da lista
Pre-condicao: nenhuma
Processo: limpar a memoria utilizada pela lista e 
          limpar seu endereco
Saida: nenhuma
Pos-condicao: memoria liberada
*/
void libera_lista(Lista *lst);

