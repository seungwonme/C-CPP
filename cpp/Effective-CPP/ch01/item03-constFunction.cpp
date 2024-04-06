#include <iostream>

class Rational
{
private:
	int mData;
public:
	Rational() : mData(0) {};
	Rational(int n) : mData(n) {};
	// Rational operator*(const Rational& rhs) // (a * b) = c; 문법 위반이 발생하지 않는다.
	const Rational operator*(const Rational& rhs)
	{
		return Rational(mData * rhs.mData);
	}
	friend std::ostream& operator<<(std::ostream& os, const Rational& rhs)
	{
		os << rhs.mData;
		return os;
	}
};

int	main(void)
{
	Rational a(2), b(5), c;

	// (a * b) = c; // operator*의 반환값을 const로 선언하면 컴파일러가 에러를 발생시킨다.
	c = a * b;
	std::cout << c << std::endl;
	return 0;
}
