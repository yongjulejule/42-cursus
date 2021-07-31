/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_b_to_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 16:37:57 by jun               #+#    #+#             */
/*   Updated: 2021/07/31 17:34:31 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	transf_b_to_a_0(t_stk **a, t_stk **b, t_stk **op, int bit_shift)
{
	int	cnt;

	cnt = 0;
	if (!(((*b)->head->next->idx >> (bit_shift) & 1)))
	{
		do_op(a, b, op, PA);
		(*a)->ac++;
		if (!(((*a)->head->next->idx >> (bit_shift - 1)) & 1))
		{
			do_op(a, b, op, RA);
			cnt++;
		}
	}
	else
		do_op(a, b, op, RB);
	return (cnt);
}

int	transf_b_to_a_1(t_stk **a, t_stk **b, t_stk **op, int bit_shift)
{
	int	cnt;

	cnt = 0;
	if ((((*b)->head->next->idx >> (bit_shift) & 1)))
	{
		do_op(a, b, op, PA);
		(*a)->ac++;
		if (!(((*a)->head->next->idx >> (bit_shift - 1) & 1)))
		{
			do_op(a, b, op, RA);
			cnt++;
		}
	}
	else
		do_op(a, b, op, RB);
	return (cnt);
}


void	subprocess_b_to_a(t_stk **a, t_stk **b, t_stk **op, int shift)
{
	int		cnt;
	int		nbr;
	int		tmp;

	cnt = 0;
	nbr = 0;
	tmp = (*a)->ac;
	while (nbr < (*b)->pivot)
	{
		cnt += transf_b_to_a_1(a, b, op, (*op)->ac - shift);
		nbr++;
	}
	while (cnt > 0)
	{
		do_op(a, NULL, op, RRA);
		cnt--;
	}
	nbr = (*b)->pivot - (*a)->ac + tmp;
	while (cnt < nbr)
	{
		do_op(a, b, op, RRB);
		cnt++;
	}
	cnt = 0;
	nbr = (*a)->ac - tmp;
	while (nbr < (*b)->pivot)
	{
		cnt += transf_b_to_a_0(a, b, op, (*op)->ac - shift);
		nbr++;
	}
	while (cnt > 0)
	{
		do_op(a, NULL, op, RRA);
		cnt--;
	}
	(*b)->ac = (*b)->ac - nbr;
}
