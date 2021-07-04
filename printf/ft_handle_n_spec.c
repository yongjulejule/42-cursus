/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_n_spec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:51:00 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/24 08:53:16 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	move_va(va_list ap, t_lidx *strs)
{
	if (strs->opts.flags != strs->opts.width)
		if (strs->txt[strs->opts.width] == '*')
			va_arg(ap, int);
	if (strs->opts.width != strs->opts.precision)
		if (strs->txt[strs->opts.precision] == '*')
			va_arg(ap, int);
}

void			ft_handle_n_spec(va_list ap, t_lidx *strs, t_ull total_len)
{
	int	flag;

	flag = get_length_flag(strs);
	move_va(ap, strs);
	if (flag == 1)
		get_uchar_byte(ap, total_len);
	else if (flag == 2)
		get_ushort_byte(ap, total_len);
	else if (flag == 3)
		get_ul_byte(ap, total_len);
	else if (flag == 4)
		get_ull_byte(ap, total_len);
	else
		get_ui_byte(ap, total_len);
}
