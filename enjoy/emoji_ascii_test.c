#include <unistd.h>
#include <stdio.h>
int main()
{
	unsigned char test[] = "🤪";

	int i = -1;
	while (++i < 3)
		printf("%d,",test[i]);
}
