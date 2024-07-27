#include "../include/minitalk.h"
#include <stdio.h>

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
		usleep(10);
	}
	return (0);
}

int send_int (int i, int pid)
{
	printf("starting to send int %i\n", i);
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
		usleep(10);
	}
	printf("int %i sent\n", i);
	return (0);
}

int	send_str (char *str, int pid)
{
	while (*str)
	{
		send_char(*str, pid);
		str++;
	}
	return (0);
}
