#include <iostream>
#include <unistd.h>

class Widget
{
private:
	/* data */
public:
	Widget()
	{
		std::cout << "Default Constructor" << std::endl;
	}
	~Widget()
	{
		std::cout << "Destructor" << std::endl;
	}
	Widget(const Widget& rhs)
	{
		std::cout << "Copy Constructor" << std::endl;
	}
	Widget& operator=(const Widget& rhs)
	{
		std::cout << "Copy Assignment Operator" << std::endl;
		return *this;
	}
};

int	main(void)
{
	Widget w1; // 기본 생성자 호출

	Widget w2(w1); // 복사 생성자 호출
	// Widget w2 = w1; // 복사 생성자 호출

	w1 = w2; // 복사 대입 연산자 호출
	sleep(100);
	return 0;
}
