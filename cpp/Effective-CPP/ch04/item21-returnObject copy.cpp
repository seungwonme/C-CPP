#include <iostream>

class Rational
{
private:
	int n; // numerator
	int d; // denominator
public:
	Rational()
	: n(0), d(1) {};
	Rational(int a, int b)
	: n(a), d(b) {};
	~Rational() {};
	// friend const Rational& operator*(const Rational& lhs, const Rational& rhs)
	// {
	// 	return Rational(lhs.n * rhs.n, lhs.d * rhs.d);
		// Rational(lhs.n * rhs.n, lhs.d * rhs.d)은 스코프를 벗어나면서 소멸되므로 참조자를 반환하면 안된다.
	// }
	// const Rational& operator*(const Rational& rhs) const
	// {
	// 	Rational result(n * rhs.n, d * rhs.d);
	// 	return result;
	// 	// result는 스코프를 벗어나면서 소멸되므로 참조자를 반환하면 안된다.
	// }
	const Rational& operator*(const Rational& rhs) const
	{
		static Rational result(n * rhs.n, d * rhs.d);
		return result;
		// 스레드 안전성 문제가 있다.
	}
	bool operator==(const Rational& rhs) const
	{
		return (n == rhs.n && d == rhs.d);
	}
	void Print()
	{
		std::cout << n << "/" << d << std::endl;
	}
};


int	main(void)
{
	// Rational a(1, 2);
	// Rational b(3, 5);

	// Rational c = a * b;
	// c.Print();

	Rational a(1, 2), b, c, d(2, 9);

	// static으로 반환하면 항상 true가 나온다.
	// (a * b), (c * d)는 static Rational result를 가리키는 임시 객체이므로 같은 주소를 가리킨다.
	if ((a * b) == (c * d))
		std::cout << "equal" << std::endl;
	else
		std::cout << "not equal" << std::endl;
	return 0;
}
