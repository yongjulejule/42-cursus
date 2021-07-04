/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:00:38 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/05 12:39:29 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cmpchr(char s, char const *set)
{
	int	idx;

	idx = 0;
	while (*(set + idx))
	{
		if (*(set + idx) == s)
			return (1);
		idx++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		idx;
	int		len;

	if (s1 == 0 || set == 0)
		return (NULL);
	len = ft_strlen(s1);
	len--;
	idx = 0;
	while (cmpchr(*(s1 + idx), set) && idx < len)
		idx++;
	while (cmpchr(*(s1 + len), set) && len > 0)
		len--;
	if (idx > len)
	{
		str = ft_strdup("");
		return (str);
	}
	if (!(str = (char*)malloc(len - idx + 2)))
		return (NULL);
	ft_memcpy(str, s1 + idx, len - idx + 1);
	*(str + len - idx + 1) = '\0';
	return (str);
}
