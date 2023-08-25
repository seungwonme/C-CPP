#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

int	main(void)
{
	printf("float range  : %E  ~ %E\n", __FLT_MIN__, __FLT_MAX__);
	printf("double range : %E ~ %E\n", __DBL_MIN__, __DBL_MAX__);
	// double 은 해상도가 높기에 신뢰성이 높다
	// 실수는 필연적으로 오차를 일으킬 수 밖에 없다.
	// 실수로 비교연산을 하는 것은 지양하도록 하자.

	float	fdata = 123.125F; // F를 안쓰면 double이다.
	printf("\n%f, %E\n", fdata, fdata);
	return (0);
}
