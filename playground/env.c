#include <stdio.h>

int	main(int argc, char *argv[], char *envp[])
{
	for (size_t i = 0; envp[i] != NULL; i++)
		printf("envp[%zu]: %s\n", i, envp[i]);
	return (0);
}

// https://stackoverflow.com/questions/54723587/what-does-envp-stand-for
