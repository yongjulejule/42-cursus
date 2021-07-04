/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:22:43 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/24 09:00:56 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	print_decimal(va_list ap, t_lidx *strs, t_ull total_len)
{
	if (strs->txt[strs->opts.spec] == 'n')
		ft_handle_n_spec(ap, strs, total_len);
	else
		ft_print_deci(ap, strs);
	return (strs->info);
}

static	int	print_hex(va_list ap, t_lidx *strs)
{
	ft_print_hexa(ap, strs);
	return (strs->info);
}

static	int	print_chrs(va_list ap, t_lidx *strs)
{
	if (strs->txt[strs->opts.spec] == 'c' || strs->txt[strs->opts.spec] == '%')
		ft_print_char(ap, strs);
	else
		ft_print_str(ap, strs);
	return (strs->info);
}

static	int	print_args(va_list ap, t_lidx *strs, t_ull total_len)
{
	int		idx;
	int		len;
	size_t	size;

	idx = 0;
	len = 0;
	size = ft_strlen(SPECS);
	while ((size_t)idx < size)
	{
		if (strs->txt[strs->opts.spec] == SPECS[idx])
		{
			if (idx < 4)
				len = print_decimal(ap, strs, total_len);
			else if (idx < 7)
				len = print_hex(ap, strs);
			else
				len = print_chrs(ap, strs);
			break ;
		}
		idx++;
	}
	return (len);
}

/*
** print arguments and strings
*/

int			go_print(va_list ap, t_lidx *strs)
{
	t_ull len;

	len = 0;
	while (strs)
	{
		if (strs->info == IS_NOT_FLAG)
		{
			ft_putstr_fd(strs->txt, 1);
			len += ft_strlen(strs->txt);
		}
		else
			len += print_args(ap, strs, len);
		strs = strs->next;
	}
	return (len);
}
