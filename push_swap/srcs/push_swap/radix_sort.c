/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 19:51:38 by jun               #+#    #+#             */
/*   Updated: 2021/07/30 15:43:31 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
*1 1 1 0 1
*1 1 1 0 0
*1 1 0 1
*1 1 0 0
*1 0 1
*1 0 0
*0 1
*0 0
*stack_b
*work like this way!
*/

int		get_most_sigf_bit(int num)
{
	int	cnt;

	if (num == 0)
		return (1);
	cnt = 0;
	while ((num >> cnt) != 0)
		cnt++;
	return (cnt);
}

void	update_idx(t_stk **a)
{
	t_deq	*cur;

	cur = (*a)->head->next;
	while (cur != (*a)->tail)
	{
		cur->idx--;
		cur = cur->next;
	}
}

void	radix_msd_sort(t_stk **a, t_stk **b, t_stk **op, int cnt)
{
	t_stk	*op_a;
	t_stk	*op_b;

	update_idx(a);
	make_stack(&op_a, &op_b, NULL, 0);
	op_a->ac = cnt;
	op_b->ac = cnt;
	transf_based_bits(a, b, &op_a, &op_b);
}
