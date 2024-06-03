	#include "include/minitalk.h"

void	test(int sig)
{
	printf("int arrived = %i", sig);
}

int	main (void)
{
	write_PID();
	pause();
	signal(SIGUSR1, &test);
}
