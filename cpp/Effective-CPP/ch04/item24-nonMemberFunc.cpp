#include <iostream>

class Rational
{
private:
	int n; // numerator
	int d; // denominator
public:
	Rational()
	: n(0)
	, d(1) {};
	Rational(int n) // Conversion constructor
	: n(n)
	, d(1) {};
	Rational(int a, int b)
	: n(a)
	, d(b) {};
	Rational(const Rational& rhs)
	: n(rhs.n)
	, d(rhs.d) {};
	~Rational() {};
	Rational& operator=(const Rational& rhs)
	{
		n = rhs.n;
		d = rhs.d;
		return *this;
	}
	// const Rational operator*(const Rational& rhs) const
	// {
	// 	return Rational(n * rhs.n, d * rhs.d);
	// }
	// const Rational operator*(int rhs) const
	// {
	// 	return Rational(n * rhs, d);
	// }
	// operator double() const
	// {
	// 	return static_cast<double>(n) / d;
	// }
	int GetNumerator() const
	{
		return n;
	}
	int GetDenominator() const
	{
		return d;
	}
};

const Rational operator*(const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.GetNumerator() * rhs.GetNumerator(), lhs.GetDenominator() * rhs.GetDenominator());
}

int	main(void)
{
	Rational oneEighth(1, 8);
	Rational oneHalf(1, 2);

	Rational result = oneHalf * oneEighth;
	result = result * oneEighth;
	std::cout << result.GetNumerator() << "/" << result.GetDenominator() << std::endl;

	result = oneHalf * 2;
	result = 2 * oneHalf;
	// result = 2.operator*(oneHalf);와 같다.
	std::cout << result.GetNumerator() << "/" << result.GetDenominator() << std::endl;
	return 0;
}
