/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_convert_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:16:22 by yongjule          #+#    #+#             */
/*   Updated: 2021/08/18 12:15:14 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

unsigned long long	hexa_to_int(const char *str)
{
	unsigned long long	num;

	num = 0;
	while (is_charset(*str, "0123456789abcdefABCDEF"))
	{
		if (is_charset(*str, "0123456789"))
			num = 16 * num + (*str - '0');
		else if (is_charset(*str, "abcdef"))
			num = 16 * num + (*str - 'a' + 10);
		else
			num = 16 * num + (*str - 'A' + 10);
		str++;
	}
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
