/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 04:25:19 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/16 16:50:48 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Not Exist = 0
** Is h = 1
** Is hh = 2
** Is l = 3
** Is ll = 4
*/

int		get_length_flag(t_lidx *strs)
{
	if (strs->opts.length < 0\
			|| strs->opts.precision == strs->opts.length)
		return (0);
	if (strs->opts.precision + 1 == strs->opts.length)
	{
		if (strs->txt[strs->opts.length] == 'h')
			return (1);
		else
			return (3);
	}
	else if (strs->opts.precision + 2 == strs->opts.length)
	{
		if (strs->txt[strs->opts.length] == 'h')
			return (2);
		else if (strs->txt[strs->opts.length] == 'l')
			return (4);
		else
			return (0);
	}
	else
		return (0);
}
