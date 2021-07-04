#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int	b;
	int x;
	int c;

	b = 10;
	c = L'🤦';
	x = INT_MAX;
	ft_printf("-->|%lc|<--\n", c);
	ft_printf("-->|1.%#0*.2x,3.%x 4.%x 5.%x 6.%x|<--\n", 4, x, x);
}
