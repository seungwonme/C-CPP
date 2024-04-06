#include <iostream>

class Test
{
private:
	int& mData;
	// 1. Initialization in the declaration ERROR!!
	// int& mData = 1;
public:
	// 2. Initialization in the constructor body ERROR!!
	// Test(int& data)
	// {
	// 	// 선언 후 대입 연산이기 때문에 에러가 발생한다. (레퍼런스는 선언과 동시에 초기화가 되어야 한다.)
	// 	mData = data;
	// 	std::cout << "Default Constructor" << std::endl;
	// };
	// 3. Initialization in the constructor with member initializer list
	Test(int& data)
	: mData(data)
	{
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

// 레퍼런스 멤버 변수는 반드시 초기화 리스트를 사용하여 초기화를 해야 한다.

int	main(void)
{
	Test test; // 디폴트 생성자가 없기 때문에 에러가 발생한다. (디폴트 생성자는 생성자가 하나도 없을 때 컴파일러가 자동으로 생성해주는 생성자이다.)
	return 0;
}
