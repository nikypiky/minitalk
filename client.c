#include "include/minitalk.h"

int send_char (char c, int pid)
{
	int	bit_test;
	int	j;

	bit_test = 128;
	j = 0;

	while (j < 8)
	{
		if ((c & bit_test) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		j++;
		bit_test = bit_test >> 1;
		sleep(0.1);
	}
	return (0);
}

int send_int (int i, int pid)
{
	unsigned int	bit_test;
	int				j;

	bit_test = 2147483648;
	j = 0;

	while (j < 32)
	{
		if ((i & bit_test) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		j++;
		bit_test = bit_test >> 1;
		sleep(0.1);
	}
	return (0);
}

int	main (int argc, char **argv)
{
	int		pid;

	pid = miniatoi(argv[1]);
	(void)argc;
	send_int(1, pid);
	return (0);
}


