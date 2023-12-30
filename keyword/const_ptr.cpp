#include <iostream>
#include <algorithm>
using namespace std;

// 포인터가 가리키는 변수의 값을 바꿀 수 없음
void	const_char()
{
	char a = 'a';
	char b = 'a';
	const char* ptr = &a;
	// *ptr = 'a'; // error
	ptr = &b;
	cout << *ptr << '\n';
}

// 포인터 값을 바꿀 수 없음
void	char_const()
{
	char a = 'a';
	char b = 'a';
	char* const ptr = &a;
	*ptr = 'b';
	// ptr = &b; // error
	cout << *ptr << '\n';
}

int	main(void)
{
	const_char();
	char_const();
	return 0;
}
