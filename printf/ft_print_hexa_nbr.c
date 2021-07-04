/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_nbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 02:20:31 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/20 14:16:03 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	put_4bit_hexa_nbr(va_list cp_ap, t_lidx *strs)
{
	if (get_length_flag(strs) == 1)
		ft_putnbr_ushort_hexa_fd(strs, va_arg(cp_ap, t_ui), 1);
	else if (get_length_flag(strs) == 2)
		ft_putnbr_uchar_hexa_fd(strs, va_arg(cp_ap, t_ui), 1);
	else
		ft_putnbr_ui_hexa_fd(strs, va_arg(cp_ap, t_ui), 1);
	va_end(cp_ap);
}

static	void	put_8bit_hexa_nbr(va_list cp_ap, t_lidx *strs)
{
	if (get_length_flag(strs) == 3)
		ft_putnbr_ul_hexa_fd(strs, va_arg(cp_ap, t_ul), 1);
	else if (get_length_flag(strs) == 4\
			|| (strs->txt[strs->opts.spec] == 'p'))
		ft_putnbr_ull_hexa_fd(strs, va_arg(cp_ap, t_ull), 1);
	va_end(cp_ap);
}

void			ft_print_hexa_nbr(va_list cp_ap, t_lidx *strs)
{
	if ((strs->opts.length >= 0
			&& (strs->txt[strs->opts.length] == 'l'))\
			|| (strs->txt[strs->opts.spec] == 'p'))
		put_8bit_hexa_nbr(cp_ap, strs);
	else
		put_4bit_hexa_nbr(cp_ap, strs);
}
