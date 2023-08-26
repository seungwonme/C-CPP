#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	*ptr;

	ptr = malloc(200000000000000); // 200조
	if (!ptr)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (0);
}

// malloc: Cannot allocate memory
