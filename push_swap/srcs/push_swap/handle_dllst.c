/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dllst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:15:00 by jun               #+#    #+#             */
/*   Updated: 2021/07/26 19:35:24 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	dllst_delone(t_stk **stk, t_deq *del)
{
	t_deq	*cur;

	if (del == (*stk)->head || del == (*stk)->tail)
		return ;
	cur = del->prev;
	cur->next = del->next;
	cur->next->prev = cur;
	free(del);
}

void	dllst_del_n_node(t_stk **stk, t_deq *del, int nbr)
{
	t_deq	*cur;
	int		cnt;

	cnt = 0;
	cur = del->prev;
	while (cnt < nbr)
	{
		dllst_delone(stk, del);
		del = cur->next;
		cnt++;
	}
}

void	dllst_add_back(t_stk **stk, int num)
{
	t_deq	*newnode;

	newnode = (t_deq *)ft_calloc_w_error(sizeof(t_deq), 1);
	newnode->num = num;
	newnode->next = (*stk)->tail;
	newnode->prev = (*stk)->tail->prev;
	newnode->next->prev = newnode;
	newnode->prev->next = newnode;
}

void	dllst_add_front(t_stk **stk, int num)
{
	t_deq	*newnode;

	newnode = (t_deq *)ft_calloc_w_error(sizeof(t_deq), 1);
	newnode->num = num;
	newnode->next = (*stk)->head->next;
	newnode->next->prev = newnode;
	newnode->prev = (*stk)->head;
	newnode->prev->next = newnode;
}
