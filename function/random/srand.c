#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("1. rand()\n");
	printf("rand : %d\n", rand());
	printf("rand : %d\n", rand());

	printf("2. rand()와 동일한 시드의 srand()\n");
	srand(32323);
	printf("rand : %d\n", rand());
	srand(32323);
	printf("rand : %d\n", rand());
	srand(32323);
	printf("rand : %d\n", rand());

	printf("3. rand()와 4개의 시드 srand()\n");
	for (int i = 0; i < 4; ++i)
	{
		srand(i);
		printf("rand : %d\n", rand());

	}
	return 0;
}
