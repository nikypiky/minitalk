#include "../include/minitalk.h"

int	miniatoi(char* str)
{
	int		result;

	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	return ((result));
}
