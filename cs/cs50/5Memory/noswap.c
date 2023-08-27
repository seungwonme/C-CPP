#include <stdio.h>

void noswap(int a, int b);

int main(void)
{
  int one = 1;
  int two = 2;
  noswap(one,two);
  printf("one : %d\ntwo : %d\n",one,two); // 복사본이기 때문에 바뀌지 않는 것
  return 0;
}

void noswap(int a, int b)
{
  int swap;
  swap = a;
  a = b;
  b = swap;
}