/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_and_merge_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:05:22 by jun               #+#    #+#             */
/*   Updated: 2021/08/01 13:28:08 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	divide_data(t_stk **a, t_stk **b, t_stk **op)
{
	float	pivot;
	t_deq	*cur;
	int		idx;

	idx = 1;
	pivot = ((float)(*a)->ac / 100) * 51;
	while (idx < pivot + 0.5)
	{
		if (pivot < 2.5)
			break ;
		cur = (*a)->head->next;
		if (cur->idx < pivot + 0.5)
		{
			do_op(a, b, op, PB);
			idx++;
		}
		else
			do_op(a, b, op, RA);
	}
	(*b)->ac = idx - 1;
	(*op)->ac = (*a)->ac;
	compress_r_revr(op);
}

void	merge_stack(t_stk **a, t_stk **b, t_stk **op)
{
	t_deq	*cur;

	cur = (*b)->head->next;
	while (cur != (*b)->tail)
	{
		do_op(a, b, op, PA);
		cur = (*b)->head->next;
	}
}
