#include <iostream>

class Test
{
private:
	int mData;
public:
	Test(int data)
	: mData(data) {};
	~Test() {};

	void	PrintData()
	{
		std::cout << mData << std::endl;
		std::cout << Test::mData << std::endl;
		std::cout << this->mData << std::endl;
		std::cout << this->Test::mData << std::endl;
	};
};

int	main(void)
{
	Test t(10);

	t.PrintData();
	return 0;
}
