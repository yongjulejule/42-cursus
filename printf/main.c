#include "ft_printf.h"
#include <stdio.h>
int main()
{
	printf("%d", printf("%kaaaaaa\n"));
	printf("%d", ft_printf("%kaaaaaa\n"));
}
