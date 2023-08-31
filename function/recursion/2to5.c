#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct h1 // 3
{
	char	ab1;
	char	ab2;
	char	ab3;
	int		asd;
} h1;

int	test(int a) // 4
{
	printf("test(%d) : Hello, World!\n", a);
	return (0);
}

void	recursion(int a)
{
	if (a == 0)
		return ;
	recursion(a - 1);
	printf("test(%d)\n", a);
}

int	main(void)
{
	// 3
	h1	a;
	printf("char(1) * 3 + int(4) * 1 = %lu\n", sizeof(a)); // 8 -> bite padding
	// 4
	int	(*f)(int) = test; // function pointer
	f(1);
	// 5
	recursion(5);
	return (0);
}
