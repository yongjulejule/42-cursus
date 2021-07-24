/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c_d_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:15:00 by jun               #+#    #+#             */
/*   Updated: 2021/07/24 16:54:10 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	cdlst_add_back(t_deq **stack, int num)
{
	t_deq	*tail;
	t_deq	*head;
	t_deq	*newnode;

	head = *stack;
	tail = *stack;
	newnode = (t_deq *)ft_calloc_w_error(sizeof(t_deq), 1);
	newnode->num = num;
	while (tail->next == NULL)
		tail = tail->next;
	newnode->next = head->next;
	newnode->prev = tail->prev;
	newnode->next->prev = newnode;
	newnode->prev->next = newnode;
}
//
//void	cdlst_add_front(t_deq **stack, int num)
//{
//}
