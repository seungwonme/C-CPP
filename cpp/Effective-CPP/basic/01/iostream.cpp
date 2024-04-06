#include <iostream>

int	main(void)
{
	int a; 
	
	std::cin >> a;
	/* std::cin 객체에 (console in)
	>> 리다이렉션 연산자를 사용하여
	키보드로 입력받은 값을 a에 저장 */

	std::cout << "Hello World!" << std::endl;
	/* std::cout 객체에 (console out)
	<< 리다이렉션 연산자를 사용하여
	"Hello World!" 문자열을 출력
	std::endl 개행문자 출력 */
	return 0;
}
