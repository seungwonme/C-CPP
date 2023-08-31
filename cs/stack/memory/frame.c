#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	int	a[10];
	a[0] = 0x12345678;
	a[1] = 0x87654321;
	a[2] = 0xdeadbeef;
	a[3] = 0xfeedface;
	a[4] = 0x00000000;
	a[5] = 0xffffffff;
	a[6] = 0x11111111;
	a[7] = 0x22222222;
	a[8] = 0x33333333;
	a[9] = 0x44444444;

	for (size_t i = 0; i < 10; i++)
		printf("%p\n", &a[i]);
	printf("\n");
	int	b[10];
	for (size_t i = 0; i < 10; i++)
		printf("%p\n", &b[i]);
	printf("\n");
	int	c[10];
	for (size_t i = 0; i < 10; i++)
		printf("%p\n", &c[i]);
	int	d;
	printf("%p\n", &d);
	return (0);
}
