#include <signal.h>

int	main(void)
{
	kill(0, SIGINT);
	return (0);
}