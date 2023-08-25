#include <stdio.h>

int	main(void)
{
	int	a[10];
	for (size_t i = 0; i < 10; i++)
		a[i] = 0x00112233 + i;
	for (size_t i = 0; i < 10; i++)
		printf("%p: %08x\n", &a[i], a[i]);
	for (size_t i = 0; i < 10; i++)
		a[i] = 0x33221100 + i;
	for (size_t i = 0; i < 10; i++)
		printf("%p: %08x\n", &a[i], a[i]);
	return (0);
}
