#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	int	a = 100;
	int	*b = &a;
	int	**c = &b;
	int	***d = &c;
	int	****e = &d;
	int	*****f = &e;
	int	******g = &f;
	printf("&a      : %p\n", &a);
	printf("*****g  : %p\n", *****g);
	printf("b       : %p\n", b);
	printf("****g   : %p\n", ****g);
	printf("c       : %p\n", c);
	printf("***g    : %p\n", ***g);
	printf("d       : %p\n", d);
	printf("**g     : %p\n", **g);
	printf("e       : %p\n", e);
	printf("*g      : %p\n", *g);
	printf("f       : %p\n", f);
	printf("g       : %p\n", g);
	printf("a       : %d\n" , a);
	printf("******g : %d\n", ******g);
	remove("a.out");
	remove("tempCodeRunnerFile.c");
	return (0);
}
