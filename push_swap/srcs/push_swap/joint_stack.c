/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joint_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 08:39:49 by jun               #+#    #+#             */
/*   Updated: 2021/07/28 11:01:58 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	update_stack(t_stk **op_b)
{
	t_deq	*cur_b;

	cur_b = (*op_b)->head->next;
	while (cur_b != (*op_b)->tail)
	{
		cur_b->num += 1;
		cur_b = cur_b->next;
	}
}

void	joint_stack(t_stk **op, t_stk **op_a, t_stk **op_b)
{
	t_deq	*cur_a;
	t_deq	*cur_b;
	t_deq	*tmp;

	cur_a = (*op_a)->head->next;
	cur_b = (*op_b)->head->next;
	while (cur_a != (*op_a)->tail)
	{
		if (cur_a->num == cur_b->num)
		{
			cur_a->num += 2;
			tmp = cur_b->prev;
			dllst_delone(op_b, cur_b);
			cur_b = tmp->next;
		}
		if (cur_a != (*op_a)->tail)
			cur_a = cur_a->next;
	}
	update_stack(op_b);
	dllst_append(op_a, op_b);
	dllst_append(op, op_a);
}
