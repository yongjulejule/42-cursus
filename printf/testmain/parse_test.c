#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>
int	main(void)
{
	setlocale(LC_ALL, "en_US.UTF-8");
	ft_printf("This is |%-+ #0123.*ls|\n", 10, L"PARSE🔥\n");
	printf("This is |%-+ #0123.*ls|\n", 10, L"PARSE🔥\n");
	ft_printf("|%%%%%d%hd%%%*.*d%0- +23.32%d%s%```````````````bbbbbbbbbbbbbbbb|\n", 1, (short)2, 3, 4,  5, "abc");
}
