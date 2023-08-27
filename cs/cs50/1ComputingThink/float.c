#include <stdio.h>

float get_float(char greet[50]);
double get_double(char greet[50]);

int main(void)
{
  float x = get_float("x: ");
  float y = get_float("y: ");
  printf("x / y = %.20f\n",x/y); // x = 1 y = 10 x / y = 0.10000000149011611938
  // float은 32비트의 저장 용량 사용하므로 나머지 값은 저장 불가

  double a = get_double("a: ");
  double b = get_double("b: ");
  printf("a / b = %.20lf\n",a/b); // x = 1 y = 10 a / b = 0.10000000000000000555
  // double은 64비트

  // float은 소수점 8자리, double은 소수점 17자리까지 가능
  return 0;
}

float get_float(char greet[50])
{
  float f;
  printf("%s",greet);
  scanf("%f",&f);
  return f;
}
double get_double(char greet[50])
{
  double lf;
  printf("%s",greet);
  scanf("%lf",&lf);
  return lf;
}