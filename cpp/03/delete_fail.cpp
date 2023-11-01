#include <iostream>

// a.out(62833,0x1f08e2080) malloc: *** error for object 0x16b51b028: pointer being freed was not allocated
// a.out(62833,0x1f08e2080) malloc: *** set a breakpoint in malloc_error_break to debug
// [1]    62833 abort      "/Users/anseungwon/dev/cpp/03/"/a.out

int	main()
{
	int	a = 5;

	delete &a;
	return (0);
}
