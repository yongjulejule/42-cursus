#include <stdio.h>
#include "../ft_printf.h"
#include <locale.h>

int	address;
int main()
{
	setlocale(LC_ALL, "en_US.UTF-8");
 	static char *addheap;
	addheap = malloc(4242);
	static int i;
	i = 20;
	printf("============================!!!MY PRINTF!!!============================\n");
	printf("============================This is String!============================\n");
	ft_printf("MY  : |%*.*s|\n", 100, 5, "hello printf");
	printf("LIB : |%*.*s|\n", 100, 5, "hello printf"); ft_printf("MY  : |%*.s|\n", 100, "hello printf");
	printf("LIB : |%*.s|\n", 100, "hello printf");
	ft_printf("MY  : |%*.7s|\n", 100, "hello printf");
	printf("LIB : |%*.7s|\n", 100, "hello printf");
	ft_printf("MY  : |%*.*s|\n", -100, 5, "hello printf");
	printf("LIB : |%*.*s|\n", -100, 5, "hello printf");
	ft_printf("MY  : |%*.*s|\n", 100, 0, "hello printf");
	printf("LIB : |%*.*s|\n", 100, 0, "hello printf");
	ft_printf("MY  : |%0*.*s|\n", 100, 5, "hello printf");
	printf("LIB : |%0*.*s|\n", 100, 5, "hello printf");
	ft_printf("MY  : |%--*.*s|\n", 100, 5, "hello printf");
	printf("LIB : |%--*.*s|\n", 100, 5, "hello printf");
	ft_printf("MY  : |%*s|\n", 100, "hello printf");
	printf("LIB : |%*s|\n", 100, "hello printf");
	printf("============================This is WString!============================\n");
	ft_printf("MY  : |%100lls|\n", L"🤯🙃🙃🙃🙃🙃");
	printf("LIB : |%100lls|\n", L"🤯🙃🙃🙃🙃🙃");
	ft_printf("MY  : |%100.4ls|\n", L"🤯🙃🙃🙃🙃🙃");
	printf("LIB : |%100.4ls|\n", L"🤯🙃🙃🙃🙃🙃");
	ft_printf("MY  : |%*.4ls|\n",100, L"🤯🙃🙃🙃🙃🙃");
	printf("LIB : |%*.4ls|\n",100, L"🤯🙃🙃🙃🙃🙃");
	ft_printf("MY  : |%0100.*ls|\n",17, L"🤯🙃🙃🙃🙃🙃");
	printf("LIB : |%0100.*ls|\n",17, L"🤯🙃🙃🙃🙃🙃");
	ft_printf("MY  : |%100.0ls|\n", L"🤯🙃🙃🙃🙃🙃");
	printf("LIB : |%100.0ls|\n", L"🤯🙃🙃🙃🙃🙃");
	ft_printf("MY  : |%100ls|\n", NULL);
	printf("LIB : |%100ls|\n", NULL);
	ft_printf("MY  : |%5.ls|\n", L"🤯🙃🙃🙃🙃🙃");
	printf("LIB : |%5.ls|\n", L"🤯🙃🙃🙃🙃🙃");
	ft_printf("MY  : |%*.4ls|\n",100, L"🤯🙃🙃🙃🙃🙃");
	printf("LIB : |%*.4ls|\n",100, L"🤯🙃🙃🙃🙃🙃");
	ft_printf("MY  : |%0100.*ls|\n",17, L"🤯🙃🙃🙃🙃🙃");
	printf("LIB : |%0100.*ls|\n",17, L"🤯🙃🙃🙃🙃🙃");
	ft_printf("MY  : |%-100.0ls|\n", L"🤯🙃🙃🙃🙃🙃");
	printf("LIB : |%-100.0ls|\n", L"🤯🙃🙃🙃🙃🙃");
	printf("retrun is :%d\n", ft_printf("MY  : |%-100.15ls|\n", L"🤯🙃🙃🙃🙃🙃"));
	printf("return is :%d\n", printf("LIB : |%-100.15ls|\n", L"🤯🙃🙃🙃🙃🙃"));
	ft_printf("MY  : |%0100ls|\n", L"과");
	printf("LIB : |%0100ls|\n", L"과");
	printf("============================This is Charactor!=========================\n");
	ft_printf("MY  : |%*c|\n", 100, 'R');
	printf("LIB : |%*c|\n", 100, 'R');
	ft_printf("MY  : |%*.c|\n", 100, 'R');
	printf("LIB : |%*.c|\n", 100, 'R');
	ft_printf("MY  : |%*.7c|\n", 100, 'R');
	printf("LIB : |%*.7c|\n", 100, 'R');
	ft_printf("MY  : |%*.*c|\n", -100, 5, 'R');
	printf("LIB : |%*.*c|\n", -100, 5, 'R');
	ft_printf("MY  : |%*.*c|\n", 100, 0, 'R');
	printf("LIB : |%*.*c|\n", 100, 0, 'R');
	ft_printf("MY  : |%0*.*c|\n", 100, 5, 'R');
	printf("LIB : |%0*.*c|\n", 100, 5, 'R');
	ft_printf("MY  : |%--*.*c|\n", 100, 5, 'R');
	printf("LIB : |%--*.*c|\n", 100, 5, 'R');
	printf("============================This is WCharactor!=========================\n");
	ft_printf("MY  : |%*lc|\n", 100, L'🤬');
	printf("LIB : |%*lc|\n", 100, L'🤬');
	ft_printf("MY  : |%*.lc|\n", 100, L'🤬');
	printf("LIB : |%*.lc|\n", 100, L'🤬');
	ft_printf("MY  : |%*.7lc|\n", 100, L'🤬');
	printf("LIB : |%*.7lc|\n", 100, L'🤬');
	ft_printf("MY  : |%*.*lc|\n", -100, 5, L'🤬');
	printf("LIB : |%*.*lc|\n", -100, 5, L'🤬');
	ft_printf("MY  : |%*.*lc|\n", 100, 0, L'🤬');
	printf("LIB : |%*.*lc|\n", 100, 0, L'🤬');
	ft_printf("MY  : |%0*.*lc|\n", 100, 5, L'🤬');
	printf("LIB : |%0*.*lc|\n", 100, 5, L'🤬');
	ft_printf("MY  : |%--*.*lc|\n", 100, 5, L'🤬');
	printf("LIB : |%--*.*lc|\n", 100, 5, L'🤬');
	ft_printf("MY  : |%*lc|\n", 5, L'🤬');
	printf("LIB : |%*lc|\n", 5, L'🤬');
	ft_printf("MY  : |%*.lc|\n", 5, L'🤬');
	printf("LIB : |%*.lc|\n", 5, L'🤬');
	ft_printf("MY  : |%*.7lc|\n", 5, L'🤬');
	printf("LIB : |%*.7lc|\n", 5, L'🤬');
	ft_printf("MY  : |%*.*lc|\n", -5, 5, L'🤬');
	printf("LIB : |%*.*lc|\n", -5, 5, L'🤬');
	ft_printf("MY  : |%*.*lc|\n", 5, 0, L'🤬');
	printf("LIB : |%*.*lc|\n", 5, 0, L'🤬');
	ft_printf("MY  : |%0*.*lc|\n", 5, 5, L'🤬');
	printf("LIB : |%0*.*lc|\n", 5, 5, L'🤬');
	ft_printf("MY  : |%--*.*lc|\n", 5, 5, L'🤬');
	printf("LIB : |%--*.*lc|\n", 5, 5, L'🤬');
	printf("============================This is Dedimal!=========================\n");
	printf("============================is negative!=========================\n");
	ft_printf("MY  : |%d|\n", -123);
	printf("LIB : |%d|\n", -123);
	ft_printf("MY  : |%.100d|\n", -123);
	printf("LIB : |%.100d|\n", -123);
	ft_printf("MY  : |%*d|\n", 100, -123);
	printf("LIB : |%*d|\n", 100, -123);
	ft_printf("MY  : |%0*d|\n", 100, -123);
	printf("LIB : |%0*d|\n", 100, -123);
	ft_printf("MY  : |%*.7d|\n", 100, -123);
	printf("LIB : |%*.7d|\n", 100, -123);
	ft_printf("MY  : |%0*.*d|\n", -100, 5, -123);
	printf("LIB : |%0*.*d|\n", -100, 5, -123);
	ft_printf("MY  : |%*.*d|\n", 100, 0, -123);
	printf("LIB : |%*.*d|\n", 100, 0, -123);
	ft_printf("MY  : |%0*.*d|\n", 100, 5, -123);
	printf("LIB : |%0*.*d|\n", 100, 5, -123);
	ft_printf("MY  : |%--*.*d|\n", 100, 5, -123);
	printf("LIB : |%--*.*d|\n", 100, 5, -123);
	printf("============================is positive!=========================\n");
	ft_printf("MY  : |%d|\n", 4242);
	printf("LIB : |%d|\n", 4242);
	ft_printf("MY  : |%+0.100d|\n", 4242);
	printf("LIB : |%+0.100d|\n", 4242);
	ft_printf("MY  : |%*d|\n", 100, 4242);
	printf("LIB : |%*d|\n", 100, 4242);
	ft_printf("MY  : |%0+*d|\n", 100, 4242);
	printf("LIB : |%0+*d|\n", 100, 4242);
	ft_printf("MY  : |%*.7d|\n", 100, 4242);
	printf("LIB : |%*.7d|\n", 100, 4242);
	ft_printf("MY  : |%0 *.*d|\n", -100, 5, 4242);
	printf("LIB : |%0 *.*d|\n", -100, 5, 4242);
	ft_printf("MY  : |% +*.*d|\n", 100, 0, 4242);
	printf("LIB : |% +*.*d|\n", 100, 0, 4242);
	ft_printf("MY  : |% 0*.*d|\n", 100, 5, 4242);
	printf("LIB : |% 0*.*d|\n", 100, 5, 4242);
	ft_printf("MY  : |%+--*.*d|\n", 100, 5, 4242);
	printf("LIB : |%+--*.*d|\n", 100, 5, 4242);
	printf("============================This is Unsigned Decimal!=========================\n");
	printf("============================is negative!=========================\n");
	ft_printf("MY  : |%u|\n", -123);
	printf("LIB : |%u|\n", -123);
	ft_printf("MY  : |%.100u|\n", -123);
	printf("LIB : |%.100u|\n", -123);
	ft_printf("MY  : |%*u|\n", 100, -123);
	printf("LIB : |%*u|\n", 100, -123);
	ft_printf("MY  : |%0*u|\n", 100, -123);
	printf("LIB : |%0*u|\n", 100, -123);
	ft_printf("MY  : |%*.7u|\n", 100, -123);
	printf("LIB : |%*.7u|\n", 100, -123);
	ft_printf("MY  : |%0*.*u|\n", -100, 5, -123);
	printf("LIB : |%0*.*u|\n", -100, 5, -123);
	ft_printf("MY  : |%*.*u|\n", 100, 0, -123);
	printf("LIB : |%*.*u|\n", 100, 0, -123);
	ft_printf("MY  : |%0*.*u|\n", 100, 5, -123);
	printf("LIB : |%0*.*u|\n", 100, 5, -123);
	ft_printf("MY  : |%--*.*u|\n", 100, 5, -123);
	printf("LIB : |%--*.*u|\n", 100, 5, -123);
	printf("============================is positive!=========================\n");
	ft_printf("MY  : |%u|\n", 4242);
	printf("LIB : |%u|\n", 4242);
	ft_printf("MY  : |%+0.100u|\n", 4242);
	printf("LIB : |%+0.100u|\n", 4242);
	ft_printf("MY  : |%*u|\n", 100, 4242);
	printf("LIB : |%*u|\n", 100, 4242);
	ft_printf("MY  : |%0+*u|\n", 100, 4242);
	printf("LIB : |%0+*u|\n", 100, 4242);
	ft_printf("MY  : |%*.7u|\n", 100, 4242);
	printf("LIB : |%*.7u|\n", 100, 4242);
	ft_printf("MY  : |%0 *.*u|\n", -100, 5, 4242);
	printf("LIB : |%0 *.*u|\n", -100, 5, 4242);
	ft_printf("MY  : |% +*.*u|\n", 100, 0, 4242);
	printf("LIB : |% +*.*u|\n", 100, 0, 4242);
	ft_printf("MY  : |% 0*.*u|\n", 100, 5, 4242);
	printf("LIB : |% 0*.*u|\n", 100, 5, 4242);
	ft_printf("MY  : |%+--*.*u|\n", 100, 5, 4242);
	printf("LIB : |%+--*.*u|\n", 100, 5, 4242);
	printf("============================Length with U??=========================\n");
	ft_printf("MY  : |%hhu|\n", 4242);
	printf("LIB : |%hhu|\n", 4242);
	ft_printf("MY  : |%hu|\n", 4242);
	printf("LIB : |%hu|\n", 4242);
	ft_printf("MY  : |%lu|\n", 424242424242);
	printf("LIB : |%lu|\n", 424242424242);
	ft_printf("MY  : |%llu|\n", 424242424242);
	printf("LIB : |%llu|\n", 424242424242);
	ft_printf("MY  : |%u|\n", 424242424242);
	printf("LIB : |%u|\n", 424242424242);
	ft_printf("MY  : |%u|\n", 424242424242);
	printf("LIB : |%u|\n", 424242424242);
	printf("============================This is Dedimal With h!=========================\n");
	printf("============================is negative!=========================\n");
	ft_printf("MY  : |%hd|\n", -123);
	printf("LIB : |%hd|\n", -123);
	ft_printf("MY  : |%.100hd|\n", -123);
	printf("LIB : |%.100hd|\n", -123);
	ft_printf("MY  : |%*hd|\n", 100, -123);
	printf("LIB : |%*hd|\n", 100, -123);
	ft_printf("MY  : |%0*hd|\n", 100, -123);
	printf("LIB : |%0*hd|\n", 100, -123);
	ft_printf("MY  : |%*.7hd|\n", 100, -123);
	printf("LIB : |%*.7hd|\n", 100, -123);
	ft_printf("MY  : |%0*.*hd|\n", -100, 5, -123);
	printf("LIB : |%0*.*hd|\n", -100, 5, -123);
	ft_printf("MY  : |%*.*hd|\n", 100, 0, -123);
	printf("LIB : |%*.*hd|\n", 100, 0, -123);
	ft_printf("MY  : |%0*.*hd|\n", 100, 5, -123);
	printf("LIB : |%0*.*hd|\n", 100, 5, -123);
	ft_printf("MY  : |%--*.*hd|\n", 100, 5, -123);
	printf("LIB : |%--*.*hd|\n", 100, 5, -123);
	printf("============================is positive!=========================\n");
	ft_printf("MY  : |%hd|\n", 4242);
	printf("LIB : |%hd|\n", 4242);
	ft_printf("MY  : |%+0.100hd|\n", 4242);
	printf("LIB : |%+0.100hd|\n", 4242);
	ft_printf("MY  : |%*hd|\n", 100, 4242);
	printf("LIB : |%*hd|\n", 100, 4242);
	ft_printf("MY  : |%0+*hd|\n", 100, 4242);
	printf("LIB : |%0+*hd|\n", 100, 4242);
	ft_printf("MY  : |%*.7hd|\n", 100, 4242);
	printf("LIB : |%*.7hd|\n", 100, 4242);
	ft_printf("MY  : |%0 *.*hd|\n", -100, 5, 4242);
	printf("LIB : |%0 *.*hd|\n", -100, 5, 4242);
	ft_printf("MY  : |% +*.*hd|\n", 100, 0, 4242);
	printf("LIB : |% +*.*hd|\n", 100, 0, 4242);
	ft_printf("MY  : |% 0*.*hd|\n", 100, 5, 4242);
	printf("LIB : |% 0*.*hd|\n", 100, 5, 4242);
	ft_printf("MY  : |%+--*.*hd|\n", 100, 5, 4242);
	printf("LIB : |%+--*.*hd|\n", 100, 5, 4242);
	printf("============================This is Dedimal with hh!=========================\n");
	printf("============================is negative!=========================\n");
	ft_printf("MY  : |%hhd|\n", -123);
	printf("LIB : |%hhd|\n", -123);
	ft_printf("MY  : |%.100hhd|\n", -123);
	printf("LIB : |%.100hhd|\n", -123);
	ft_printf("MY  : |%*hhd|\n", 100, -123);
	printf("LIB : |%*hhd|\n", 100, -123);
	ft_printf("MY  : |%0*hhd|\n", 100, -123);
	printf("LIB : |%0*hhd|\n", 100, -123);
	ft_printf("MY  : |%*.7hhd|\n", 100, -123);
	printf("LIB : |%*.7hhd|\n", 100, -123);
	ft_printf("MY  : |%0*.*hhd|\n", -100, 5, -123);
	printf("LIB : |%0*.*hhd|\n", -100, 5, -123);
	ft_printf("MY  : |%*.*hhd|\n", 100, 0, -123);
	printf("LIB : |%*.*hhd|\n", 100, 0, -123);
	ft_printf("MY  : |%0*.*hhd|\n", 100, 5, -123);
	printf("LIB : |%0*.*hhd|\n", 100, 5, -123);
	ft_printf("MY  : |%--*.*hhd|\n", 100, 5, -123);
	printf("LIB : |%--*.*hhd|\n", 100, 5, -123);
	printf("============================is positive!=========================\n");
	ft_printf("MY  : |%hhd|\n", 4242);
	printf("LIB : |%hhd|\n", 4242);
	ft_printf("MY  : |%+0.100hhd|\n", 4242);
	printf("LIB : |%+0.100hhd|\n", 4242);
	ft_printf("MY  : |%*hhd|\n", 100, 4242);
	printf("LIB : |%*hhd|\n", 100, 4242);
	ft_printf("MY  : |%0+*hhd|\n", 100, 4242);
	printf("LIB : |%0+*hhd|\n", 100, 4242);
	ft_printf("MY  : |%*.7hhd|\n", 100, 4242);
	printf("LIB : |%*.7hhd|\n", 100, 4242);
	ft_printf("MY  : |%0 *.*hhd|\n", -100, 5, 4242);
	printf("LIB : |%0 *.*hhd|\n", -100, 5, 4242);
	ft_printf("MY  : |% +*.*hhd|\n", 100, 0, 4242);
	printf("LIB : |% +*.*hhd|\n", 100, 0, 4242);
	ft_printf("MY  : |% 0*.*hhd|\n", 100, 5, 4242);
	printf("LIB : |% 0*.*hhd|\n", 100, 5, 4242);
	ft_printf("MY  : |%+--*.*hhd|\n", 100, 5, 4242);
	printf("LIB : |%+--*.*hhd|\n", 100, 5, 4242);
	printf("============================This is Dedimal with l!=========================\n");
	printf("============================is negative!=========================\n");
	ft_printf("MY  : |%ld|\n", -123);
	printf("LIB : |%ld|\n", -123);
	ft_printf("MY  : |%.100ld|\n", -123);
	printf("LIB : |%.100ld|\n", -123);
	ft_printf("MY  : |%*ld|\n", 100, -123);
	printf("LIB : |%*ld|\n", 100, -123);
	ft_printf("MY  : |%0*ld|\n", 100, -123);
	printf("LIB : |%0*ld|\n", 100, -123);
	ft_printf("MY  : |%*.7ld|\n", 100, -123);
	printf("LIB : |%*.7ld|\n", 100, -123);
	ft_printf("MY  : |%0*.*ld|\n", -100, 5, -123);
	printf("LIB : |%0*.*ld|\n", -100, 5, -123);
	ft_printf("MY  : |%*.*ld|\n", 100, 0, -123);
	printf("LIB : |%*.*ld|\n", 100, 0, -123);
	ft_printf("MY  : |%0*.*ld|\n", 100, 5, -123);
	printf("LIB : |%0*.*ld|\n", 100, 5, -123);
	ft_printf("MY  : |%--*.*ld|\n", 100, 5, -123);
	printf("LIB : |%--*.*ld|\n", 100, 5, -123);
	printf("============================is positive!=========================\n");
	ft_printf("MY  : |%ld|\n", 4242);
	printf("LIB : |%ld|\n", 4242);
	ft_printf("MY  : |%+0.100ld|\n", 4242);
	printf("LIB : |%+0.100ld|\n", 4242);
	ft_printf("MY  : |%*ld|\n", 100, 4242);
	printf("LIB : |%*ld|\n", 100, 4242);
	ft_printf("MY  : |%0+*ld|\n", 100, 4242);
	printf("LIB : |%0+*ld|\n", 100, 4242);
	ft_printf("MY  : |%*.7ld|\n", 100, 4242);
	printf("LIB : |%*.7ld|\n", 100, 4242);
	ft_printf("MY  : |%0 *.*ld|\n", -100, 5, 4242);
	printf("LIB : |%0 *.*ld|\n", -100, 5, 4242);
	ft_printf("MY  : |% +*.*ld|\n", 100, 0, 4242);
	printf("LIB : |% +*.*ld|\n", 100, 0, 4242);
	ft_printf("MY  : |% 0*.*ld|\n", 100, 5, 4242);
	printf("LIB : |% 0*.*ld|\n", 100, 5, 4242);
	ft_printf("MY  : |%+--*.*ld|\n", 100, 5, 4242);
	printf("LIB : |%+--*.*ld|\n", 100, 5, 4242);
	printf("============================This is Dedimal with ll!=========================\n");
	printf("============================is negative!=========================\n");
	ft_printf("MY  : |%lld|\n", -123);
	printf("LIB : |%lld|\n", -123);
	ft_printf("MY  : |%.100lld|\n", -123);
	printf("LIB : |%.100lld|\n", -123);
	ft_printf("MY  : |%*lld|\n", 100, -123);
	printf("LIB : |%*lld|\n", 100, -123);
	ft_printf("MY  : |%0*lld|\n", 100, -123);
	printf("LIB : |%0*lld|\n", 100, -123);
	ft_printf("MY  : |%*.7lld|\n", 100, -123);
	printf("LIB : |%*.7lld|\n", 100, -123);
	ft_printf("MY  : |%0*.*lld|\n", -100, 5, -123);
	printf("LIB : |%0*.*lld|\n", -100, 5, -123);
	ft_printf("MY  : |%*.*lld|\n", 100, 0, -123);
	printf("LIB : |%*.*lld|\n", 100, 0, -123);
	ft_printf("MY  : |%0*.*lld|\n", 100, 5, -123);
	printf("LIB : |%0*.*lld|\n", 100, 5, -123);
	ft_printf("MY  : |%--*.*lld|\n", 100, 5, -123);
	printf("LIB : |%--*.*lld|\n", 100, 5, -123);
	printf("============================is positive!=========================\n");
	ft_printf("MY  : |%lld|\n", 42424242424);
	printf("LIB : |%lld|\n", 42424242424);
	ft_printf("MY  : |%+0.100lld|\n", 42424242424);
	printf("LIB : |%+0.100lld|\n", 42424242424);
	ft_printf("MY  : |%*lld|\n", 100, 42424242424);
	printf("LIB : |%*lld|\n", 100, 42424242424);
	ft_printf("MY  : |%0+*lld|\n", 100, 42424242424);
	printf("LIB : |%0+*lld|\n", 100, 42424242424);
	ft_printf("MY  : |%*.7lld|\n", 100, 42424242424);
	printf("LIB : |%*.7lld|\n", 100, 42424242424);
	ft_printf("MY  : |%0 *.*lld|\n", -100, 5, 42424242424);
	printf("LIB : |%0 *.*lld|\n", -100, 5, 42424242424);
	ft_printf("MY  : |% +*.*lld|\n", 100, 0, 42424242424);
	printf("LIB : |% +*.*lld|\n", 100, 0, 42424242424);
	ft_printf("MY  : |% 0*.*lld|\n", 100, 5, 42424242424);
	printf("LIB : |% 0*.*lld|\n", 100, 5, 42424242424);
	ft_printf("MY  : |%+--*.*lld|\n", 100, 5, 42424242424);
	printf("LIB : |%+--*.*lld|\n", 100, 5, 42424242424);
	printf("============================This is hexa x!=========================\n");
	printf("============================is negative!=========================\n");
	ft_printf("MY  : |%x|\n", -123);
	printf("LIB : |%x|\n", -123);
	ft_printf("MY  : |%.100x|\n", -123);
	printf("LIB : |%.100x|\n", -123);
	ft_printf("MY  : |%*x|\n", 100, -123);
	printf("LIB : |%*x|\n", 100, -123);
	ft_printf("MY  : |%0*x|\n", 100, -123);
	printf("LIB : |%0*x|\n", 100, -123);
	ft_printf("MY  : |%*.7x|\n", 100, -123);
	printf("LIB : |%*.7x|\n", 100, -123);
	ft_printf("MY  : |%0*.*x|\n", -100, 5, -123);
	printf("LIB : |%0*.*x|\n", -100, 5, -123);
	ft_printf("MY  : |%*.*x|\n", 100, 0, -123);
	printf("LIB : |%*.*x|\n", 100, 0, -123);
	ft_printf("MY  : |%0*.*x|\n", 100, 5, -123);
	printf("LIB : |%0*.*x|\n", 100, 5, -123);
	ft_printf("MY  : |%--*.*x|\n", 100, 5, -123);
	printf("LIB : |%--*.*x|\n", 100, 5, -123);
	printf("============================is positive!=========================\n");
	ft_printf("MY  : |%x|\n", 4242);
	printf("LIB : |%x|\n", 4242);
	ft_printf("MY  : |%+0.100x|\n", 4242);
	printf("LIB : |%+0.100x|\n", 4242);
	ft_printf("MY  : |%*x|\n", 100, 4242);
	printf("LIB : |%*x|\n", 100, 4242);
	ft_printf("MY  : |%0+*x|\n", 100, 4242);
	printf("LIB : |%0+*x|\n", 100, 4242);
	ft_printf("MY  : |%*.7x|\n", 100, 4242);
	printf("LIB : |%*.7x|\n", 100, 4242);
	ft_printf("MY  : |%0 *.*x|\n", -100, 5, 4242);
	printf("LIB : |%0 *.*x|\n", -100, 5, 4242);
	ft_printf("MY  : |% +*.*x|\n", 100, 0, 4242);
	printf("LIB : |% +*.*x|\n", 100, 0, 4242);
	ft_printf("MY  : |% 0*.*x|\n", 100, 5, 4242);
	printf("LIB : |% 0*.*x|\n", 100, 5, 4242);
	ft_printf("MY  : |%+--*.*x|\n", 100, 5, 4242);
	printf("LIB : |%+--*.*x|\n", 100, 5, 4242);
	printf("============================Length with U??=========================\n");
	ft_printf("MY  : |%hhx|\n", 4242);
	printf("LIB : |%hhx|\n", 4242);
	ft_printf("MY  : |%hx|\n", 4242);
	printf("LIB : |%hx|\n", 4242);
	ft_printf("MY  : |%lx|\n", 424242424242);
	printf("LIB : |%lx|\n", 424242424242);
	ft_printf("MY  : |%llx|\n", 424242424242);
	printf("LIB : |%llx|\n", 424242424242);
	ft_printf("MY  : |%x|\n", 424242424242);
	printf("LIB : |%x|\n", 424242424242);
	ft_printf("MY  : |%x|\n", 424242424242);
	printf("LIB : |%x|\n", 424242424242);
	printf("============================This is hex X!=========================\n");
	printf("============================is negative!=========================\n");
	ft_printf("MY  : |%hX|\n", -123);
	printf("LIB : |%hX|\n", -123);
	ft_printf("MY  : |%.100hX|\n", -123);
	printf("LIB : |%.100hX|\n", -123);
	ft_printf("MY  : |%*hX|\n", 100, -123);
	printf("LIB : |%*hX|\n", 100, -123);
	ft_printf("MY  : |%0*hX|\n", 100, -123);
	printf("LIB : |%0*hX|\n", 100, -123);
	ft_printf("MY  : |%*.7hX|\n", 100, -123);
	printf("LIB : |%*.7hX|\n", 100, -123);
	ft_printf("MY  : |%0*.*hX|\n", -100, 5, -123);
	printf("LIB : |%0*.*hX|\n", -100, 5, -123);
	ft_printf("MY  : |%*.*hX|\n", 100, 0, -123);
	printf("LIB : |%*.*hX|\n", 100, 0, -123);
	ft_printf("MY  : |%0*.*hX|\n", 100, 5, -123);
	printf("LIB : |%0*.*hX|\n", 100, 5, -123);
	ft_printf("MY  : |%--*.*hX|\n", 100, 5, -123);
	printf("LIB : |%--*.*hX|\n", 100, 5, -123);
	printf("============================is positive!=========================\n");
	ft_printf("MY  : |%hX|\n", 4242);
	printf("LIB : |%hX|\n", 4242);
	ft_printf("MY  : |%+0.100hX|\n", 4242);
	printf("LIB : |%+0.100hX|\n", 4242);
	ft_printf("MY  : |%*hX|\n", 100, 4242);
	printf("LIB : |%*hX|\n", 100, 4242);
	ft_printf("MY  : |%0+*hX|\n", 100, 4242);
	printf("LIB : |%0+*hX|\n", 100, 4242);
	ft_printf("MY  : |%*.7hX|\n", 100, 4242);
	printf("LIB : |%*.7hX|\n", 100, 4242);
	ft_printf("MY  : |%0 *.*hX|\n", -100, 5, 4242);
	printf("LIB : |%0 *.*hX|\n", -100, 5, 4242);
	ft_printf("MY  : |% +*.*hX|\n", 100, 0, 4242);
	printf("LIB : |% +*.*hX|\n", 100, 0, 4242);
	ft_printf("MY  : |% 0*.*hX|\n", 100, 5, 4242);
	printf("LIB : |% 0*.*hX|\n", 100, 5, 4242);
	ft_printf("MY  : |%+--*.*hX|\n", 100, 5, 4242);
	printf("LIB : |%+--*.*hX|\n", 100, 5, 4242);
	printf("============================This is DeXimal with hh!=========================\n");
	printf("============================is negative!=========================\n");
	ft_printf("MY  : |%hhX|\n", -123);
	printf("LIB : |%hhX|\n", -123);
	ft_printf("MY  : |%.100hhX|\n", -123);
	printf("LIB : |%.100hhX|\n", -123);
	ft_printf("MY  : |%*hhX|\n", 100, -123);
	printf("LIB : |%*hhX|\n", 100, -123);
	ft_printf("MY  : |%0*hhX|\n", 100, -123);
	printf("LIB : |%0*hhX|\n", 100, -123);
	ft_printf("MY  : |%*.7hhX|\n", 100, -123);
	printf("LIB : |%*.7hhX|\n", 100, -123);
	ft_printf("MY  : |%0*.*hhX|\n", -100, 5, -123);
	printf("LIB : |%0*.*hhX|\n", -100, 5, -123);
	ft_printf("MY  : |%*.*hhX|\n", 100, 0, -123);
	printf("LIB : |%*.*hhX|\n", 100, 0, -123);
	ft_printf("MY  : |%0*.*hhX|\n", 100, 5, -123);
	printf("LIB : |%0*.*hhX|\n", 100, 5, -123);
	ft_printf("MY  : |%--*.*hhX|\n", 100, 5, -123);
	printf("LIB : |%--*.*hhX|\n", 100, 5, -123);
	printf("============================is positive!=========================\n");
	ft_printf("MY  : |%hhX|\n", 4242);
	printf("LIB : |%hhX|\n", 4242);
	ft_printf("MY  : |%+0.100hhX|\n", 4242);
	printf("LIB : |%+0.100hhX|\n", 4242);
	ft_printf("MY  : |%*hhX|\n", 100, 4242);
	printf("LIB : |%*hhX|\n", 100, 4242);
	ft_printf("MY  : |%0+*hhX|\n", 100, 4242);
	printf("LIB : |%0+*hhX|\n", 100, 4242);
	ft_printf("MY  : |%*.7hhX|\n", 100, 4242);
	printf("LIB : |%*.7hhX|\n", 100, 4242);
	ft_printf("MY  : |%0 *.*hhX|\n", -100, 5, 4242);
	printf("LIB : |%0 *.*hhX|\n", -100, 5, 4242);
	ft_printf("MY  : |% +*.*hhX|\n", 100, 0, 4242);
	printf("LIB : |% +*.*hhX|\n", 100, 0, 4242);
	ft_printf("MY  : |% 0*.*hhX|\n", 100, 5, 4242);
	printf("LIB : |% 0*.*hhX|\n", 100, 5, 4242);
	ft_printf("MY  : |%+--*.*hhX|\n", 100, 5, 4242);
	printf("LIB : |%+--*.*hhX|\n", 100, 5, 4242);
	printf("============================This is DeXimal with l!=========================\n");
	printf("============================is negative!=========================\n");
	ft_printf("MY  : |%lX|\n", -123);
	printf("LIB : |%lX|\n", -123);
	ft_printf("MY  : |%.100lX|\n", -123);
	printf("LIB : |%.100lX|\n", -123);
	ft_printf("MY  : |%*lX|\n", 100, -123);
	printf("LIB : |%*lX|\n", 100, -123);
	ft_printf("MY  : |%0*lX|\n", 100, -123);
	printf("LIB : |%0*lX|\n", 100, -123);
	ft_printf("MY  : |%*.7lX|\n", 100, -123);
	printf("LIB : |%*.7lX|\n", 100, -123);
	ft_printf("MY  : |%0*.*lX|\n", -100, 5, -123);
	printf("LIB : |%0*.*lX|\n", -100, 5, -123);
	ft_printf("MY  : |%*.*lX|\n", 100, 0, -123);
	printf("LIB : |%*.*lX|\n", 100, 0, -123);
	ft_printf("MY  : |%0*.*lX|\n", 100, 5, -123);
	printf("LIB : |%0*.*lX|\n", 100, 5, -123);
	ft_printf("MY  : |%--*.*lX|\n", 100, 5, -123);
	printf("LIB : |%--*.*lX|\n", 100, 5, -123);
	printf("============================is positive!=========================\n");
	ft_printf("MY  : |%lX|\n", 4242);
	printf("LIB : |%lX|\n", 4242);
	ft_printf("MY  : |%+0.100lX|\n", 4242);
	printf("LIB : |%+0.100lX|\n", 4242);
	ft_printf("MY  : |%*lX|\n", 100, 4242);
	printf("LIB : |%*lX|\n", 100, 4242);
	ft_printf("MY  : |%0+*lX|\n", 100, 4242);
	printf("LIB : |%0+*lX|\n", 100, 4242);
	ft_printf("MY  : |%*.7lX|\n", 100, 4242);
	printf("LIB : |%*.7lX|\n", 100, 4242);
	ft_printf("MY  : |%0 *.*lX|\n", -100, 5, 4242);
	printf("LIB : |%0 *.*lX|\n", -100, 5, 4242);
	ft_printf("MY  : |% +*.*lX|\n", 100, 0, 4242);
	printf("LIB : |% +*.*lX|\n", 100, 0, 4242);
	ft_printf("MY  : |% 0*.*lX|\n", 100, 5, 4242);
	printf("LIB : |% 0*.*lX|\n", 100, 5, 4242);
	ft_printf("MY  : |%+--*.*lX|\n", 100, 5, 4242);
	printf("LIB : |%+--*.*lX|\n", 100, 5, 4242);
	printf("============================This is DeXimal with ll!=========================\n");
	printf("============================is negative!=========================\n");
	ft_printf("MY  : |%llX|\n", -123);
	printf("LIB : |%llX|\n", -123);
	ft_printf("MY  : |%.100llX|\n", -123);
	printf("LIB : |%.100llX|\n", -123);
	ft_printf("MY  : |%*llX|\n", 100, -123);
	printf("LIB : |%*llX|\n", 100, -123);
	ft_printf("MY  : |%0*llX|\n", 100, -123);
	printf("LIB : |%0*llX|\n", 100, -123);
	ft_printf("MY  : |%*.7llX|\n", 100, -123);
	printf("LIB : |%*.7llX|\n", 100, -123);
	ft_printf("MY  : |%0*.*llX|\n", -100, 5, -123);
	printf("LIB : |%0*.*llX|\n", -100, 5, -123);
	ft_printf("MY  : |%*.*llX|\n", 100, 0, -123);
	printf("LIB : |%*.*llX|\n", 100, 0, -123);
	ft_printf("MY  : |%0*.*llX|\n", 100, 5, -123);
	printf("LIB : |%0*.*llX|\n", 100, 5, -123);
	ft_printf("MY  : |%--*.*llX|\n", 100, 5, -123);
	printf("LIB : |%--*.*llX|\n", 100, 5, -123);
	printf("============================is positive!=========================\n");
	ft_printf("MY  : |%llX|\n", 42424242424);
	printf("LIB : |%llX|\n", 42424242424);
	ft_printf("MY  : |%+0.100llX|\n", 42424242424);
	printf("LIB : |%+0.100llX|\n", 42424242424);
	ft_printf("MY  : |%*llX|\n", 100, 42424242424);
	printf("LIB : |%*llX|\n", 100, 42424242424);
	ft_printf("MY  : |%0+*llX|\n", 100, 42424242424);
	printf("LIB : |%0+*llX|\n", 100, 42424242424);
	ft_printf("MY  : |%*.7llX|\n", 100, 42424242424);
	printf("LIB : |%*.7llX|\n", 100, 42424242424);
	ft_printf("MY  : |%0 *.*llX|\n", -100, 5, 42424242424);
	printf("LIB : |%0 *.*llX|\n", -100, 5, 42424242424);
	ft_printf("MY  : |% +*.*llX|\n", 100, 0, 42424242424);
	printf("LIB : |% +*.*llX|\n", 100, 0, 42424242424);
	ft_printf("MY  : |% 0*.*llX|\n", 100, 5, 42424242424);
	printf("LIB : |% 0*.*llX|\n", 100, 5, 42424242424);
	ft_printf("MY  : |%+--*.*llX|\n", 100, 5, 42424242424);
	printf("LIB : |%+--*.*llX|\n", 100, 5, 42424242424);
	printf("============================This is # with ll!=========================\n");
	printf("============================is negative!=========================\n");
	ft_printf("MY  : |%#llX|\n", -123);
	printf("LIB : |%#llX|\n", -123);
	ft_printf("MY  : |%#.100llX|\n", -123);
	printf("LIB : |%#.100llX|\n", -123);
	ft_printf("MY  : |%#*llX|\n", 100, -123);
	printf("LIB : |%#*llX|\n", 100, -123);
	ft_printf("MY  : |%#0*llX|\n", 100, -123);
	printf("LIB : |%#0*llX|\n", 100, -123);
	ft_printf("MY  : |%#*.7llX|\n", 100, -123);
	printf("LIB : |%#*.7llX|\n", 100, -123);
	ft_printf("MY  : |%#0*.*llX|\n", -100, 5, -123);
	printf("LIB : |%#0*.*llX|\n", -100, 5, -123);
	ft_printf("MY  : |%#*.*llX|\n", 100, 0, -123);
	printf("LIB : |%#*.*llX|\n", 100, 0, -123);
	ft_printf("MY  : |%#0*.*llX|\n", 100, 5, -123);
	printf("LIB : |%#0*.*llX|\n", 100, 5, -123);
	ft_printf("MY  : |%#--*.*llX|\n", 100, 5, -123);
	printf("LIB : |%#--*.*llX|\n", 100, 5, -123);
	printf("============================is positive!=========================\n");
	ft_printf("MY  : |%#llX|\n", 42424242424);
	printf("LIB : |%#llX|\n", 42424242424);
	ft_printf("MY  : |%#+0.100llX|\n", 42424242424);
	printf("LIB : |%#+0.100llX|\n", 42424242424);
	ft_printf("MY  : |%#*llX|\n", 100, 42424242424);
	printf("LIB : |%#*llX|\n", 100, 42424242424LL);
	ft_printf("MY  : |%#0+*llX|\n", 100, 42424242424);
	printf("LIB : |%#0+*llX|\n", 100, 42424242424);
	ft_printf("MY  : |%#*.7llX|\n", 100, 42424242424);
	printf("LIB : |%#*.7llX|\n", 100, 42424242424);
	ft_printf("MY  : |%#0 *.*llX|\n", -100, 5, 42424242424);
	printf("LIB : |%#0 *.*llX|\n", -100, 5, 42424242424);
	ft_printf("MY  : |%# +*.*llX|\n", 100, 0, 42424242424);
	printf("LIB : |%# +*.*llX|\n", 100, 0, 42424242424);
	ft_printf("MY  : |%# 0*.*llX|\n", 100, 5, 42424242424);
	printf("LIB : |%# 0*.*llX|\n", 100, 5, 42424242424);
	ft_printf("MY  : |%#+--*.*llX|\n", 100, 5, 42424242424);
	printf("LIB : |%#+--*.*llX|\n", 100, 5, 42424242424);
	static int aa = 424242;
	ft_printf("MY  : |%#+0*p|\n", 100, aa);
	printf("LIB : |%#+0*p|\n", 100, aa);
	ft_printf("MY  : |%p|\n", aa);
	printf("LIB : |%p|\n", aa);
	ft_printf("Hello %n Nflag\n",&aa);
	printf("Hello %n Nflag\n",&aa);
	ft_printf("%d\n", aa);
	printf("%d\n", aa);
	ft_printf("%% -dasdfsaf\n", aa);
	printf("%% -dasdfsaf\n", aa);
	ft_printf("%%%%d%d%d\n", aa, aa);
	printf("%%%%d%d%d\n", aa, aa);
	ft_printf("a%100d\n", aa);
	printf("a%100d\n", aa);
	ft_printf("%ld\n", aa);
	ft_printf("%hd\n", aa);
	ft_printf("%d\n", aa);
	ft_printf("%d\n", aa);
	ft_printf("%5.3s\n", NULL);
	printf("%5.3s\n", NULL);
	ft_printf("%d\n",	ft_printf("hello ,%s\n", NULL));
	printf("%d\n", printf("hello, %s\n", NULL));
	ft_printf("%s", NULL);
	ft_printf("%-10.*s" ,-10, NULL);
	ft_printf("|%-10.8s|" ,"hi lo");
//	ft_printf("%%-*.3s LYDI == |%-*.3s|\\n", 5, "LYDI");
//	printf("%%-*.3s LYDI == |%-*.3s|\\n", 5, "LYDI");
//	ft_printf("%% *.5i 42 == |% *.5i|\n", 4, 42);
	printf("%% *.5i 42 == |% *.5i|\n", 4, 42);
	static int n = 0;
	printf("%d, %d\n", ft_printf("pft%*.*ntest%d", 5, 5, &n, 123), n);
	printf("%d, %d\n", printf("pft%*.*ntest%d", 5, 5, &n, 123), n);
	ft_printf("%d%d%%%d\n", 10, 10);
	ft_printf("%-3p\n", &n);
	printf("%-3p\n", &n);
	printf("%d\n", ft_printf("%-6.5i\n,% 6.5d\n,%6u\n,%6li\n", 124,124,124,124));
	printf("%d\n", printf("%-6.5i\n,% 6.5d\n,%6u\n,%6li\n", 124,124,124,124));
	printf("%d\n", ft_printf("%7d", 33));
	printf("%d\n", printf("%7d", 33));
	ft_printf("% *d\n",3, 0);
	printf("% *d\n",3, 0);
	ft_printf("%.0d\n", 0);
	printf("%.0d\n", 0);
	printf("%5%\n");
	printf("%0100s\n", "");
	ft_printf("%5%\n");
	printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", -1, -1, -1, -1,-1,"asd",'c',-1,-1,-1,-1);
	ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", -1, -1, -1, -1,-1,"asd",'c',-1,-1,-1,-1);
	printf("%0 *.*%", 10, 10);
	ft_printf("%0 *.*%", 10, 10);
	printf("===================================DEBUGING WITH TESTER=============================\n");
	ft_printf("MY d:");
	ft_printf("-->|%-4.d|<--\n", -135);
	ft_printf("LIB d:");
	printf("-->|%-4.d|<--\n", -135);
	ft_printf("MY x:");
	ft_printf("-->|%#0x|<--\n", aa);
	ft_printf("LIB x:");
	printf("-->|%#0x|<--\n", aa);
	printf("-->|%.0d|<--\n", aa);
	ft_printf("-->|%.0d|<--\n", aa);
	int d = -135;
	ft_printf("-->|%0*d|<--\n", -4, d);
	printf("-->|%0*d|<--\n", -4, d);
	ft_printf("-->|%0*d|<--\n", -3, d);
	printf("-->|%0*d|<--\n", -3, d);
	d = 198;
	ft_printf("-->|% 0*d|<--\n", -3, d);
	printf("-->|% 0*d|<--\n", -3, d);
	ft_printf("-->|% 0*d|<--\n", -2, d);
	printf("-->|% 0*d|<--\n", -2, d);
	printf("return :%d\n", ft_printf("%b\n"));
	printf("return :%d\n", printf("%b\n"));
	printf("return :%d\n", ft_printf("%l\n"));
	printf("return :%d\n", printf("%l\n"));
	ft_printf("%0.0d\n", 0);
	printf("%0.0d\n", 0);
	ft_printf("%0*.*i\n", 2, -2, 1);
	printf("%0*.*i\n", 10, -3, 1);
	printf("============\n");
	printf("%.*u, %.*x %.*X\n", 0, 0, 0, 0, 0, 0);
	ft_printf("%.*u, %.*x %.*X\n", 0, 0, 0, 0, 0, 0);
	address = 10;
	printf("============addr==========\n");
	ft_printf("|%p|\n", &address);
	printf("|%p|\n", &address);
	ft_printf("|%p|\n", &addheap);
	printf("%p\n", &addheap);
	ft_printf("|%5.5p|\n", &addheap);
	printf("|%5.5p|\n", &addheap);
	ft_printf("|%*.*p|\n", 5, 5,&addheap);
	printf("|%*.*p|\n",5, 5 ,&addheap);
	ft_printf("|%*.*p|\n", 5, 5,NULL);
	printf("|%*.*p|\n",5, 5 ,NULL);
	ft_printf("|%.*p|\n", 5,NULL);
	printf("|%.*p|\n", 5 ,NULL);
	ft_printf("|%*p|\n", 5,NULL);
	printf("|%*p|\n", 5 ,NULL);
	printf("%d", ft_printf("|%p|\n", NULL));
	printf("%d", printf("|%p|\n", NULL));

	printf("==================TO FIT TESTER================\n");
	static char	a01;
	static unsigned char a02;
	static short a03;
	static unsigned short a04;
	static int a05;
	static unsigned int a06;
	static long a07;
	static unsigned long a08;
	static long long a09;
	static unsigned long long a10;
	static char *a11;
	static void *a12;
	ft_printf("|%70p|\n|%70p|\n|%70p|\n|%70p|\n|%70p|\n|%70p|\n|%70p|\n|%70p|\n|%70p|\n|%70p|\n|%70p|\n|%70p|\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	printf("|%70p|\n|%70p|\n|%70p|\n|%70p|\n|%70p|\n|%70p|\n|%70p|\n|%70p|\n|%70p|\n|%70p|\n|%70p|\n|%70p|\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);

	ft_printf("|%15p|\n|%15p|\n|%15p|\n|%15p|\n|%15p|\n|%15p|\n|%15p|\n|%15p|\n|%15p|\n|%15p|\n|%15p|\n|%15p|\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	printf("|%15p|\n|%15p|\n|%15p|\n|%15p|\n|%15p|\n|%15p|\n|%15p|\n|%15p|\n|%15p|\n|%15p|\n|%15p|\n|%15p|\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf(" %p %% %c %u %s %X \n", addheap, (char)-1, 33, "abc", NULL);
	printf(" %p %% %c %u %s %X \n", addheap, (char)-1, 1, "abc", NULL);
	printf("ORIGIN:");
	printf("%hi\n", (short)(-32768));
	printf("MY:");
	ft_printf("%hi\n", (short)(-32768));
	ft_printf("%#037lx\n", 22337203685477ul);
	printf("%#037lx\n", 22337203685477ul);
	ft_printf("%#5.0X\n", 0);
	printf("%#5.0X\n", 0);
	ft_printf("this %#x number", 0);
	printf("this %#x number", 0);
	printf("%d",ft_printf("%5p", 0));
	printf("%d\n",printf("%5p", 0));
	static int x = 100000;
	ft_printf("-->|%#-4x|<--\n", x);
	printf("-->|%#-4x|<--\n", x);

	ft_printf("-->|%#*x|<--\n", -4, 0);
	printf("-->|%#*x|<--\n", -4, 0);


	ft_printf("-->|%#0*.2x|<--\n", 4, x);
	printf("-->|%#0*.2x|<--\n", 4, x);



	static t_ul a;
	static t_ul k;
	printf("-->|%%-4.%ln|<--", &k);
	printf("%d\n", k);
	ft_printf("-->|%%-4.%ln|<--", &a);
	printf("%d\n", a);

//	printf("-->|%#0*.2x, %x %x %x %x|<--\n", 4, x, x);
//	ft_printf("-->|1%#0*.2x,2%x 3%x 4%x 5%x|<--\n", 4, x, x);









	free(addheap);
	static unsigned int		mx_u = 235;
	static char				mx_c = 'G';
	static char			   *mx_s = "Hello, World!";
	static int				mx_i = 42;
	static long				mx_li =  4223372036854775800;
	static long long		mx_lli = 3223372036654775200;
	static short			mx_hi = -3244;
	static char				mx_hhi = 'F';

	ft_printf("%d", "asdf");
	printf("%d", "asdf");

	while(1){};
}
