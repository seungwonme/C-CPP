#include <stdio.h>

int const FOUNDNUM = 50;

int main(void)
{
  // Linear Search O(n),Ω(1)
  int numbers[6] = {4,8,15,17,23,42};
  for (int i = 0; i < 6; i++)
  {
    if (numbers[i] == FOUNDNUM)
    {
      printf("found %i\n",numbers[i]);
      return 0;
    } 
  }
  printf("not found\n");
  if(-1 == remove("numbers"))
  return 1;
}