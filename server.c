#include "include/minitalk.h"

t_message	message;

void sigusr1(int signum)
{
	(void)signum;
	message.char_holder = message.char_holder << 1;
	// printf("sigusr1 bit_counter = %i\n", message.bit_counter);
	message.bit_counter++;
}

void sigusr2(int signum)
{
	(void)signum;
	message.char_holder = (message.char_holder << 1) | 1;
	// message.char_holder = message.char_holder | 1;
	// printf("sigusr2 bit_counter = %i\n", message.bit_counter);
	message.bit_counter++;
}

int	write_int(char *nbr)
{
	int	i;

	i = 0;
	// (void)nbr;
	signal(SIGUSR1, sigusr1);
	signal(SIGUSR2, sigusr2);
	while (i < 4)
	{
		message.bit_counter = 0;
		while (message.bit_counter < 8)
		{
			// printf("bit_counter = %i\n", message.bit_counter);
			pause();
		}
		printf("%c\n", message.char_holder);
		nbr[4 - i] = message.char_holder;
		i++;
		printf("i = %i\n", (int) *nbr);
	}
	return (0);
}

void	write_char()
{
	message.bit_counter = 0;
	signal(SIGUSR1, sigusr1);
	signal(SIGUSR2, sigusr2);
	while (message.bit_counter < 8)
	{
		pause();
	}
	printf("%c\n", message.char_holder);
}

int main(void)
{
	write_PID();

	write_char('c');
	// write_int(message.len);
	printf("char_holder = %c\n", message.char_holder);
	// printf("message.len = %i\n", (int)*message.len);
	// printf("pid = %i, len = %i", (int)*message.client_PID, (int)*message.len);
	return 0;
}
