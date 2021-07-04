/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:14:37 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/13 15:10:27 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	tmp;
	unsigned char	*string;
	size_t			idx;

	idx = 0;
	string = (unsigned char*)s;
	tmp = (unsigned char)c;
	while (idx < n && *string != tmp)
	{
		string++;
		idx++;
	}
	if (idx == n)
		return (NULL);
	return (string);
}
