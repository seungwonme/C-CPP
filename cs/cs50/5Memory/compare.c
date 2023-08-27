#include <stdio.h>

int main(void)
{
  char a[100];
  char b[100];

  printf("a : ");
  scanf("%s",a);
  printf("b : ");
  scanf("%s",b);
  printf("---------\na : %s\nb : %s\n",a,b);
  if (a == b)
  {
    printf("same\n");
  }
  else printf("diffrent\n");
  return 0;
}
/*
a : EMMA
b : EMMA
---------
a : EMMA
b : EMMA
diffrent

주소가 다르기 때문이다.
*/