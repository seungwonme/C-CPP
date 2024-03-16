#include <iostream>

class MiniString
{
private:
	char* mData;
public:
	MiniString()
	{
		std::cout << "Default constructor" << std::endl;
		mData = new char[1];
		mData[0] = '\0';
	}
	MiniString(const char* data)
	{
		std::cout << "Conversion constructor" << std::endl;
		mData = new char[strlen(data) + 1];
		strcpy(mData, data);
	}
	~MiniString() 
	{ 
		std::cout << "Destructor" << std::endl;
		delete[] mData; 
	}
	MiniString(const MiniString& rhs)
	{
		std::cout << "Copy constructor" << std::endl;
		mData = new char[strlen(rhs.mData) + 1];
		strcpy(mData, rhs.mData);
	}
	MiniString& operator=(const MiniString& rhs)
	{
		std::cout << "Copy assignment operator" << std::endl;
		if (this == &rhs)
			return *this;
		delete[] mData;
		mData = new char[strlen(rhs.mData) + 1];
		strcpy(mData, rhs.mData);
		return *this;
	}
	void swap(MiniString& rhs)
	{
		std::swap(mData, rhs.mData);
	}
	operator const char*() const
	{
		return mData;
	}
};

template<typename T>
void swap(T& lhs, T& rhs)
{
	std::cout << "swap" << std::endl;
	T temp(lhs); // copy constructor
	lhs = rhs; // copy assignment operator
	rhs = temp; // copy assignment operator
	std::cout << "~swap" << std::endl;
}

namespace std
{
	template<>
	void	swap<MiniString>(MiniString& lhs, MiniString& rhs)
	{
		std::cout << "std::swap" << std::endl;
		lhs.swap(rhs); // MiniString::swap
		std::cout << "~std::swap" << std::endl;
	}
}

int	main(void)
{
	MiniString s1("World");
	MiniString s2("Hello");

	std::swap(s1, s2);

	std::cout << s1 << ", " << s2 << std::endl;
	return 0;
}
