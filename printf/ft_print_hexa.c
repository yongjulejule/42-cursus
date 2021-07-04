/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:28:23 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/24 10:27:12 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		width_in_hexa(va_list ap, t_lidx *strs)
{
	va_list	cp_ap;
	t_ull	nbr;
	int		width_len;

	width_len = get_width_len(ap, strs);
	va_copy(cp_ap, ap);
	if (strs->opts.precision != strs->opts.width\
			&& strs->txt[strs->opts.precision] == '*')
		va_arg(cp_ap, int);
	if (get_length_flag(strs) > 2)
		nbr = va_arg(cp_ap, t_ull);
	else
		nbr = va_arg(cp_ap, t_ui);
	va_end(cp_ap);
	if ((ft_memchr(strs->txt, '#', (strs->opts.flags + 1)) && nbr != 0)
			|| strs->txt[strs->opts.spec] == 'p')
	{
		if (width_len < -1)
			width_len += 2;
		else if (width_len > 1)
			width_len -= 2;
		else
			width_len = 0;
	}
	return (width_len);
}

static	int		precision_in_hexa(va_list ap, t_lidx *strs)
{
	va_list	cp_ap;
	va_list cp_nbr;
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
	tmplen = get_nbr_len(cp_ap, strs, 16);
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

	width_len = 0;
	va_copy(cp_ap, ap);
	dgt_len = get_nbr_len(ap, strs, 16);
	while (dgt_len < len)
	{
		ft_putchar_fd('0', 1);
		dgt_len++;
	}
	if (len != 0)
		ft_print_hexa_nbr(cp_ap, strs);
	va_end(cp_ap);
	strs->info += dgt_len;
}

static	void	print_with_width(va_list ap, t_lidx *strs,\
				int width_len, int precision_len)
{
	if ((ft_memchr(strs->txt, '0', (strs->opts.flags + 1))
				&& strs->opts.precision == strs->opts.width))
	{
		ft_print_hash(strs, ap);
		ft_print_width(strs, '0', width_len - precision_len);
	}
	else
	{
		ft_print_width(strs, ' ', width_len - precision_len);
		ft_print_hash(strs, ap);
	}
	print_dgt(ap, strs, precision_len, width_len);
}

void			ft_print_hexa(va_list ap, t_lidx *strs)
{
	int		precision_len;
	int		width_len;

	width_len = width_in_hexa(ap, strs);
	precision_len = precision_in_hexa(ap, strs);
	if (ft_memchr(strs->txt, '-', strs->opts.flags + 1) || width_len < 0)
	{
		ft_print_hash(strs, ap);
		print_dgt(ap, strs, precision_len, width_len);
		if (width_len < 0)
			width_len *= -1;
		ft_print_width(strs, ' ', width_len - precision_len);
	}
	else
		print_with_width(ap, strs, width_len, precision_len);
}
