/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 18:13:39 by yongjule          #+#    #+#             */
/*   Updated: 2021/08/07 15:11:54 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_chr(char c, char *charset)
{
	if (c == '\0')
		return (0);
	while (c != *charset && *charset != '\0')
		charset++;
	if (*charset != '\0')
		return (1);
	return (0);
}

static int	get_size(char *str, char *charset)
{
	int	size;

	size = 0;
	if (!str)
		return (size);
	while (*str)
	{
		if (!check_chr(*str, charset))
		{
			size++;
			while (*str && !check_chr(*str, charset))
				str++;
		}
		if (*str != '\0')
			str++;
	}
	size++;
	return (size);
}

static	char	**alloc_mem(char **tmp, int start, int i, int idx)
{
	tmp[idx] = (char *)ft_calloc(i - start + 1, sizeof(char));
	return (tmp);
}

static	char	**get_strs(char *s, char *charset, char **tmp)
{
	int	i;
	int	idx;
	int	start;

	i = 0;
	idx = 0;
	while (*(s + i))
	{
		if (!check_chr(*(s + i), charset))
		{
			start = i;
			while (*(s + i) && !check_chr(*(s + i), charset))
				i++;
			tmp = alloc_mem(tmp, start, i, idx);
			ft_strlcpy(tmp[idx++], (char *)(s + start), i - start + 1);
		}
		if (*(s + i) != '\0')
			i++;
	}
	return (tmp);
}

char	**ft_split_charset(char const *s, char *charset)
{
	char	**tmp;

	if (!s)
		return (NULL);
	tmp = (char **)ft_calloc(get_size((char *)s, charset), sizeof(char *));
	return (get_strs((char *)s, charset, tmp));
}
