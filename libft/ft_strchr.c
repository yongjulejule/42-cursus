/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:14:59 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/07 11:49:27 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char *str;

	str = (unsigned char*)s;
	while (*str != (unsigned char)c && (*str != 0))
		str++;
	if (*str != (unsigned char)c)
		return (NULL);
	return ((char*)str);
}
