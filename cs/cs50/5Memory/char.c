#include <stdio.h>

int main(void)
{
  char *a = "Hello World!";
  char b[13] = "Hello World!";
  char c[] = "Hello World!";
  printf("%s\n",a);
  printf("%s\n",b);
  printf("%s\n",c);
  return 0;
}