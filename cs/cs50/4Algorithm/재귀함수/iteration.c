#include <stdio.h>

void draw(int h);

int main(void)
{
  int height;
  printf("Height : ");
  scanf("%d", &height);
  draw(height);
  if(-1 == remove("iteration"))
  return 0;
}

void draw(int h)
{
  for (int i = 1; i <= h; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      printf("#");
    }
    printf("\n");
  }
}