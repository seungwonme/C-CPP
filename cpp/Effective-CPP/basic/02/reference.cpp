#include <iostream>

// 포인터 값을 전달받아 해당 포인터가 가리키는 변수의 값을 변경하는 함수
void	call_by_value(int* a)
{
	*a += 10;
}

// 참조를 이용하여 해당 변수의 값을 변경하는 함수
void	call_by_reference(int &a)
{
	a += 10;
}

int	main(void)
{
	int a = 10;

	call_by_value(&a);
	std::cout << "call_by_value    : " << a << std::endl;

	call_by_reference(a);
	std::cout << "call_by_reference: " << a << std::endl;
	return 0;
}
