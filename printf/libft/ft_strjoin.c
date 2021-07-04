/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:49:01 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/09 09:35:36 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	idx_1;
	size_t	idx_2;

	if (s2 == NULL || s1 == NULL)
		return (NULL);
	idx_1 = 0;
	if (!(str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
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
	*(str + idx_1) = '\0';
	return (str);
}
