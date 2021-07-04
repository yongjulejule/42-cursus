/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_deci.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:28:23 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/24 08:53:52 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		width_in_deci(va_list ap, t_lidx *strs)
{
	va_list	cp_ap;
	int		len;

	len = get_width_len(ap, strs);
	va_copy(cp_ap, ap);
	if ((strs->opts.precision != strs->opts.width)\
			&& strs->txt[strs->opts.precision] == '*')
		va_arg(cp_ap, int);
	if (strs->txt[strs->opts.spec] != 'u')
		if (get_sign(cp_ap, strs) < 0\
				|| ft_memchr(strs->txt, '+', (size_t)(strs->opts.flags + 1))
			|| ft_memchr(strs->txt, ' ', (size_t)(strs->opts.flags + 1)))
		{
			if (len < 0)
				len++;
			else if (len > 0)
				len--;
			else
				len = 0;
		}
	va_end(cp_ap);
	return (len);
}

static int		precision_in_deci(va_list ap, t_lidx *strs)
{
	va_list	cp_ap;
	va_list	cp_nbr;
	int		len;
	int		tmplen;
	int		zero_flag;

	len = get_precision_len(ap, strs);
	va_copy(cp_ap, ap);
	va_copy(cp_nbr, ap);
	zero_flag = is_zero_nbr(cp_nbr, strs);
	if (zero_flag == 0 && len == 0)
	{
		strs->info--;
		return (0);
	}
	tmplen = get_nbr_len(cp_ap, strs, 10);
	if (len < tmplen)
		len = tmplen;
	va_end(cp_ap);
	va_end(cp_nbr);
	return (len);
}

static	void	print_dgt(va_list ap, t_lidx *strs, int len, int width_len)
{
	va_list	cp_ap;
	int		dgt_len;
	int		idx;

	idx = 0;
	if (!(ft_memchr(strs->txt, '0', (size_t)(strs->opts.flags + 1))
			&& strs->opts.precision == strs->opts.width) || width_len < 0
			|| ft_memchr(strs->txt, '-', strs->opts.flags + 1))
		ft_print_sign(ap, strs);
	va_copy(cp_ap, ap);
	dgt_len = get_nbr_len(ap, strs, 10);
	while (dgt_len < len)
	{
		ft_putchar_fd('0', 1);
		dgt_len++;
	}
	if (len != 0)
		ft_print_deci_nbr(cp_ap, strs);
	va_end(cp_ap);
	strs->info += dgt_len;
}

void			ft_print_deci(va_list ap, t_lidx *strs)
{
	int		precision_len;
	int		width_len;

	width_len = width_in_deci(ap, strs);
	precision_len = precision_in_deci(ap, strs);
	if (ft_memchr(strs->txt, '-', (strs->opts.flags + 1)) || width_len < 0)
	{
		print_dgt(ap, strs, precision_len, width_len);
		if (width_len < 0)
			width_len *= -1;
		ft_print_width(strs, ' ', width_len - precision_len);
	}
	else
	{
		if (ft_memchr(strs->txt, '0', (strs->opts.flags + 1))
				&& strs->opts.precision == strs->opts.width)
		{
			ft_print_sign(ap, strs);
			ft_print_width(strs, '0', width_len - precision_len);
		}
		else
			ft_print_width(strs, ' ', width_len - precision_len);
		print_dgt(ap, strs, precision_len, width_len);
	}
}
