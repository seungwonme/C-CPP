#include <unistd.h>

int	main(void)
{
	// char	*av[] = {"./a.out", NULL};
	// execve("./print", av, NULL);

	char	*av[] = {"ls", "-al", NULL};
	execve("/bin/ls", av, NULL);
	return (0);
}
