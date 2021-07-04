/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 12:40:57 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/20 16:22:28 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_zero_nbr(va_list cp_nbr, t_lidx *strs)
{
	t_ll	nbr;

	if (get_length_flag(strs) == 4 || strs->txt[strs->opts.spec] == 'p')
		nbr = va_arg(cp_nbr, t_ll);
	else if (get_length_flag(strs) == 3)
		nbr = va_arg(cp_nbr, long);
	else
		nbr = va_arg(cp_nbr, t_ui);
	if (nbr == 0)
		return (0);
	return (1);
}
