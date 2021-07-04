/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:12:13 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/24 09:01:25 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		get_flags(t_lidx **str)
{
	t_lidx *tmp;

	tmp = *str;
	while (tmp)
	{
		check_flags(tmp);
		tmp = (tmp)->next;
	}
	return (SUCCESS_FLAG);
}

int				parsing(char *format, t_lidx **strs)
{
	if (!ft_split_for_pf(format, strs))
		return (ERROR_FLAG);
	if (!get_flags(strs))
		return (ERROR_FLAG);
	return (SUCCESS_FLAG);
}
