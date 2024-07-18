#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <signal.h>

void	write_PID();
int		miniatoi(char* str);
int		send_char (char c, int pid);
int		send_int (int i, int pid);
void	write_0(char *c);
void	write_1(char *c);

typedef struct s_message
{
	char	client_PID[4];
	char	len[4];
	char	*text;
	char	char_holder;
	int		bit_counter;
}	t_message;

# define INT_BIT_TEST 2147483648

#endif
