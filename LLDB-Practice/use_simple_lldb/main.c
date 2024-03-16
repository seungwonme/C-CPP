// https://www.youtube.com/watch?v=v_C1cvo1biI

#include <stdio.h>

void	func2()
{
	int *ptr = NULL;

	*ptr = 7;
}

void	func1()
{
	func2();
}

int	main(void)
{
	func1();
	return (0);
}
