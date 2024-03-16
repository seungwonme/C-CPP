#include <iostream>

class Point
{
private:
	int x;
	int y;
public:
	int GetX() const
	{
		return x;
	}
	int GetY() const
	{
		return y;
	}
};

Point p; // 전역변수로 선언한 Point 클래스의 객체는 확실히 0으로 초기화된다.

int x; // 전역변수로 선언한 변수는 확실히 0으로 초기화된다.

int	main(void)
{
	int x; // 초기화되지 않은 변수

	std::cout << ::x << std::endl; // 전역변수 x의 값인 0이 출력된다.
	std::cout << x << std::endl; // 지역변수 x의 값인 쓰레기 값이 출력된다.

	Point p;

	std::cout << ::p.GetX() << std::endl; // 전역변수 Point 클래스의 멤버변수 x의 값인 0이 출력된다.
	std::cout << ::p.GetY() << std::endl; // 전역변수 Point 클래스의 멤버변수 y의 값인 0이 출력된다.
	std::cout << p.GetX() << std::endl; // Point 클래스의 멤버변수 x의 값인 쓰레기 값이 출력된다.
	std::cout << p.GetY() << std::endl; // Point 클래스의 멤버변수 y의 값인 쓰레기 값이 출력된다.

	return 0;
}
