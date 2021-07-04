/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:46:43 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/09 14:21:47 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	idx;
	size_t	len;
	char	*tmp;

	idx = 0;
	len = ft_strlen(s1);
	tmp = (char*)malloc(len + 1);
	if (tmp == 0)
		return (0);
	while (idx < len)
	{
		*(tmp + idx) = *(s1 + idx);
		idx++;
	}
	*(tmp + len) = '\0';
	return (tmp);
}
