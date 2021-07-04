/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:55:59 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/20 11:26:54 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list *newlst;
	t_list *root_newlst;

	if (lst == NULL)
		return (NULL);
	if (!(newlst = ft_lstnew(f(lst->content))))
		return (NULL);
	root_newlst = newlst;
	while (lst->next != NULL)
	{
		if (!(newlst->next = ft_lstnew(f(lst->next->content))))
		{
			ft_lstclear(&root_newlst, del);
			return (NULL);
		}
		if (lst->next != NULL)
			lst = lst->next;
		newlst = newlst->next;
	}
	return (root_newlst);
}
