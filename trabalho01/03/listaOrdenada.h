/*
Nome: listaOrdenada
Dados: numeros inteiros
Lista das operações: cria_lista, lista_vazia, insere_ord, remove_ord, 
                     tamanho, media, igualdade, intercala, inverte, get_impares
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
Entradas: endereco de uma lista
Pre-condicao: nenhuma
Processo: percorrer a lista e contar a quantidade de elementos
Saida: o tamanho da lista
Pos-condicao: nenhuma
*/
int tamanho(Lista lst);

/*
Entradas: endereco da lista e variavel para armazenar a media
Pre-condicao: nenhuma
Processo: somar todos os elem. da lista e dividir pelo tamnho
Saida: 0 se falha 1 se sucesso
Pos-condicao: variavel com o valor da media
*/
int media(Lista lst, double *med);

/*
Entradas: endereco de duas listas
Pre-condicao: nenhuma
Processo: percorer as listas e comparar cada um dos elementos
Saida: 1 se iguais 0 se diferentes
Pos-condicao: nenhuma
*/
int igualdade(Lista *lst1, Lista *lst2);

/*
Entradas: enderecos de duas listas
Pre-condicao: listas serem validas e nao estarem vazias
Processo: percorrer uma das listas e ir inserindo os elementos dela
          na outra lista de forma ordenada utilizando a função
          insere_ord
Saida: 1 se sucesso 0 se falha
Pos-condicao: uma lista com os elementos de duas listas intercalados
              de forma ordenada
*/
int intercala(Lista *lst1, Lista *lst2);

/*
Entradas: o endereco de duas listas
Pre-condicao: nenhuma
Processo: percorrer a lista e ir inserindo os elementos dela do menor pro maior
          na primeira posicao da segunda lista
Saida: 1 se sucesso 0 se falha
Pos-condicao: uma lista com os elementos ordenados de forma decrescente
*/
int inverte(Lista lst1, Lista *lst2);

/*
Entradas: o endereco de duas listas
Pre-condicao: nenhuma
Processo: percorrer a lista e verificar se os elementos sao impares. Caso
          seja impar, inserir na segunda lista de forma ordenada
Saida: 1 se sucesso 0 se falha
Pos-condicao: uma lista com os elementos impares ordenados
*/
int get_impares(Lista lst1, Lista *lst2);

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