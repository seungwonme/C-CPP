#include <iostream>

class Test
{
private:
	// 1. Initialization in the declaration
	int		mData = 1; 
public:
	// 2. Initialization in the constructor with member initializer list
	Test()
	: mData(2)
	{
		mData = 3;
		// 3. Initialization in the constructor body
		std::cout << "Default Constructor" << std::endl;
	};
	~Test()
	{
		std::cout << "Destructor" << std::endl;
	};
	void PrintData()
	{
		std::cout << mData << std::endl;
	};
};

// 1, 2, 3 순서로 대입이 이루어진다.

int	main(void)
{
	Test test;
	test.PrintData();
	return 0;
}
