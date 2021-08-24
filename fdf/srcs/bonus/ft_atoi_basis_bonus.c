/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_basis_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:16:22 by yongjule          #+#    #+#             */
/*   Updated: 2021/08/24 21:16:55 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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
		num = hexa_to_int(str + 1);
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

	if (str == NULL)
		return (0);
	sign = 1;
	num = 0;
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
		is_error("Data is not Number! Check it");
	if (num > LIMIT_VALUE)
		is_error("Data is out of range...!");
	return (sign * num);
}
