/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_fuc_w_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:25:30 by jun               #+#    #+#             */
/*   Updated: 2021/07/24 12:17:36 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	*ft_calloc_w_error(size_t count, size_t size)
{
	unsigned char	*str;
	size_t			idx;

	idx = 0;
	str = (unsigned char *)malloc(sizeof(unsigned char) * size * count);
	if (str == 0)
		is_error("Error while Memory Allocating");
	while (idx < count * size)
	{
		*(str + idx) = 0;
		idx++;
	}
	return (str);
}

static	size_t	min_len(size_t len1, size_t len2)
{
	if (len1 > len2)
		return (len2);
	else
		return (len1);
}

char	*ft_substr_w_error(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	idx;

	idx = 0;
	if (s == NULL)
		return (NULL);
	while (idx < start)
	{
		if (*(s + idx) == '\0')
			return (ft_strdup(""));
		idx++;
	}
	idx = 0;
	substring = (char *)ft_calloc_w_error(min_len(len,
				ft_strlen(s) - start) + 1, sizeof(char));
	while (idx < len && (*(s + start + idx) != 0))
	{
		*(substring + idx) = *(s + start + idx);
		idx++;
	}
	return (substring);
}

char	*ft_strjoin_w_error(char const *s1, char const *s2)
{
	char	*str;
	size_t	idx_1;
	size_t	idx_2;

	if (s2 == NULL || s1 == NULL)
		return (NULL);
	idx_1 = 0;
	str = (char *)ft_calloc_w_error(sizeof(char),
			ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (*(s1 + idx_1))
	{
		*(str + idx_1) = *(s1 + idx_1);
		idx_1++;
	}
	idx_2 = 0;
	while (*(s2 + idx_2))
	{
		*(str + idx_1) = *(s2 + idx_2);
		idx_1++;
		idx_2++;
	}
	return (str);
}
