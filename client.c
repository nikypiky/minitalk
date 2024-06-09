#include "include/minitalk.h"

int	main (int argc, char **argv)
{
	// printf("argc = %i argv = %s", argc, argv[1]);
	if (argc != 2)
	{
		write(1, "Please input server PID.\n", 26);
		return(1);
	}
	if (kill(miniatoi(argv[1]), SIGUSR1) == -1) {
		printf("error %s\n", argv[1]);
        perror("Error sending signal"); // Prints the error message and reason
        return 1;
    }	// printf("client %i\n", miniatoi("1234"));
}


