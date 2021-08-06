/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_basis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:16:22 by yongjule          #+#    #+#             */
/*   Updated: 2021/08/06 15:58:43 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hexa_to_int(const char *str);
{
}

static int	bi_to_int(const char *str);
{
}

static int	oct_to_int(const char *str);
{
}


static int	convert_to_int(const char *str)
{
	int	num;

	while (*str == '0')
		str++;
	if (*str == 'x' || *str == 'X')
		num = hexa_to_int();
	else if (*str == 'b' || *str == 'B')
		num = bi_to_int();
	else if (*str > 0 && *str <= '9')
		num = oct_to_int();
	else
		return (0);
}

int	ft_atoi_basis(const char *str)
{
	unsigned long long	num;
	int					sign;

	sign = 1;
	num = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (*str > '0' && *str <= '9')
		return (sign * ft_atoi(str));
	else if (*str == '0')
		num = convert_to_int(str);
	else 
	{
		ft_putendl_fd("Data is not number", 2);
		exit(EXIT_FAILURE);
	}
	return (sign * num);
}
