#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>
int main()
{
	setbuf(stdout, NULL);
	setlocale(LC_ALL, "en_US.UTF-8");
	wchar_t *a = L"🔥우와 이게 되네🥺\nGreek latter: Ελληνικό αλφάβητο\
			 \nArabic: لأَبْجَدِيَّة العَرَبِيَّة al-abjadīyah al-ʻarabīyah ค้้้้้้้้้้้้้้้้้้้้้้้้้้้้้้้้้้้้้้้้้้้้้้้้้้้้้้้\n(ส็็็็็็็็็็็็็็็็็็็°□°)ส้้้้้้้้้้้้้\
			 \nKorean: 꺆 꺆 너무 쒼나 뷁뚫쉞궳\nGet Crazy: iœ♡☁︎☹︎♘*🔥♡\n";
	wchar_t *b = L"😜 Hello 👋 Unicode ‼️ \n";
	int idx;

	idx = 0;
	while (a[idx])
	{
		ft_putchar_utf_fd(a[idx], 1);
		idx++;
	}
	idx = 0;
	while (b[idx])
	{
		ft_putchar_utf_fd(b[idx], 1);
		idx++;
	}
	ft_printf("MY: |%ls|\n", L"아왜이래");
	ft_printf("MY: |%-100ls|\n", a);
	printf("LIB: |%-100ls|\n", a);
	ft_printf("MY: |%5ls|\n", L"🤯");
	printf("LIB:|%5ls|\n", L"🤯");
	ft_printf("MY: |%5ls|\n", L"과");
	printf("LIB:|%5ls|\n", L"과");
}
