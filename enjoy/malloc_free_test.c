#include <stdlib.h>

/*
** if u move malloc-ed memory and free it, consider it as not malloc-ed
*/

int main()
{
	char *mem;
	char *tmp;

	mem = malloc(10);
	tmp = mem + 2;
	free(tmp);
	free(mem);
}
