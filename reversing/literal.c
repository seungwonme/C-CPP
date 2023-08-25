#include <stdio.h>

int	main(void)
{
	// 메모리에 대한 접근 권한 RWX

	// Data 영역
	// Data 영역에는 실행권한(X)이 있으면 절대 안된다.
	// Heap   : malloc -> runtime
	// Stack  : 자동변수 -> runtime
	// Static : R-- 문자열   -> build time -> a.out에 저장되어있다.
	//        : RW- static -> build time -> a.out에 저장되어있다.

	// 문자열 상수는 존재하지 않는다.
	// 상수화된 문자 배열이 존재한다 !!

	char *pszParam = "Hello world\n";

	printf("%p\n","Hello world\n");
	printf("%p\n",pszParam);

	printf("%s\n","Hello world\n");
	printf("%s\n",pszParam);
	return (0);
}
