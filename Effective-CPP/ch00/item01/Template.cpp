// 3. 템플릿 C++

/* 
템플릿은 일반화 프로그래밍을 위한 도구로, 함수나 클래스를 일반화하여 여러 데이터 타입에 대해 동작하도록 할 수 있다.
컴파일 시점에서 타입이 정해지므로 실행 속도가 빠르며, 코드 중복을 피할 수 있다.
예를 들어, 템플릿을 사용하면 같은 로직을 가진 함수나 클래스를 여러 데이터 타입에 대해 사용할 수 있다.
*/

#include <iostream>

template <typename T>
T Add(T a, T b)
{
	return a + b;
}

template <unsigned int N>
unsigned int Factorial()
{
	return N * Factorial<N - 1>();
}

template <>
unsigned int Factorial<0>()
{
	return 1;
}

int	main(void)
{
	std::cout << "1 + 2 = " << Add(1, 2) << std::endl;
	std::cout << "1.1 + 2.2 = " << Add(1.1, 2.2) << std::endl;

	std::cout << "5! = " << Factorial<5>() << std::endl;
	return 0;
}
