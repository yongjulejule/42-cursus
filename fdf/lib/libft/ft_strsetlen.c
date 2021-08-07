/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsetlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 15:24:52 by jun               #+#    #+#             */
/*   Updated: 2021/08/07 16:15:23 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strsetlen(char **strs)
{
	int	cnt;

	cnt = 0;
	if (strs == NULL)
		return (0);
	if (*strs == NULL)
		return (0);
	while (*strs)
	{
		if (**strs == '\0')
			break ;
		cnt++;
		strs++;
	}
	return (cnt);
}
