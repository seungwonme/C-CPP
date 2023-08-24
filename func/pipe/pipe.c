#include <unistd.h>

int	main(void)
{
	char	buf[100] = {0};
	int		fd[2];

	pipe(fd);
	write(fd[1], "hello ", 6);
	write(fd[1], "world!\n", 7);

	read(fd[0], buf, 13);
	write(1, buf, 13);
	return (0);
}
