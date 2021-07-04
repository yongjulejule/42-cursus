/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:07:09 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/24 08:53:33 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hash(t_lidx *strs, va_list ap)
{
	va_list	cp_ap;
	int		nbr;

	if (strs->txt[strs->opts.spec] != 'p')
	{
		va_copy(cp_ap, ap);
		if (get_length_flag(strs) > 2)
			nbr = va_arg(cp_ap, t_ull);
		else
			nbr = va_arg(cp_ap, t_ui);
		va_end(cp_ap);
		if (!ft_memchr(strs->txt, '#', (strs->opts.flags + 1)) || nbr == 0)
			return ;
	}
	if (strs->txt[strs->opts.spec] == 'X')
		ft_putstr_fd("0X", 1);
	else
		ft_putstr_fd("0x", 1);
	strs->info += 2;
}
