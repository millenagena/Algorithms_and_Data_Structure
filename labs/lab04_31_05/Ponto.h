/*
Nome: Ponto
Dados: numeros decimais
Lista das operações: gera_pto, set_pto, get_pto, distancia_pto, libera_pto
*/

typedef struct ponto Ponto;

/*
Entradas: nenhuma
Pre-condicao: nenhuma
Processo: criar um Ponto sem valores de coordenadas definidos
Saida: endereço de um Ponto criado
Pos-condicao: nenhuma
*/
Ponto *gera_pto();

/*
Entradas: endereco de um Ponto e valores das coordenadas x e y (dois floats)
Pre-condicao: Ponto ter um endereco valido
Processo: atribuir a coordenada x o valor do float x
          e atribuir a coordenada y o valor do float y
Saida: 1 se sucesso na atribuicao de valores
       0 se falha
Pos-condicao: Ponto com valores de coordenadas setados
*/
int set_pto(Ponto *p, float x, float y);

/*
Entradas: endereco de um Ponto e endereco de dois floats (x e y)
Pre-condicao: Ponto ter um endereco valido
Processo: atribuir ao conteudo do float x o valor da coordenada
          x do ponto e ao conteudo do float y o valor da 
          coordenada y
Saida: 1 se sucesso e 0 se falha
Pos-condicao: os floats com os valores das coordenadas x e y
              do Ponto
*/
int get_pto(Ponto *p, float *x, float *y);

/*
Entradas: endereco de dois Pontos
Pre-condicao: os Pontos terem enderecos validos
Processo: calcular a distancia entre os dois Pontos
Saida: o valor da distancia entre os Pontos
Pos-condicao: nenhuma
*/
float distancia_pto(Ponto *pto1, Ponto *pto2);

/*
Entradas: endereco do endereco de um Ponto
Pre-condicao: nenhuma
Processo: limpar a memoria utilizada pelo Ponto e
          limpar seu endereco
Saida: nenhuma
Pos-condicao: Ponto liberado
*/
void libera_pto(Ponto **p);
