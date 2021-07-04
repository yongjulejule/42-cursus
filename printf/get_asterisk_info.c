/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_asterisk_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 13:31:14 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/21 21:29:46 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_width_len(va_list ap, t_lidx *strs)
{
	int		len;

	if (strs->opts.flags == strs->opts.width)
		return (0);
	if (strs->txt[strs->opts.width] == '*')
		len = va_arg(ap, int);
	else
		len = ft_atoi(strs->txt + strs->opts.flags + 1);
	return (len);
}

int		get_precision_len(va_list ap, t_lidx *strs)
{
	int		len;

	if (strs->opts.width == strs->opts.precision)
		return (-1);
	if (strs->txt[strs->opts.precision] == '.')
		return (0);
	if (strs->txt[strs->opts.precision] == '*')
		len = va_arg(ap, int);
	else
		len = ft_atoi(strs->txt + strs->opts.width + 2);
	if (len < 0)
		strs->opts.width = strs->opts.precision;
	return (len);
}
