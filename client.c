#include "include/minitalk.h"

int	main (int argc, char **argv)
{
	int		pid;

	pid = miniatoi(argv[1]);
	(void)argc;
	send_int(126876543, pid);
	return (0);
}


