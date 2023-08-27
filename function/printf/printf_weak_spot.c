#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	*str;
	int		i;

	scanf("%s", str);
	// %s, %p 문자열을 넣었을 때 등의 취약점이 존재한다.
	printf(str);
	return (0);
}
