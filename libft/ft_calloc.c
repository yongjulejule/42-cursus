/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:18:23 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/09 13:50:30 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*str;
	size_t			idx;

	idx = 0;
	str = (unsigned char*)malloc(sizeof(unsigned char) * size * count);
	if (str == 0)
		return (0);
	while (idx < count * size)
	{
		*(str + idx) = 0;
		idx++;
	}
	return (str);
}
