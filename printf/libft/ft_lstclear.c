/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:41:38 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/09 14:00:58 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *tmp;

	if (lst == NULL || *lst == NULL)
		return ;
	tmp = *lst;
	if (tmp->next == NULL)
		ft_lstdelone(tmp, del);
	else
	{
		while (tmp->next != NULL)
		{
			*lst = tmp;
			tmp = tmp->next;
			del((*lst)->content);
			free(*lst);
			*lst = NULL;
			if (tmp->next == NULL)
			{
				ft_lstdelone(tmp, del);
				return ;
			}
		}
	}
}
