/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_deci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:16:22 by yongjule          #+#    #+#             */
/*   Updated: 2021/08/06 17:42:52 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static unsigned long long	lower_case_hexa(const char *str)
{
	unsigned long long	num;

	num = 0;
	while (is_charset(*str, "0123456789abcdef"))
	{
		if (is_charset(*str, "0123456789"))
			num = 16 * num + (*str - '0');
		else
			num = 16 * num + (*str - 'a' + 10);
		str++;
	}
	return (num);
}

static unsigned long long	upper_case_hexa(const char *str)
{
	unsigned long long	num;

	num = 0;
	while (is_charset(*str, "0123456789ABCDEF"))
	{
		if (is_charset(*str, "0123456789"))
			num = 16 * num + (*str - '0');
		else
			num = 16 * num + (*str - 'A' + 10);
		str++;
	}
	return (num);
}

unsigned long long	hexa_to_int(const char *str)
{
	unsigned long long	num;

	num = 0;
	if (*str == 'x')
		num = lower_case_hexa(str + 1);
	else
		num = upper_case_hexa(str + 1);
	return (num);
}

unsigned long long	bi_to_int(const char *str)
{
	unsigned long long	num;

	num = 0;
	while (*str == '0' || *str == '1')
	{
		num = 2 * num + (*str++ - '0');
		if (num > LIMIT_VALUE)
		{
			ft_putendl_fd("Data is out of given range", 2);
			exit(EXIT_FAILURE);
		}
	}
	return (num);
}

unsigned long long	oct_to_int(const char *str)
{
	unsigned long long	num;

	num = 0;
	while (*str >= '0' && *str <= '7')
	{
		num = 8 * num + (*str++ - '0');
		if (num > LIMIT_VALUE)
		{
			ft_putendl_fd("Data is out of given range", 2);
			exit(EXIT_FAILURE);
		}
	}
	return (num);
}
