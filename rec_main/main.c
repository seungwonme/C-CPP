// main 함수도 처음에 실행되는 함수일뿐이므로 재귀함수로 구현도 가능하다.

#include <stdio.h>

int	main(int ac, char *av[])
{
	if (ac > 0)
		main(ac - 1, av);
	printf("%s\n", av[ac]);
	return (0);
}
