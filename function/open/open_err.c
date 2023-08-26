#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	if (open("no_file", O_RDONLY) == -1)
		perror("open");
	if (open("permission_denied", O_RDONLY) == -1)
		perror("open");
	return (0);
}
