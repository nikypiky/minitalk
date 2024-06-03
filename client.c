#include "include/minitalk.h"

int	main (int argc, char** argv)
{
	kill(miniatoi(argv[argc - 1]), SIGUSR1);
	// printf("client %i\n", miniatoi("1234"));
}

