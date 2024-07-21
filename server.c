#include "include/minitalk.h"

t_message	message;

void sigusr1(int signum)
{
	(void)signum;
	message.char_holder = message.char_holder << 1;
	message.bit_counter++;
	// // printf(" test1 - %i char_holder = %i\n", message.char_holder, message.bit_counter);
	// printf("sigusr1\n");
}

void sigusr2(int signum)
{
	(void)signum;
	message.char_holder = (message.char_holder << 1) | 1;
	// message.char_holder = message.char_holder | 1;
	message.bit_counter++;
	// // printf(" test2 - %i char_holder = %i\n", message.char_holder, message.bit_counter);
	// printf("sigusr2\n");
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

char	write_char(char	c)
{
	(void)c;
	signal(SIGUSR1, sigusr1);
	signal(SIGUSR2, sigusr2);
	message.bit_counter = 0;
	while (message.bit_counter < 8)
	{
		pause();
		printf("bit_counter = %i/n", message.bit_counter);
	}
	printf("%c\n", message.char_holder);
	return('c');
}

int main(void)
{
	write_PID();

	write_char('c');
	// write_int(message.len);
	// printf("message.len = %i\n", (int)*message.len);
	// printf("pid = %i, len = %i", (int)*message.client_PID, (int)*message.len);
	return 0;
}
