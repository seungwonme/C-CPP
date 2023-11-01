#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	pid_t	pid;

	for (size_t i = 0; i < 2304; i++)
	{
		pid = fork();
		if (pid == 0)
			exit(0);
		else
		{
			if (pid == -1)
				perror("fork");
		}
	}

	return (0);
}

// fork: Resource temporarily unavailable
