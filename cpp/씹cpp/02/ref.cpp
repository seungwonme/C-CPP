#include <iostream>

/* 댕글링 레퍼런스
int	&func()
{
	int	a = 2;
	return (a);
} */

int	&func(int &a)
{
	a = 100;

	return (a);
}

int	func1()
{
	int	a = 3;
	return (a);
}

int	main(void)
{
	int	a = 3;
	int	b = 5;
	int	&another_a = a;
	// int	&this_is_impossible;
	// int	&this_is_impossible = 5;

	another_a = 5;
	std::cout << "a         : " << a << std::endl;
	std::cout << "another_a : " << another_a << std::endl;
	another_a = b; // a = b 와 같다.
	std::cout << "a         : " << &a << std::endl;
	std::cout << "another_a : " << &another_a << std::endl;

	int	arr[][3] = {{1, 2, 3}, {4, 5, 6}};
	int	(&another_arr)[2][3] = arr;

	another_arr[0][0] = 0;
	another_arr[0][1] = 0;
	another_arr[0][2] = 0;
	another_arr[1][0] = 0;
	another_arr[1][1] = 0;
	another_arr[1][2] = 0;

	for (int i = 0; i < 3; i++)
		std::cout << arr[0][i] << ' ';

	int	res = func(another_a);
	std::cout << res << ", " << another_a << '\n';

	// int	&res1 = func1();
	const int	&res1 = func1();
	std::cout << res1;
	return (0);
}
