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
size_t	ft_strlen(const char *c);
int		send_str (char *str, int pid);


typedef struct s_message
{
	int		client_PID;
	int		len;
	char	*text;
}	t_message;

typedef struct s_holder
{
	char	char_holder;
	int		bit_counter;
}	t_holder;

# define INT_BIT_TEST 2147483648

#endif
