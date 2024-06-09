#include "../include/minitalk.h"

int	digit_nbr(int nbr)
{
	int	str;

	str = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		str++;
	while (nbr)
	{
		nbr /= 10;
		str++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char			*string;
	unsigned int	nbr;
	unsigned int	str;

	str = digit_nbr(n);
	string = (char *)malloc(sizeof(char) * (str + 1));
	if (string == NULL)
		return (NULL);
	if (n < 0)
	{
		string[0] = '-';
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr == 0)
		string[0] = '0';
	string[str] = '\0';
	while (nbr != 0)
	{
		string[str - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		str--;
	}
	return (string);
}

void	write_PID()
{
	write(1, "Server PID = ", 13);
	write(1, ft_itoa(getpid()), 5);
	write(1, "\n", 1);
}
