#include <unistd.h>

int	main(void)
{
	char	*av[] = {"/bin/ls", "-l", "-a", "-R", NULL};
	execve(av[0], av, NULL);

	// char	*av[] = {"./a.out", NULL};
	// execve("print", av, NULL);

	return (0);
}
