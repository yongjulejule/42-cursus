/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_for_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:19:37 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/24 08:59:55 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	is_spec(char c)
{
	int idx;

	idx = 0;
	while (SPECS[idx])
	{
		if (c == SPECS[idx])
			return (SUCCESS_FLAG);
		idx++;
	}
	return (ERROR_FLAG);
}

static	int	split_percent(char *string, t_lidx **strs)
{
	int		idx;
	char	*splited_str;

	idx = 1;
	while (*(string + idx) != '\0' && !is_spec(*(string + idx)))
		idx++;
	idx++;
	if (!(splited_str = ft_substr(string, 0, idx)))
		return (-1);
	ft_lidxadd_back(strs, ft_lidxnew(splited_str, IS_FLAGS));
	free(splited_str);
	splited_str = NULL;
	if (!strs)
		return (-1);
	return (idx);
}

static	int	split_not_percent(char *string, t_lidx **strs)
{
	int		idx;
	char	*splited_str;

	idx = 0;
	while (*(string + idx + 1) != '\0' && *(string + idx + 1) != '%')
		idx++;
	idx++;
	if (!(splited_str = ft_substr(string, 0, idx)))
		return (-1);
	ft_lidxadd_back(strs, ft_lidxnew(splited_str, IS_NOT_FLAG));
	free(splited_str);
	splited_str = NULL;
	if (!strs)
		return (-1);
	return (idx);
}

static	int	init_split(char *format, t_lidx **strs)
{
	int		idx;
	char	*splited_str;

	idx = 0;
	if (*(format + idx) != '%')
		while (*(format + idx + 1) != '\0' && *(format + idx + 1) != '%')
			idx++;
	else
	{
		idx++;
		while (*(format + idx) != '\0' && !is_spec(*(format + idx)))
			idx++;
	}
	idx++;
	if (!(splited_str = ft_substr(format, 0, idx)))
		return (-1);
	(*strs) = ft_lidxnew(splited_str, IS_NOT_FLAG);
	free(splited_str);
	splited_str = NULL;
	if (!strs)
		return (-1);
	return (idx);
}

int			ft_split_for_pf(char *format, t_lidx **strs)
{
	int		idx;
	int		len;
	size_t	size;

	size = ft_strlen(format);
	if ((idx = init_split(format, strs)) == -1)
		return (ERROR_FLAG);
	while ((size_t)idx < size)
	{
		if (format[idx] != '%')
		{
			if ((len = split_not_percent(format + idx, strs)) == -1)
				return (ERROR_FLAG);
			idx += len;
		}
		else
		{
			if ((len = split_percent(format + idx, strs)) == -1)
				return (ERROR_FLAG);
			idx += len;
		}
	}
	return (SUCCESS_FLAG);
}
