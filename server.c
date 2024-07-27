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

char	write_char()
{
	holder.bit_counter = 0;
	signal(SIGUSR1, sigusr1);
	signal(SIGUSR2, sigusr2);
	while (holder.bit_counter < 8)
	{
		pause();
	}
	return (holder.char_holder);
}

void	write_str(char *str, int len)
{
	int	i;

	i = 0;
	// if(!str)
	// 	return ();
	while (i != len)
	{
		holder.bit_counter = 0;
		signal(SIGUSR1, sigusr1);
		signal(SIGUSR2, sigusr2);
		while (holder.bit_counter < 8)
		{
			pause();
		}
	}
	printf("text = %s\n", str);
}

int main(void)
{
	t_message	message;

	write_PID();
	message.client_PID = write_int();
	printf("pid = %i\n", message.client_PID);
	message.len = write_int();
	printf("len = %i\n", message.len);
	message.text = malloc(sizeof(char) * message.len);
	if (!message.len)
		return (1);
	write_str(message.text, message.len);
	return 0;
}




