#include <stdio.h>

int main(void)
{
	// little endian, big endian
	int	a;
	int	*p;

	p = &a;
	printf("0x%p\n", &a);
	a = 0x00112233;
	printf("0x%08x\n", a);
	a = 0x33221100;
	printf("0x%08x\n", a);
	return (0);
}
