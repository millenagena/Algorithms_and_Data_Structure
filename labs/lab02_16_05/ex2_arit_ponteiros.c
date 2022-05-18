#include <stdio.h>

int main(){
  char nome[] = "Jose Augusto";

  for(int i=0; nome[i] != '\0'; i++){
    printf("%c", *(nome+i));
  }
  return 0;
}
