#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char *str;

	for (size_t i = 0; i < 10; i++)
		str = malloc(1);
	str = NULL;
	while (1)
		;
	return (0);
}
