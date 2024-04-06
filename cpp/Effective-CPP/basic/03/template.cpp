#include <iostream>

// 컴파일러가 템플릿 함수가 필요할 때마다 그에 맞는 함수를 자동으로 생성
// 제작자 관점에서 생산성이 높아짐
// 형에 의존하지 않는 코드를 작성할 수 있음
template <typename T>
T add(T a, T b)
{
	return a + b;
}

int	main(void)
{
	std::cout << add(3, 4) << std::endl;
	std::cout << add(3.3, 4.4) << std::endl;
	std::cout << add(std::string("Hello, "), std::string("World !")) << std::endl;
	return 0;
}
