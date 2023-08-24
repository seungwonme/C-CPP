#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(void)
{
	pid_t	pid;

	pid = fork(); // fork() returns 0 to the child process and returns the pid of the child process to the parent process.
	if (pid == -1)
	{
		printf("Error\n");
		return (1);
	}
	if (pid == 0)
	{
		printf("My pid is %d\n", getpid());
		while (1)
			;
	}
	else
	{
		printf("My child pid is %d\n", pid);
		waitpid(pid, NULL, 0);
	}
	return (0);
}
