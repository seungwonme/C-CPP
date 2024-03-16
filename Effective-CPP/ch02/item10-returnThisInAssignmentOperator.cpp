#include <iostream>

class Widget
{
public:
	Widget() {};
	~Widget() {};
	Widget& operator=(const Widget& rhs) // 반환 타입은 현재의 클래스에 대한 참조자
	{
		// ...
		return *this; // 좌변 객체 참조자 반환
	}
	Widget& operator+=(const Widget& rhs) // +=, -=, *= 등에도 동일한 규칙
	{
		// ...
		return *this; // 좌변 객체 참조자 반환
	}
};

int	main(void)
{
	int x, y, z;

	// C++의 대입 연산은 여러 개가 사슬처럼 엮일 수 있는 성질을 지닌다.
	x = y = z = 15;
	// x = (y = (z = 15));
	// z => y => x 순으로 대입된다.

	// 이렇게 대입 연산이 사슬처럼 엮이기 위해서는 대입 연산자가 좌변 인자에 대한 참조자를 반환하도록 구현해야 한다.
	// 이런 구현은 일종의 관례이기 때문에 지키는 편이 좋다.
	std::cout << x << ' ' << y << ' ' << z << std::endl;
	return 0;
}
