#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[1024 * 1024 * 8]; // 8MB
	strcpy(str, "Hello, World!\n");
	printf("%s", str);
	return (0);
}
