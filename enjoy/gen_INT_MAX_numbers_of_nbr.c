#include <stdio.h>

int main()
{
	int i = 0;

	while (i < 2147483647)
	{
		printf("%d\n", i);
		i++;
	}
}
