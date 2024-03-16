#include <iostream>

class TextBlock
{
private:
	std::string text;
public:
	TextBlock(const std::string& str) : text(str) {};
	const char& operator[](std::size_t position) const // 상수 객체에 대한 [] 연산자
	{
		std::cout << "const version" << std::endl;
		return text[position];
	};
	char& operator[](std::size_t position) // 비상수 객체에 대한 [] 연산자(오버로딩)
	{
		std::cout << "non-const version" << std::endl;
		return text[position];
	};
};

int	main(void)
{
	TextBlock tb("Hello");
	const TextBlock ctb("World");

	std::cout << tb[0] << std::endl;

	tb[0] = 'x';

	std::cout << ctb[0] << std::endl;

	// ctb[0] = 'x'; // 상수 객체에 대한 [] 연산자 호출 에러, const char& 타입에 대입 연산을 시도하기 때문에 에러가 발생한다.
	return 0;
}
