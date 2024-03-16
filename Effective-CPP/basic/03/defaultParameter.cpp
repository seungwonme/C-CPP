#include <iostream>

void print(int a, int b = 10)
{
	std::cout << a << ", " << b << std::endl;
}

int	main(void)
{
	print(1, 2);
	print(3);
	return 0;
}
