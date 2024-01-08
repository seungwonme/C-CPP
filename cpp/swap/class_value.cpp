#include <iostream>

class Data
{
private:
	std::string mName;
	int mData;
public:
	Data()
	: mName("Data")
	, mData(0)
	{
		std::cout << mName << " Constructor" << std::endl;
	}
	Data(std::string name, int data) 
	: mName(name)
	, mData(data)
	{
		std::cout << mName << " Constructor" << std::endl;
	}
	Data(const Data& rhs)
	: mName(rhs.mName)
	, mData(rhs.mData)
	{
		std::cout << mName << " Copy Constructor" << std::endl;
	}
	void operator=(const Data& rhs)
	{
		std::cout << mName << " Copy Assignment" << std::endl;
		mData = rhs.mData;
	}
	~Data()
	{
		std::cout << mName << " Destructor" << std::endl;
	}
	operator int() const
	{
		return mData;
	}
};

void	swap(Data a, Data b)
{
	// a Copy Constructor
	// b Copy Constructor
	Data tmp = a;
	// a Copy Constructor
	a = b;
	// a Copy Assignment
	b = tmp;
	// b Copy Assignment
}
// a Destructor
// b Destructor
// a Destructor (tmp)

int	main(void)
{
	Data a("a", 5), b("b", 10);
	// a Constructor
	// b Constructor
	::swap(a, b);
	std::cout << a << ' ' << b << std::endl;
	// 5 10
	return 0;
}
// b Destructor
// a Destructor
