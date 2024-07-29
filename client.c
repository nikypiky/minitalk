#include "include/minitalk.h"
#include <signal.h>

void	wait_4_signal(int signum)
{
	(void)signum;
	printf("signal received\n");
}

int	main (int argc, char **argv)
{
	int		pid;
	char string[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
	(void)argc;
	pid = miniatoi(argv[1]);

	// // signal(SIGUSR1, wait_4_signal);
	// // printf("pid real = %i\n", getpid());
	// send_int(getpid(), pid);
	// // pause();
	// send_int(ft_strlen(string), pid);
	// printf("strlen = %li\n", ft_strlen(string));
	// // pause();
	send_str(string, pid);
	return (0);
}


