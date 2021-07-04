/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 11:07:30 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/24 10:50:16 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lidxadd_back(t_lidx **lst, t_lidx *new)
{
	t_lidx *start;
	t_lidx *tmp;

	start = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lidxlast(*lst);
	tmp->next = new;
	*lst = start;
}

void	ft_lidxclear(t_lidx **lst, void (*del)(void*))
{
	t_lidx *tmp;

	if (lst == NULL || *lst == NULL)
		return ;
	tmp = *lst;
	if (tmp->next == NULL)
		ft_lidxdelone(tmp, del);
	else
	{
		while (tmp->next != NULL)
		{
			*lst = tmp;
			tmp = tmp->next;
			del((*lst)->txt);
			free(*lst);
			*lst = NULL;
			if (tmp->next == NULL)
			{
				ft_lidxdelone(tmp, del);
				return ;
			}
		}
	}
}

void	ft_lidxdelone(t_lidx *lst, void (*del)(void*))
{
	if (lst == NULL)
		return ;
	del(lst->txt);
	free(lst);
	lst = NULL;
}

t_lidx	*ft_lidxlast(t_lidx *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_lidx	*ft_lidxnew(void *txt, int info)
{
	t_lidx	*newlst;

	if (!(newlst = (t_lidx*)malloc(sizeof(t_lidx))))
		return (NULL);
	if (!(newlst->txt = ft_strdup(txt)))
	{
		free(newlst);
		return (NULL);
	}
	newlst->info = info;
	newlst->next = NULL;
	newlst->opts.flags = 0;
	newlst->opts.width = 0;
	newlst->opts.precision = 0;
	newlst->opts.length = 0;
	newlst->opts.spec = 0;
	return (newlst);
}
