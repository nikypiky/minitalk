#include "include/minitalk.h"

t_message	message;

void sigusr1(int signum)
{
	(void)signum;
	write_0(&message.char_holder);
	message.bit_counter++;
	printf(" test1 - %i char_holder = %i\n", message.char_holder, message.bit_counter);
}

void sigusr2(int signum)
{
	(void)signum;
	write_1(&message.char_holder);
	message.bit_counter++;
	printf(" test2 - %i char_holder = %i\n", message.char_holder, message.bit_counter);
}

int main(void)
{
	write_PID();

	signal(SIGUSR1, sigusr1);
	signal(SIGUSR2, sigusr2);
	message.text = malloc(sizeof(char) * 2);
	while (1)
		pause();
	return 0;
}
