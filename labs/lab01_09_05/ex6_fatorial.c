#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fatorial(int num){
  int i;

  for(i = 1; num > 1; num--){
    i = i * num;
  }
  return i;
}

int main(){
  
  printf("\n<<Fatorial>>\n");
  for(int i = 1; i <= 10; i++){
    printf("%d! = %d\n", i, fatorial(i));
  }

  return 0;
}
