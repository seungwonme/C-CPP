#include <iostream>

int	main(void)
{
	int arr[5] = {1, 2, 3, 4, 5};

	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << std::endl;
	}
	std::cout << std::endl;

	for (auto &i : arr)
	{
		std::cout << i-- << std::endl;
	}
	std::cout << std::endl;

	for (const auto& i : arr)
	{
		// --i; // error: assignment of read-only reference ‘i’
		std::cout << i << std::endl;
	}
	
	return 0;
}
