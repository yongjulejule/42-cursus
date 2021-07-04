/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:29:02 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/04 12:45:16 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		len;

	len = ft_strlen(s);
	str = (char*)s;
	while (len > 0)
	{
		if (*(str + len) == (char)c)
			return (str + len);
		len--;
	}
	if (*str == (char)c)
		return (str);
	return (NULL);
}
