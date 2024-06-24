#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <signal.h>

void	write_PID();
int		miniatoi(char* str);

typedef struct s_message
{
	int		client_PID;
	int		len;
	char	*text;
}	t_message;

# define INT_BIT_TEST 2147483648

#endif
