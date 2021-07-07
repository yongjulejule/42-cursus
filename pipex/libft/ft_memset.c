/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:09:21 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/03 14:11:43 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*res;
	size_t			idx;

	res = (unsigned char *)b;
	idx = 0;
	while (idx < len)
	{
		*res = (unsigned char)c;
		res++;
		idx++;
	}
	return (b);
}
