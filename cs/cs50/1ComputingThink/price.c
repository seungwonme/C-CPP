#include <stdio.h>

float get_float(char greet[50]);

int main(void)
{
  printf("Your total is %.2f\n", get_float("What's the price?")*1.033);
  return 0;
}

float get_float(char greet[50])
{
  float f;
  printf("%s\n",greet);
  scanf("%f",&f);
  return f;
}