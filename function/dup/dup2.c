#include <unistd.h>

int	main(void)
{
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execve("/bin/ls", (char *[]){"ls", "-al", NULL}, NULL);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		execve("/usr/bin/wc", (char *[]){"wc", "-l", NULL}, NULL);
	}
	return (0);
}
