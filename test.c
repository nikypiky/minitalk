#include <unistd.h>
#include <stdio.h>
#include "include/minitalk.h"

int    main ()
 {
	char	s[4];
	int	*i;

	s[0] = 1;
	s[1] = 1;
	s[2] = 1;
	s[3] = 1;
	i = (int *)s;
	printf("%i", *i);
}
