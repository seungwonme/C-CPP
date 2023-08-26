#include <signal.h>

int	main(void)
{
	signal(SIGINT, SIG_IGN);
	return (0);
}
