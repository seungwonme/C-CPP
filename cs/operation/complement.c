// https://whoishoo.tistory.com/123

#include <stdio.h>

int	main(void)
{
	printf("%d\n", 10 - 5);
	printf("%d\n", 10 + (~5 + 1));
	// - 는 사실 2의 보수의 덧셈이다.
	// ~는 비트연산

	remove("a.out");
	remove("tempCodeRunnerFile.c");
	return (0);
}
