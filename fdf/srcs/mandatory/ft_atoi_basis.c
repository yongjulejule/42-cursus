/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_basis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:16:22 by yongjule          #+#    #+#             */
/*   Updated: 2021/08/07 12:28:04 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO
#include "../../includes/fdf.h"

static unsigned long long	deci_to_int(const char *str)
{
	unsigned long long	num;

	num = 0;
	while (*str >= '0' && *str <= '9')
		num = 10 * num + (*str++ - '0');
	if (num > LIMIT_VALUE)
	{
		ft_putendl_fd("Data is out of given range", 2);
		exit(EXIT_FAILURE);
	}
	return (num);
}

static unsigned long long	convert_to_int(const char *str)
{
	unsigned long long	num;

	while (*str == '0')
		str++;
	if (*str == 'x' || *str == 'X')
		num = hexa_to_int(str);
	else if (*str == 'b' || *str == 'B')
		num = bi_to_int(str + 1);
	else if (*str > 0 && *str <= '9')
		num = oct_to_int(str);
	else
		return (0);
	return (num);
}

int	ft_atoi_basis(const char *str)
{
	unsigned long long	num;
	int					sign;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (*str > '0' && *str <= '9')
		num = deci_to_int(str);
	else if (*str == '0')
		num = convert_to_int(str);
	else 
	{
		ft_putendl_fd("Data is not number", 2);
		exit(EXIT_FAILURE);
	}
	if (num > LIMIT_VALUE)
	{
		ft_putendl_fd("Data is out of range", 2);
		exit(EXIT_FAILURE);
	}
	return (sign * num);
}
