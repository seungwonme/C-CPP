// https://ipcvhomme.tistory.com/3#:~:text=%EC%9E%85%EB%A0%A5%EC%8B%9C%20%25i%EC%99%80%20%25d,%EC%97%AC%EA%B8%B0%EC%84%9C%20%EC%95%BD%EA%B0%84%20%EB%89%98%EC%95%99%EC%8A%A4%EA%B0%80%20%EB%8B%AC%EB%9D%BC%EC%A7%84%EB%8B%A4
// 10 10
// 010 010
// 0x10 0x10
#include <stdio.h>

int	main(void)
{
	int x1, x2;
	scanf("%d", &x1); // %d -> 32bit decimal
	scanf("%i", &x2); // %d -> integer type

	printf("%d %d\n", x1, x2);
	return (0);
}
