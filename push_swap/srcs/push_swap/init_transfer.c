/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_transfer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 17:34:18 by jun               #+#    #+#             */
/*   Updated: 2021/08/01 13:26:18 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	init_transf_a_to_b_0(t_stk **a, t_stk **b, t_stk **op, int shift)
{
	int	cnt;

	cnt = 0;
	if (!(((*a)->head->next->idx >> (shift) & 1)))
	{
		do_op(a, b, op, PB);
		(*b)->ac++;
		if (!(((*b)->head->next->idx >> (shift - 1)) & 1))
		{
			do_op(NULL, b, op, RB);
			cnt++;
		}
	}
	else
		do_op(a, NULL, op, RA);
	return (cnt);
}

static int	init_transf_a_to_b_1(t_stk **a, t_stk **b, t_stk **op, int shift)
{
	int	cnt;

	cnt = 0;
	if ((((*a)->head->next->idx >> (shift) & 1)))
	{
		do_op(a, b, op, PB);
		(*b)->ac++;
		if ((((*b)->head->next->idx >> (shift - 1) & 1)))
		{
			do_op(NULL, b, op, RB);
			cnt++;
		}
	}
	else
		do_op(a, NULL, op, RA);
	return (cnt);
}

void	init_transf(t_stk **a, t_stk **b, t_stk **op)
{
	int		cnt;
	int		nbr;

	cnt = 0;
	nbr = 0;
	while (nbr < (*a)->ac)
	{
		init_transf_a_to_b_0(a, b, op, (*op)->ac - 1);
		nbr++;
	}
	nbr = (*b)->ac;
	while (nbr < (*a)->ac)
	{
		cnt += init_transf_a_to_b_1(a, b, op, (*op)->ac - 1);
		nbr++;
	}
	while (cnt > 0)
	{
		do_op(NULL, b, op, RRB);
		cnt--;
	}
	(*a)->ac = (*a)->ac - (*b)->ac;
}
