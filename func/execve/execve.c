#include <unistd.h>

int	main(void)
{
	// char	*av[] = {"ls", "-al", NULL};
	// execve("/bin/ls", av, NULL);

	char	*av[] = {"./a.out", NULL};
	execve("print", av, NULL);

	return (0);
}
