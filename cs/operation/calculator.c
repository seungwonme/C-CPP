#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int plus(int a, int b)
{
	return (a + b);
}

int minus(int a, int b)
{
	return (a + (~b + 1));
}

int multiplication(int a, int b)
{
	int sum = 0;

	while (b > 0)
	{
		sum += a;
		--b;
	}
	return (sum);
}


int division(int a, int b)
{
	int cnt = 0;

	while (a >= b)
	{
		a -= b;
		++cnt;
	}
	return (cnt);
}

int modulus(int a, int b)
{
	while (a >= b)
		a -= b;
	return (a);
}

int main(void)
{
	printf("1 + 2 = %d\n", plus(1, 2));
	printf("1 - 2 = %d\n", minus(1, 2));
	printf("1 * 2 = %d\n", multiplication(1, 2));
	printf("1 / 2 = %d\n", division(1, 2));
	printf("1 %% 2 = %d\n", modulus(1, 2));

	remove("a.out");
	remove("tempCodeRunnerFile.c");
	return (0);
}
