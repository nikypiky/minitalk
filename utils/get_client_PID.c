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

int	get_client_PID(t_message *message)
{

}
