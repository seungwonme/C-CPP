#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int ac, char *av[])
{
	(void)	ac;
	char	word[65];
	for (int i = 0; i < 10; i++)
		word[i] = '0' + i;
	for (int i = 10; i < 36; i++)
		word[i] = 'A' - 10 + i;
	for (int i = 36; i < 62; i++)
		word[i] = 'a' - 36 + i;
	word[62] = '-';
	word[63] = '_';
	word[64] = '!';

	srand(time(NULL));
	for (int i = 0; i < atoi(av[1]); ++i)
		printf("%c", word[rand() % 65]);
	printf("\n");
	return (0);
}
