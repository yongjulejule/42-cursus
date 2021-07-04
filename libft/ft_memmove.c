/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:23:45 by yongjule          #+#    #+#             */
/*   Updated: 2021/07/04 10:53:21 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp;
	unsigned char	*dest;
	size_t			idx;

	idx = 0;
	dest = (unsigned char *)dst;
	tmp = (unsigned char *)src;
	if (src < dst)
	{
		while (0 < len)
		{
			len--;
			*(dest + len) = *(tmp + len);
		}
	}
	else if (src > dst)
	{
		while (idx < len)
		{
			*(dest + idx) = *(tmp + idx);
			idx++;
		}
	}
	return (dst);
}
