/*
Nome: listaOrdenada
Dados: numeros inteiros
Lista das operações: cria_lista, lista_vazia, insere_ord, remove_ord, obtem_valor_elem, imprime_lista, libera_lista
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
Processo: percorrer a lista ate encontrar a posicao correta de insercao
          para garantir a ordenacao (proximo for maior que o elemento).
          Inserir o elemento na posicao escolhida
Saida: 1 se sucesso ou 0 se falha
Pos-condicao: a lista de entrada com um elemento a mais
*/
int insere_ord(Lista *lst, int elem);

/*
Entradas: endereco de uma lista e o elemento a ser removido
Pre-condicao: lista ser valida e nao estar vazia
Processo: percorrer a lista ate encontrar o elemento desejado ou um elemento
          maior. Se o elemento existe, remova-o da lista
Saida: 1 se sucesso ou 0 se falha
Pos-condicao: a lista de entrada com um elemento a menos
*/
int remove_ord(Lista *lst, int elem);

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
Pre-condicao: lista ser valida
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
