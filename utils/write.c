#include "../include/minitalk.h"

// void	write_0(int *c)
// {
// 	*c = *c << 1;
// }

// void	write_1(char *c)
// {
// 	*c = *c | 1;
// }

void	write_0(char *c)
{
	*c = *c << 1;
	printf("sigusr1 - %i", *c);
}

void	write_1(char *c)
{
	*c = *c << 1;
	*c = *c | 1;
	printf("sigusr2 - %i", *c);
}
