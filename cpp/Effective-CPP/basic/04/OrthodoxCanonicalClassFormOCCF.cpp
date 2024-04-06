#include <iostream>

class Test
{
private:
	int		mData;
public:
	Test()
	: mData(0)
	{
		std::cout << "Default Constructor" << std::endl;
	};
	Test(const Test &rhs)
	: mData(rhs.mData)
	{
		std::cout << "Copy Constructor" << std::endl;
	};
	Test(int data)
	: mData(data)
	{
		std::cout << "Conversion Constructor" << std::endl;
	};
	Test &operator=(const Test &rhs)
	{
		std::cout << "Assignment Copy Operator" << std::endl;
		return *this;
	};
	~Test()
	{
		std::cout << "Destructor" << std::endl;
	};
};

void convertion(Test test)
{
	std::cout << "Conversion Function" << std::endl;
}

int	main(void)
{
	Test stack;

	convertion(1); // Conversion Constructor

	Test* heap = new Test; // Default Constructor

	// delete heap; // Destructor
	// if you delete heap, it will call destructor
	return 0;
}
