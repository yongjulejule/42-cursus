/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 19:50:57 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/09 15:02:27 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		idx;
	int		len;
	char	*str;

	if (s == 0)
		return (NULL);
	len = ft_strlen(s);
	if (!(str = (char*)malloc(len + 1)))
		return (NULL);
	idx = 0;
	while (*(s + idx))
	{
		*(str + idx) = f(idx, *(s + idx));
		idx++;
	}
	*(str + idx) = '\0';
	return (str);
}
