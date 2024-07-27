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
	char string[] = "hello world";

	pid = miniatoi(argv[1]);
	// signal(SIGUSR1, wait_4_signal);
	(void)argc;
	// printf("pid real = %i\n", getpid());
	send_int(getpid(), pid);
	// pause();
	send_int(ft_strlen(string), pid);
	// printf("strlen = %li\n", ft_strlen(string));
	// // pause();
	send_str(string, pid);
	return (0);
}


