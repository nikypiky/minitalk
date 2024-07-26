#include "include/minitalk.h"
#include <signal.h>

void	wait_4_signal(int signum)
{
	(void)signum;
}

int	main (int argc, char **argv)
{
	int		pid;
	char string[] = "hello world";

	pid = miniatoi(argv[1]);
	// signal(SIGUSR1, wait_4_signal);
	(void)argc;
	send_int(getpid(), pid);
	/* pause(); */
	send_int(ft_strlen(string), pid);
	/* pause(); */
	/* send_str(string, pid); */
	return (0);
}


