#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	if (dup2(3, 3) < 0)
		perror("dup2");
	return (0);
}

// dup2: Bad file descriptor
