#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int (*arr)[2];

	arr = malloc(sizeof(int) * 1000);

	for (size_t i = 0; i < 1000; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			arr[i][j] = i + j;
			printf("%d\n", arr[i][j]);
		}
	}
	return (0);
}
