#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int fd[10000][2];

	for (size_t i = 0; i < 4100; i++)
	{
		if (pipe(fd[i]) == -1)
		{
			printf("i: %zu\n", i);
			perror("pipe");
		}
	}
	return (0);
}

// pipe: Too many open files
