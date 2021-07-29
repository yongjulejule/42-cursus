#include <stdlib.h>
#include <stdio.h>

int	g_i;

void	function_location()
{
	int i;
	static int static_func_i;

	printf("in function, int i address is %p\n", &i);
	printf("in function, static int i address is %p\n", &static_func_i);
}

int main(int argc, char **argv)
{
	char	*a = malloc(10);
	int		i;
	static int static_i;

	function_location();
	printf("in main, malloced char *address is %p\n", a);
	printf("in main, int i address is %p\n", &i);
	printf("in main, static int i address is %p\n", &static_i);
	printf("in main, argc address is %p\n", &argc);
	printf("in main, argv address is %p\n", argv);
}
