#include <iostream>

char greeting[]  = "Hello";

char* p = greeting; // non-const pointer, non-const data

const char* p1 = greeting; // non-const pointer, const data

char* const p2 = greeting; // const pointer, non-const data

const char* const p3 = greeting; // const pointer, const data

/* 
const가 *의 오른쪽에 있는 경우엔 포인터 자체가 상수다.
const가 *의 왼쪽에 있는 경우엔 포인터가 가리키는 대상이 상수다.
const가 *의 양쪽에 있는 경우엔 포인터 자체가 상수이며, 포인터가 가리키는 대상도 상수다.
*/

// 포인터가 가리키는 대상이 상수일 때 순서를 바꿔도 결과는 같다.
void	f1(const int* p)
{
	p = nullptr; // ok
	std::cout << p << std::endl;
}

void	f2(int const* p)
{
	p = nullptr; // ok
	std::cout << p << std::endl;
}

int	main(void)
{
	const int a = 10;

	f1(&a);
	f2(&a);
	return 0;
}
