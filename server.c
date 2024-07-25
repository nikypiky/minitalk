#include "include/minitalk.h"

t_holder	holder;

void sigusr1(int signum)
{
	(void)signum;
	holder.char_holder = holder.char_holder << 1;
	holder.bit_counter++;
}

void sigusr2(int signum)
{
	(void)signum;
	holder.char_holder = (holder.char_holder << 1) | 1;
	holder.bit_counter++;
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
		holder.bit_counter = 0;
		while (holder.bit_counter < 8)
		{
			pause();
		}
		nbr[i] = holder.char_holder;
		i--;
	}
	return (*((int *)nbr));
}

void	write_char()
{
	holder.bit_counter = 0;
	signal(SIGUSR1, sigusr1);
	signal(SIGUSR2, sigusr2);
	while (holder.bit_counter < 8)
	{
		pause();
	}
}

int main(void)
{
	t_message	message;
	write_PID();

	// write_char('c');
	message.client_PID = write_int();
	message.len = write_int();
	message.text = malloc(sizeof(char) * message.len);
	if(!message.text)
		return (1);
	printf("pid = %i\nlen = %i", message.client_PID, message.len);
	return 0;
}
