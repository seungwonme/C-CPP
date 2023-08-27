#include <stdio.h>

void cough(int n);

int main(void)
{
  cough(7);
  return 0;
}

void cough(int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("cough\n");
  }
}