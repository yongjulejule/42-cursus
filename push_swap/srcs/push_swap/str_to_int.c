/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 12:54:16 by jun               #+#    #+#             */
/*   Updated: 2021/07/24 13:33:33 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	arg_cnt(char **tmp)
{
	int idx;

	idx = 0;
	while (tmp[idx])
		idx++;
	return (idx);
}


static int	go_to_digit(char *str, int *sign)
{
	int idx;

	idx = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign *= -1;
		idx++;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			is_error("Error : argv should contain only digit and single sign");
		str++;
	}
	return (idx);
}

int	ft_atoi_only_num(const char *str)
{
	unsigned long long	num;
	int					sign;
	int					idx;

	sign = 1;
	num = 0;
	idx = go_to_digit((char *)str, &sign);
	while (*(str + idx) >= '0' && *(str + idx) <= '9')
	{
		num = 10 * num + (*(str + idx) - '0');
		idx++;
	}
	if (num > 2147483647)
	{
		if (num == 2147483648 && sign < 0 )
			return (sign * num);
		is_error("Error : argv is not INT");
	}
	free((char *)str);
	str = NULL;
	return (sign * num);
}

int	*strset_to_integer(char **tmp, int *ac)
{
	int	*av_int;
	int	idx;

	*ac = arg_cnt(tmp);
	av_int = ft_calloc_w_error(sizeof(int*), *ac);
	idx = 0;
	while (tmp[idx])
	{
		av_int[idx] = ft_atoi_only_num(tmp[idx]);
		idx++;
	}
	free(tmp);
	tmp = NULL;
	return (av_int);
}
