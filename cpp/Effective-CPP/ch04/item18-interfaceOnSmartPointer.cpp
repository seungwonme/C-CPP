#include <iostream>

class Investment
{
public:
	Investment()
	{
		std::cout << "Investment()" << std::endl;
	};
	~Investment()
	{
		std::cout << "~Investment()" << std::endl;
	};
};

// 스마트 포인터를 사용해야 한다는 사실을 사용자가 잊는다면?
// 문제 생길 여지를 남겨두지 않고 사용자가 스마트 포인터를 사용하도록 강제하는 방법
// Investment* CreateInvestment()
std::shared_ptr<Investment> CreateInvestment()
{
	// return new Investment();
	return std::shared_ptr<Investment>(new Investment());
}

void f()
{
	std::shared_ptr<Investment> pInv(CreateInvestment());
}

int	main(void)
{
	f();
	return 0;
}
