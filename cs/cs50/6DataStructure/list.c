#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	// int list[3];
	int *list = malloc(3 * sizeof(int));
	if (list == NULL)
		return 1;

	list[0] = 1;
	list[1] = 2;
	list[2] = 3;

	// int *tmp = malloc(4 * sizeof(int)); malloc으로 메모리 할당하면 초기화가 필요하다.
	// realloc을 통해 free(old arr)의 과정을 거치치 않아도 된다.
	int *tmp = realloc(list, 4 * sizeof(int));
	if (tmp == NULL)
		return 1;

	// Copy intergers from old array into new array
	// for (int i = 0; i < 3; i++) realloc이 대신 해준다.
	// 	tmp[i] = list[i];
	tmp[3] = 4;

	free(list);

	// list = tmp; realloc이 대신 해준다.

	for (int i = 0; i < 4; i++)
		printf("%i\n",list[i]);
	
	return 0;
}