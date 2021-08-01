/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:41:25 by jun               #+#    #+#             */
/*   Updated: 2021/08/01 13:19:49 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	move_spec_nbr_left(t_stk **stk, t_deq *cur, int start, t_stk **op)
{
	int	cnt;

	while (cur->idx != start)
	{
		cnt = 0;
		while (cur->next->idx != start)
		{
			do_op(stk, NULL, op, RA);
			cur = (*stk)->head->next;
			cnt++;
		}
		do_op(stk, NULL, op, SA);
		cur = (*stk)->head->next;
		while (cnt != 0)
		{
			do_op(stk, NULL, op, RRA);
			cur = (*stk)->head->next;
			cnt--;
		}
		if (cur == (*stk)->tail)
			return ;
	}
}

void	insertion_sort(t_stk **stk, t_stk **op, int start, int last)
{
	t_deq	*cur;

	cur = (*stk)->head->next;
	while (cur->idx != start)
	{
		do_op(stk, NULL, op, RA);
		cur = (*stk)->head->next;
	}
	while (1)
	{
		do_op(stk, NULL, op, RA);
		cur = (*stk)->head->next;
		if (start > last)
			start--;
		else if (start < last)
			start++;
		else
			break ;
		move_spec_nbr_left(stk, cur, start, op);
	}
}

void	sort_each_stack(t_stk **a, t_stk **b, t_stk **op)
{
	t_stk	*op_a;
	t_stk	*op_b;

	make_stack(&op_a, &op_b, NULL, 0);
	op_a->ac = (*a)->ac - (*b)->ac;
	op_b->ac = (*b)->ac;
	insertion_sort(a, &op_a, (*b)->ac + 1, (*a)->ac);
	if ((*b)->ac != 0)
		insertion_sort(b, &op_b, (*b)->ac, 1);
	compress_each_op(&op_a, &op_b);
	joint_stack(op, &op_a, &op_b);
}
