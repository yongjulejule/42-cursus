#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <locale.h>
#include <wchar.h>
int main()
{
	
	setbuf(stdout, NULL);
	setlocale(LC_ALL, "en_US.UTF-8");
	printf("========================== CHAR TEST ===========================\n"); 
	unsigned char my_char[4];
	wchar_t b = L'오';
	unsigned char* d;
	d = (unsigned char*)&b;
	printf("%x\n",d[0]);
	printf("%x\n", b);
	printf("%x\n", (unsigned char)b);
	printf("%x\n", (unsigned char)(b>>4));
	printf("%x\n", (unsigned char)(b>>8));
	printf("%x\n", (unsigned char)(b>>12));
	printf("\n\n\n");
	printf("bit cal::%lc\n\n\n", L'🔥');
	wchar_t c_1 = L'오';
	printf("\n\n%x\n\n", c_1);

	write(1, &c_1, 4);
//	unsigned char *a = (unsigned char*)"오";
//	printf("\n a =%d", *(a + 1));
	my_char[0] = (unsigned char)236;
	my_char[1] = (unsigned char)152;
	my_char[2] = (unsigned char)164;
	int j = 0;
	write(1, "\n", 1);
	while (j < 3)
	{	
		write(1, &my_char[j], 1);
		j++;
	}
//	write(1, "\n", 1);
//	printf("\n|%s|\n", my_char);
//	int i = 0;
//	unsigned char *test = (unsigned char*)"오늘도 밤샐까?";
//	while (test[i])
//	{
//		printf("%d\n", (int)test[i]);
//		i++;
//	}
//	
//	printf("%lc", (wchar_t)(1000));
//	printf("%zu", sizeof(wchar_t*));
//	int t;
//	t = 10L;
//	printf("\ntype size : %zu\n", sizeof(size_t));
}
//11101100 10011000 10100100
