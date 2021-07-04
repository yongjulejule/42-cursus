#include "ft_printf.h"
#include <stdio.h>

int main()
{
	static unsigned int		mx_u = 235;
	static char				mx_c = 'G';
	static char			   *mx_s = "Hello, World!";
	static int				mx_i = 42;
	static long				mx_li =  4223372036854775800;
	static long long		mx_lli = 3223372036654775200;
	static short			mx_hi = -3244;
	static char				mx_hhi = 'F';

	ft_printf("  %hhi    %o    %hi    %c    %s    %li  ",
			mx_c, mx_u, mx_hi, mx_c, mx_s, mx_li);
	printf("  %hhi    %o    %hi    %c    %s    %li  ",
			mx_c, mx_u, mx_hi, mx_c, mx_s, mx_li);
}
