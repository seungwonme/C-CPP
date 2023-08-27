#include <stdio.h>

int get_int(char greet[50]);

int main(void)
{
  int n = get_int("number : ");
  if(n % 2 == 0) 
  {
    printf("%i is even\n",n);
  }
  else
  {
    printf("%i is odd\n",n);
  }
  return 0;
}

int get_int(char greet[50])
{
  int integer;
  printf("%s",greet);
  scanf("%d",&integer);
  return integer;
}