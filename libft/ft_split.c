/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 18:13:39 by yongjule          #+#    #+#             */
/*   Updated: 2021/07/04 14:07:15 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_chr(char c, char ch)
{
	if (c == ch)
		return (1);
	return (0);
}

static int	get_size(char *str, char c)
{
	int	size;

	size = 0;
	if (!str)
		return (size);
	while (*str)
	{
		if (!check_chr(*str, c))
		{
			size++;
			while (*str && !check_chr(*str, c))
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
	tmp[idx] = (char *)malloc(i - start + 1);
	if (!tmp[idx])
	{
		while (0 <= idx)
		{
			free(tmp[idx]);
			idx--;
		}
		free(tmp);
		return (NULL);
	}
	return (tmp);
}

static	char	**get_strs(char *s, char c, char **tmp)
{
	int	i;
	int	idx;
	int	start;

	i = 0;
	idx = 0;
	while (*(s + i))
	{
		if (!check_chr(*(s + i), c))
		{
			start = i;
			while (*(s + i) && !check_chr(*(s + i), c))
				i++;
			tmp = alloc_mem(tmp, start, i, idx);
			if (!tmp)
				return (NULL);
			ft_strlcpy(tmp[idx++], (char *)(s + start), i - start + 1);
		}
		if (*(s + i) != '\0')
			i++;
	}
	return (tmp);
}

char	**ft_split(char const *s, char c)
{
	char	**tmp;

	if (!s)
		return (NULL);
	tmp = (char **)ft_calloc(get_size((char *)s, c), sizeof(char *));
	if (!tmp)
		return (NULL);
	return (get_strs((char *)s, c, tmp));
}
