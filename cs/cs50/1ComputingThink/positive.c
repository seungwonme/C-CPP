#include <stdio.h>

int get_int(char greet[50]);
int positive(void);

int main(void)
{
  printf("%i\n",positive());
  return 0;
}

int get_int(char greet[50])
{
  int integer;
  printf("%s",greet);
  scanf("%d",&integer);
  return integer;
}
int positive(void)
{
  int n;
  do
  {
   n = get_int("Positive Integer: ");
  } while (n < 1);
  return n;
}