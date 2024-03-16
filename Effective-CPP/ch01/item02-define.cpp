#include <iostream>

#define ASPECT_RATIO 1.653
// => const double ASPECT_RATIO = 1.653;
/* 
우리에겐 ASPECT_RATIO가 symbolic name으로 보이지만
컴파일러로 넘어가기 전 전처리기를 거치면서 1.653으로 치환된다.
만약 컴파일 에러가 나면 ASPECT_RATIO가 아닌 1.653으로 에러가 나오기 때문에 에러를 찾기 힘들다.
*/

/* 
m1 mac 환경에서는 보여준다.
❯ g++ define.cpp
define.cpp:17:4: warning: implicit conversion from 'double' to 'int' changes value from 1.653 to 1 [-Wliteral-conversion]
        f(ASPECT_RATIO);
        ~ ^~~~~~~~~~~~
define.cpp:3:22: note: expanded from macro 'ASPECT_RATIO'
#define ASPECT_RATIO 1.653
                    ^~~~~
1 warning generated.
*/

#define NAME "seunan"
// => const char * const Name = "seunan";
// => const std::string Name("seunan");
/* 
포인터가 가리키는 값의 변경이 불가능하다는 의미의 const char
포인터가 가리키는 주소가 변하지 않는다는 의미의 * const
const를 두 번 써야한다.

하지만 문자열 상수를 사용할 때 std::string을 사용하는 것이 더 좋다.
*/

void	f(const int i)
{
	std::cout << i << std::endl;
}

int	main(void)
{
	f(ASPECT_RATIO);
	return 0;
}
