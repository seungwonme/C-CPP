#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	*ptr;

	ptr = malloc(3000000000); // 30억 byte => 약 2.8Gb
	if (!ptr)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (0);
}

// malloc: Cannot allocate memory
