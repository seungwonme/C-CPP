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

Investment* CreateInvestment()
{
	return new Investment();
}

void f()
{
	std::unique_ptr<Investment> pInv(CreateInvestment());
	// std::auto_ptr<Investment> pInv(CreateInvestment());
	
	std::shared_ptr<Investment> pInv1(CreateInvestment());
	std::shared_ptr<Investment> pInv2(pInv1);

	// Investment* pInv = CreateInvestment();
	// auto_ptr의 소멸자를 통해 pInv를 삭제, auto_ptr은 C++11에서 deprecated
	// 자원 획득과 자원 관리를 한 문장에서 함 => RAII (Resource Acquisition Is Initialization)
	// ...
	// delete 전 return, continue, goto, throw 등을 사용하여 함수를 빠져나가는 경우를 고려해야함
	// 함수로 얻어낸 자원이 항상 해제되도록 만들 방법은, 자원을 객체에 넣고 그 자원 해제를 소멸자에게 맡기는 것
	// delete pInv;
}

int	main(void)
{
	f();
	return 0;
}
