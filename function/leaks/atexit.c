#include <stdio.h>
#include <stdlib.h>

void	leak(void);

int	main(void)
{
	atexit(leak);

	char* str = malloc(500);
	for (size_t i = 0; i < 50; i++)
		str[i] = 32 + i;
	printf("%s\n", str);
	free(str);
	return (0);
}

void	leak(void)
{
	// system("leaks a.out");
	// system("leaks a.out > leaks_result_temp;");
	// system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked ");
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
}
