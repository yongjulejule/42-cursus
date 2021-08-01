/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_a_to_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 17:36:15 by jun               #+#    #+#             */
/*   Updated: 2021/08/01 14:05:54 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	transf_a_to_b_0(t_stk **a, t_stk **b, t_stk **op, int bit_shift)
{
	int	cnt;

	cnt = 0;
	if (!(((*a)->head->next->idx >> (bit_shift) & 1)))
	{
		do_op(a, b, op, PB);
		(*b)->ac++;
		if ((((*b)->head->next->idx >> (bit_shift - 1)) & 1))
		{
			do_op(NULL, b, op, RB);
			cnt++;
		}
	}
	else
		do_op(a, NULL, op, RA);
	return (cnt);
}

static int	transf_a_to_b_1(t_stk **a, t_stk **b, t_stk **op, int bit_shift)
{
	int	cnt;

	cnt = 0;
	if ((((*a)->head->next->idx >> (bit_shift) & 1)))
	{
		do_op(a, b, op, PB);
		(*b)->ac++;
		if ((((*b)->head->next->idx >> (bit_shift - 1) & 1)))
		{
			do_op(NULL, b, op, RB);
			cnt++;
		}
	}
	else
		do_op(a, NULL, op, RA);
	return (cnt);
}

static void	preserv_transf_a_to_b_0(t_stk **a, t_stk **b, t_stk **op, int shift)
{
	int		cnt;
	int		nbr;
	int		tmp;

	cnt = 0;
	nbr = 0;
	tmp = (*b)->ac;
	while (nbr < (*a)->pivot)
	{
		cnt += transf_a_to_b_0(a, b, op, (*op)->ac - shift);
		nbr++;
	}		
	while (cnt > 0)
	{
		do_op(NULL, b, op, RRB);
		cnt--;
	}
	nbr = (*a)->pivot - (*b)->ac + tmp;
	while (cnt < nbr)
	{
		do_op(a, NULL, op, RRA);
		cnt++;
	}
}

void	subprocess_a_to_b(t_stk **a, t_stk **b, t_stk **op, int shift)
{
	int		cnt;
	int		nbr;
	int		tmp;

	cnt = 0;
	tmp = (*b)->ac;
	preserv_transf_a_to_b_0(a, b, op, shift);
	nbr = (*b)->ac - tmp;
	while (nbr < (*a)->pivot)
	{
		cnt += transf_a_to_b_1(a, b, op, (*op)->ac - shift);
		nbr++;
	}
	while (cnt > 0)
	{
		do_op(NULL, b, op, RRB);
		cnt--;
	}
	(*a)->ac = (*a)->ac - nbr;
}
