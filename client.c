#include "include/minitalk.h"

int	main (int argc, char **argv)
{
	int		pid;

	pid = miniatoi(argv[1]);
	(void)argc;
	send_int(126, pid);
	return (0);
}


