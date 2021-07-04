/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 12:21:01 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/20 16:47:31 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	check_spec(t_lidx *str)
{
	int idx;
	int jdx;

	jdx = 0;
	idx = str->opts.length;
	idx++;
	while (jdx < 11)
	{
		if (str->txt[idx] == '\0')
			break ;
		if (str->txt[idx] == SPECS[jdx])
		{
			str->opts.spec = idx;
			str->info = IS_FLAGS;
			return ;
		}
		jdx++;
	}
	idx--;
	str->opts.spec = idx;
	str->info = IS_NOT_FLAG;
}

static	void	check_length(t_lidx *str)
{
	int idx;

	idx = str->opts.precision;
	idx++;
	if (str->txt[idx] == 'h')
	{
		idx++;
		if (str->txt[idx] == 'h')
			idx++;
	}
	else if (str->txt[idx] == 'l')
	{
		idx++;
		if (str->txt[idx] == 'l')
			idx++;
	}
	idx--;
	str->opts.length = idx;
	check_spec(str);
}

static	void	check_precision(t_lidx *str)
{
	int idx;

	idx = str->opts.width;
	idx++;
	if (str->txt[idx] == '.')
	{
		idx++;
		if (str->txt[idx] == '*')
			idx++;
		else
			while (ft_isdigit(str->txt[idx]))
				idx++;
	}
	idx--;
	str->opts.precision = idx;
	check_length(str);
}

static	void	check_width(t_lidx *str)
{
	int idx;

	idx = str->opts.flags;
	idx++;
	if (str->txt[idx] > '0' && str->txt[idx] <= '9')
		while (ft_isdigit(str->txt[idx]))
			idx++;
	else if (str->txt[idx] == '*')
		idx++;
	idx--;
	str->opts.width = idx;
	check_precision(str);
}

void			check_flags(t_lidx *str)
{
	int idx;

	if (str->txt[0] != '%')
	{
		str->info = IS_NOT_FLAG;
		return ;
	}
	idx = 1;
	while (str->txt[idx] == '-'\
			|| str->txt[idx] == '+'\
			|| str->txt[idx] == ' '\
			|| str->txt[idx] == '0'\
			|| str->txt[idx] == '#')
		idx++;
	idx--;
	str->opts.flags = idx;
	check_width(str);
}
