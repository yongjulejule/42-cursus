/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_based_bits.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 10:51:11 by jun               #+#    #+#             */
/*   Updated: 2021/08/01 13:12:48 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	transf_b_to_a(t_stk **a, t_stk **b, t_stk **op)
{
	static	int	shift = 3;

	(*b)->pivot = (*b)->ac % (*op)->pivot;
	subprocess_b_to_a(a, b, op, shift);
	(*b)->pivot = (*op)->pivot;
	while ((*b)->ac > 0)
		subprocess_b_to_a(a, b, op, shift);
	(*op)->pivot >>= 2;
	shift += 4;
}

static void	transf_a_to_b(t_stk **a, t_stk **b, t_stk **op)
{
	static	int	shift = 5;

	(*a)->pivot = (*op)->pivot;
	while ((*a)->ac > (*a)->pivot)
		subprocess_a_to_b(a, b, op, shift);
	(*a)->pivot = (*a)->ac;
	subprocess_a_to_b(a, b, op, shift);
	(*op)->pivot >>= 2;
	shift += 4;
}

static void	transf_b_to_a_last_bit(t_stk **a, t_stk **b, t_stk **op)
{
	while ((*b)->ac > 0)
	{
		if ((*b)->head->next->idx & 1)
		{
			do_op(a, b, op, PA);
			do_op(a, b, op, PA);
		}
		else
		{
			do_op(a, b, op, SB);
			do_op(a, b, op, PA);
			do_op(a, b, op, PA);
		}
		(*b)->ac -=2;
	}
}

void	transf_based_bits(t_stk **a, t_stk **b, t_stk **op)
{
	int cnt;

	init_transf(a, b, op);
	transf_b_to_a(a, b, op);
	cnt = (*op)->ac - 4;
	while (cnt > 0)
	{
		transf_a_to_b(a, b, op);
		cnt -= 2;
		if (cnt == 1 || cnt == -1)
			transf_b_to_a_last_bit(a, b, op);
		else
			transf_b_to_a(a, b, op);
		cnt -= 2;
	}
}
