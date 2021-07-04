/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 00:43:57 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/20 16:22:06 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	get_4bit_len(va_list ap, t_lidx *strs, int base)
{
	int cnt;

	if (strs->txt[strs->opts.spec] == 'd' || strs->txt[strs->opts.spec] == 'i')
	{
		if (get_length_flag(strs) == 1)
			cnt = ft_dgt_short_len(va_arg(ap, int), base);
		else if (get_length_flag(strs) == 2)
			cnt = ft_dgt_char_len(va_arg(ap, int), base);
		else
			cnt = ft_dgtlen(va_arg(ap, int), base);
	}
	else
	{
		if (get_length_flag(strs) == 1)
			cnt = ft_dgt_ushort_len(va_arg(ap, int), base);
		else if (get_length_flag(strs) == 2)
			cnt = ft_dgt_uchar_len(va_arg(ap, int), base);
		else
			cnt = ft_dgt_ui_len(va_arg(ap, int), base);
	}
	return (cnt);
}

static	int	get_8bit_len(va_list ap, t_lidx *strs, int base)
{
	int cnt;

	if (strs->txt[strs->opts.spec] == 'd' || strs->txt[strs->opts.spec] == 'i')
		if (get_length_flag(strs) == 3)
			cnt = ft_dgt_l_len(va_arg(ap, long), base);
		else
			cnt = ft_dgt_ll_len(va_arg(ap, t_ll), base);
	else
	{
		if (get_length_flag(strs) == 3)
			cnt = ft_dgt_ul_len(va_arg(ap, t_ul), base);
		else
			cnt = ft_dgt_ull_len(va_arg(ap, t_ull), base);
	}
	return (cnt);
}

int			get_nbr_len(va_list ap, t_lidx *strs, int base)
{
	int		cnt;

	if (((strs->opts.length != strs->opts.precision
			&& strs->txt[strs->opts.precision + 1] == 'l'))\
			|| strs->txt[strs->opts.spec] == 'p')
		cnt = get_8bit_len(ap, strs, base);
	else
		cnt = get_4bit_len(ap, strs, base);
	return (cnt);
}
