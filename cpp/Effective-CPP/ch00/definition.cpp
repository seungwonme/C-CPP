#include <iostream>

template <typename T> // 템플릿 정의
class GraphNode
{
private:
	/* data */
public:
	GraphNode(/* args */);
	~GraphNode();
};

class Widget // 클래스 정의
{
public:
	Widget();
	~Widget();
};

std::size_t numDigits(int number) // 함수 정의
{
	std::size_t digitsSoFar = 1;

	while ((number /= 10) != 0)
	{
		++digitsSoFar;
	}
	return digitsSoFar;
}

int x; // 객체 정의

int	main(void)
{

	return 0;
}
