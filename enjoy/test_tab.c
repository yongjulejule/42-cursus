#include <stdio.h>

int main(int argc, char **argv)
{
	int i = 0;
	int j = 1;

	printf("%d\n", argc);
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			printf("%d, ", argv[j][i]);
			i++;
		}
		j++;
	}
}
