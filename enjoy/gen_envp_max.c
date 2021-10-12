#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	long long i = 0;
	long long max = atoll(argv[1]);
	while (i < max)
	{
		write(1, "a ", 2);
		i++;
	}
}
