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
	bool isTaxFree() const
	{
		return true;
	};
};

Investment* CreateInvestment()
{
	return new Investment();
}

int daysHeld(const Investment* pi)
{
	return 0;
}

void f()
{
	std::shared_ptr<Investment> pInv(CreateInvestment());

	// int days = daysHeld(pInv);
	// candidate function not viable: no known conversion from 'std::shared_ptr<Investment>' to 'const Investment *' for 1st argument
	int days = daysHeld(pInv.get());
	// get() returns a pointer to the object managed by the shared_ptr

	bool taxable1 = !(pInv->isTaxFree());

	std::unique_ptr<Investment> pInv2(CreateInvestment());

	bool taxable2 = !((*pInv2).isTaxFree());
}

int	main(void)
{
	f();
	return 0;
}
