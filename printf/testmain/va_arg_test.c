#include <stdarg.h>
#include <stdio.h>

int sum(int a, ...)
{
	va_list ap;
	va_list cp_ap;
	int		i;

	i = 0;
	va_start(ap, a);
	while (i <10)
	{
		printf("%dth is :%d\n",i, va_arg(ap, int));
		i++;
	}
	va_copy(cp_ap, ap);
	printf("%dth is :%d\n",i, va_arg(cp_ap, int));
	return (222);
}
int main()
{
	int a = 10;

	a = sum(a, 1, 2, 3);
	printf("%d", a);
}
