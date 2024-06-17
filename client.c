#include "include/minitalk.h"

int	main (int argc, char **argv)
{
	int		i;
	int		pid;
	char	bit_test;
	char	test = 'a';

	bit_test = 0b10000000;
	pid = miniatoi(argv[1]);
	i = 0;
	(void)argc;
	// if (argc != 3)
	// {
	// 	write(1, "Please input server PID and message.\n", 26);
	// 	return(1);
	// }
	while (i <= 8)
	{
		if ((test & bit_test) == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				perror("Error sending signal"); // Prints the error message and reason
				return 1;
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				perror("Error sending signal"); // Prints the error message and reason
				return 1;
			}
		}
		test = test << 1;
		i++;
		sleep(1);
	}
	return (0);
}


