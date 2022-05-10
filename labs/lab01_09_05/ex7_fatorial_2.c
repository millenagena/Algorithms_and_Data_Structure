#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
int fatorial(int num){
  int i;

  for(i = 1; num > 1; num--){
    i = i * num;
  }
  return i;
}

int main(){
  
  printf("\n<<Fatorial>>\n");
  for(int i = 10; i <= 15; i++){
    printf("%d! = %d\n", i, fatorial(i));
  }

  return 0;
}
*/

/* 
Utilizando o código acima vamos perceber a partir do 13! vamos começar a ter resultados incorretos. 
Isso acontece porque estamos utilizando o tipo int para armazenar nossas variáveis, no entanto esse 
tipo de variável é limitada até certo ponto, pois não consegue armazenar valores muito grandes.

Para resolvermos esse erro podemos utilizar um tipo de variável que consiga armazenar valores 
maiores como o tipo double.
*/

double fatorial(double num){
  double i;

  for(i = 1; num > 1; num--){
    i = i * num;
  }
  return i;
}

int main(){
  
  printf("\n<<Fatorial>>\n");
  for(double i = 10; i <= 15; i++){
    printf("%.1lf! = %.1lf\n", i, fatorial(i));
  }

  return 0;
}