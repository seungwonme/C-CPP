#include <stdio.h>

void	ft_swap(int *pA, int *pB)
{
	int	nTmp;

	nTmp = *pA;
	*pA = *pB;
	*pB = nTmp;
}

int	main(void)
{
	int	x = 3, y = 4;
	ft_swap(&x, &y);
	printf("x = %d, y = %d\n", x, y);
	return (0);
}
