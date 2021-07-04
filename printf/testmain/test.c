#include <stdio.h>
#include <unistd.h>
#include "printf/ft_printf.h"
#include <limits.h>

int i;

int num(int a, ...)
{
	va_list ap;
	int b;

	va_start(ap, a);
	b = va_arg(ap, int);
	return (b);

}

int main()
{
	num(1);
	i = 10;
	t_ull add;

	printf("%d", !(1 && (3 == 1)));
	printf("%d", !(INT_MAX));
	add = (t_ull)&i;
	printf("%hhx\n", (char)((char)CHAR_MIN));
	printf("%hhx\n", (char)((char)-1));
	printf("%hhx\n", (char)((char)CHAR_MIN + (char)1));
	printf("%hhx\n", (char)((char)CHAR_MAX));
	printf("%hhx\n", (char)((char)CHAR_MIN * (char)-1));
	printf("%hx\n", (short)((short)SHRT_MIN));
	printf("%hx\n", (short)((short)SHRT_MIN * (short)-1));
	printf("%x\n", (int)((int)INT_MIN));
	printf("%x\n", (int)((int)INT_MIN * (int) -1));
	printf("%p\n", &i);
	printf("%llx\n", add);
//	int num1;
//	t_ull a[1];
//	printf("123%n6789\n", &num1); // 123456789
//	printf("num : %d\n", num1); // 3
//	printf("12345%n6789\n", &num1); // 123456789
//	printf("num : %d\n", num1); // 5
//	printf("1%n6789\n", &num1); // 16789
//	printf("num : %d\n", num1); // 1
//	printf("%*d, %lln\n", INT_MAX - 1, 42, a);
//	printf("%lld", *a);
}
