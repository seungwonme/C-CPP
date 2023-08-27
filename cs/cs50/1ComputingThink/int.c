#include <stdio.h>

int get_int(char greet[50]);

int main(void)
{
  printf("You are at least %i days olds\n", get_int("What's your age?") * 365);
  return 0;
}

int get_int(char greet[50])
{
  int integer;
  printf("%s\n",greet);
  scanf("%d",&integer);
  return integer;
}