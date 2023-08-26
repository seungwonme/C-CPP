#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char	*av[] = {"ls", "-al", NULL};
	if (execve("/sbin/ls", av, NULL) == -1)
		perror("execve");
	return (0);
}

// execve: No such file or directory
