#include <stdio.h>
#include <stdlib.h>
int		get_most_sigf_bit(int num)
{
	int	cnt;

	if (num == 0)
		return (1);
	cnt = 0;
	while ((num >> cnt) != 0)
		cnt++;
	return (cnt);
}

int main(int argc, char **argv)
{
	int shift = 0;
	printf("%d\n", get_most_sigf_bit(atoi(argv[1])));
	printf("-shift = %d\n", atoi(argv[1]) >> (shift - 1));
}
