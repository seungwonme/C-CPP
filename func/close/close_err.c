#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	if (close(-1) < 0)
		perror("close");
	return (0);
}

// close: Bad file descriptor
