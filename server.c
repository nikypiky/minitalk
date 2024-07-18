#include "include/minitalk.h"

t_message	message;

void sigusr1(int signum)
{
	(void)signum;
	write_0(&message.char_holder);
	message.bit_counter++;
	// printf(" test1 - %i char_holder = %i\n", message.char_holder, message.bit_counter);
}

void sigusr2(int signum)
{
	(void)signum;
	write_1(&message.char_holder);
	message.bit_counter++;
	// printf(" test2 - %i char_holder = %i\n", message.char_holder, message.bit_counter);
}

int	write_int(char *nbr)
{
	int	i;

	i = 0;
	signal(SIGUSR1, sigusr1);
	signal(SIGUSR2, sigusr2);
	while (i < 4)
	{
		message.bit_counter = 0;
		while (message.bit_counter < 8)
		{
			pause();
		}
		nbr[i] = message.char_holder;
		i++;
	}
	return (0);
}

int main(void)
{
	write_PID();

	write_int(message.client_PID);
	write_int(message.len);
	printf("pid = %i, len = %i", (int)*message.client_PID, (int)*message.len);
	return 0;
}
