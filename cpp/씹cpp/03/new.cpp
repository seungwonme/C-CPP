#include <iostream>

int	main(void)
{
	int	arr_size;
	int	*list;

	std::cout << "array size : ";
	std::cin >> arr_size;
	list = new int[arr_size];
	for (int i = 0; i < arr_size; i++)
		std::cin >> list[i];
	for (int i = 0; i < arr_size; i++)
		std::cout << i << "th element of list : " << list[i] << std::endl;
	delete[] list;
	return (0);
}
