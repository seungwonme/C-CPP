#include <iostream>

// 비교를 통해 처리한 결과가 달라진다.
#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b)) 

void f(int x) 
{
	std::cout << "Max value: " << x << std::endl;
}

// 기존 매크로의 효율을 그대로 유지함은 물론 정규 함수의 모든 동작 방식 및 타입 안전성까지 보장한다.
// T가 정확히 무엇인지 모르기 때문에 매개변수로 상수 객체에 대한 참조자를 쓴다.
template<typename T>
inline void callWithMax(const T& a, const T& b)
{
	f(a > b ? a : b);
}

int	main(void)
{
	int a = 5, b = -10;

	CALL_WITH_MAX(++a, b); // a가 두 번 증가한다.
	CALL_WITH_MAX(++a, b + 10); // a가 두 번 증가한다.

	a = 5, b = -10;

	callWithMax(++a, b); // a가 한 번 증가한다.
	callWithMax(++a, b + 10); // a가 한 번 증가한다.
	return 0;
}
