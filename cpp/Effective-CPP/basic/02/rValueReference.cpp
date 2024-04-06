#include <iostream>

int	main(void)
{
	int a(3), b(4), c;

	c = a + b;
	// l-value: c
	// r-value: a + b

	// a + b가 임시 객체로 생성되어 c에 대입된다.

	int &&rData = a + 5; 
	// r-value 참조자는 임시 객체를 참조할 수 있다.
	return 0;
}
