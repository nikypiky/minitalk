#include "../include/minitalk.h"

void sigusr1(int signum)
{
	(void)signum;
	write_0(&g_message.len);
	printf(" test1 - %i\n", g_message.len);
}

void sigusr2(int signum)
{
	(void)signum;
	write_1(&g_message.len);
	printf(" test2 - %i\n", g_message.len);
}

int write_client_PID(int client_PID)
{
	signal(SIGUSR1, sigusr1);
	signal(SIGUSR2, sigusr2);
	while (1)
		pause();
}
