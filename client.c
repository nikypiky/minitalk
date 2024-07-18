#include "include/minitalk.h"

int	main (int argc, char **argv)
{
	int		pid;

	pid = miniatoi(argv[1]);
	(void)argc;
	send_char(66, pid);
	send_char(23, pid);
	return (0);
}


