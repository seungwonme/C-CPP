#include <iostream>

class CTextBook
{
private:
	char *mpText;
public:
	CTextBook(char* text) : mpText(text) {};
	char& operator[](std::size_t position) const // 상수 객체에 대한 [] 연산자
	{
		return mpText[position];
	};
	friend std::ostream& operator<<(std::ostream& os, const CTextBook& rhs)
	{
		os << rhs.mpText;
		return os;
	}
};

int	main(void)
{
	char greeting[] = "Hello";
	const CTextBook ctb(greeting); // 상수 객체를 선언

	char* pc = &ctb[0];

	*pc = 'J';

	std::cout << ctb << std::endl;
	return 0;
}
