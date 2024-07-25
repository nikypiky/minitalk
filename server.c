#include "include/minitalk.h"

t_message	message;

void sigusr1(int signum)
{
	(void)signum;
	message.char_holder = message.char_holder << 1;
	message.bit_counter++;
}

void sigusr2(int signum)
{
	(void)signum;
	message.char_holder = (message.char_holder << 1) | 1;
	message.bit_counter++;
}

int	write_int()
{
	int		i;
	char	nbr[4];

	i = 3;
	signal(SIGUSR1, sigusr1);
	signal(SIGUSR2, sigusr2);
	while (i >= 0)
	{
		message.bit_counter = 0;
		while (message.bit_counter < 8)
		{
			pause();
		}
		nbr[i] = message.char_holder;
		i--;
	}
	return (*((int *)nbr));
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
}

// int	write_int()
// {
// 	int		i;
// 	char	nbr[4];
// 	int		*ptr;

// 	i = 4;
// 	while (i > 0)
// 	{
// 		write_char();
// 		nbr[i] = message.char_holder;
// 		printf("char_holder = %i\n", i);
// 		i--;
// 	}
// 	ptr = (int *)nbr;
// 	printf("nbr = %i\n", *ptr);
// 	return(*ptr);
// }

int main(void)
{
	write_PID();

	// write_char('c');
	int i =  write_int(message.len);
	printf("i = %i\n", i);
	return 0;
}
