#include "include/minitalk.h"

t_message	g_message;

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

int main(void)
{
	write_PID();

	signal(SIGUSR1, sigusr1);
	signal(SIGUSR2, sigusr2);
	g_message.text = malloc(sizeof(char) * 2);
	while (1)
		pause();
	return 0;
}
