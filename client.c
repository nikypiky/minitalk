#include "include/minitalk.h"

int	main (int argc, char **argv)
{
	int		i;
	int		pid;
	char	bit_test;
	char	test = 'a';

	bit_test = 0b00000001;
	pid = miniatoi(argv[argc - 1]);
	i = 0;
	// if (argc != 3)
	// {
	// 	write(1, "Please input server PID and message.\n", 26);
	// 	return(1);
	// }
	while (i <= 8)
	{
		if ((test & bit_test) != 1)
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
				return 1;if (kill(pid, SIGUSR2) == -1)
			{
				perror("Error sending signal"); // Prints the error message and reason
				return 1;
			}
			}
		}
		test = test >> 1;
		i++;
	}
	if (kill(pid, SIGUSR1) == -1)
	{
		printf("error %s\n", argv[1]);
		perror("Error sending signal"); // Prints the error message and reason
		return 1;
	}
    	printf("client %i\n", miniatoi("1234"));
}


