#include <stdio.h>

int fatorial(int number)
{
  int res;

  for (res = 1; number > 1; number--)
  {
    res = res * number;
  }

  return res;
}

int main()
{
  int fat;

  fat = fatorial(5);

  printf("%d", fat);

  return 0;
}
