/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 19:25:54 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/06 10:55:46 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		to_string(int n, int cnt, char *str)
{
	int	digit;

	cnt--;
	while (n)
	{
		digit = n % 10;
		if (digit < 0)
			digit *= -1;
		*(str + cnt) = digit + '0';
		n /= 10;
		cnt--;
	}
}

static	int		get_digit(int n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (0);
	while (n != 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

static	char	*is_zero(void)
{
	char	*str;

	str = (char *)malloc(2);
	*str = '0';
	*(str + 1) = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		cnt;

	if (n == 0)
	{
		str = is_zero();
		return (str);
	}
	cnt = get_digit(n);
	if (n < 0)
	{
		if (!(str = (char*)malloc(sizeof(char) * cnt + 2)))
			return (NULL);
		*str = '-';
		*(str + cnt + 1) = '\0';
		to_string(n, cnt, str + 1);
	}
	else
	{
		if (!(str = (char*)malloc(sizeof(char) * cnt + 1)))
			return (NULL);
		*(str + cnt) = '\0';
		to_string(n, cnt, str);
	}
	return (str);
}
