/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_based_bits.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 10:51:11 by jun               #+#    #+#             */
/*   Updated: 2021/07/30 17:20:10 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	transf_a_to_b_0(t_stk **a, t_stk **b, t_stk **op_a, t_stk **op_b)
{
	int	cnt;
	int	bit_shift;

	bit_shift = (*op_a)->ac;
	cnt = 0;
	if (!(((*a)->head->next->idx >> bit_shift) & 1))
	{
		do_op(a, b, op_a, PB);
		(*b)->ac++;
		if (!(((*b)->head->next->idx >> (bit_shift - 1)) & 1))
		{
			do_op(NULL, b, op_a, RB);
			cnt++;
		}
	}
	else
		do_op(a, NULL, op_a, RA);
	return (cnt);
}

int	transf_a_to_b_1(t_stk **a, t_stk **b, t_stk **op_a, t_stk **op_b)
{
	int	cnt;
	int	bit_shift;

	bit_shift = (*op_a)->ac;
	cnt = 0;
	if ((((*a)->head->next->idx >> bit_shift) & 1))
	{
		do_op(a, b, op_a, PB);
		(*b)->ac++;
		if ((((*b)->head->next->idx >> (bit_shift - 1)) & 1))
		{
			do_op(NULL, b, op_a, RB);
			cnt++;
		}
	}
	else
		do_op(a, NULL, op_a, RA);
	return (cnt);
}

static void init_transf(t_stk **a, t_stk **b, t_stk **op_a, t_stk **op_b)
{
	int		bit_shift;
	int		cnt;
	int		nbr;

	bit_shift = (*op_a)->ac;
	(*op_a)->ac = bit_shift - 1;
	while ((*op_a)->ac > 5)
	{
		cnt = 0;
		nbr = (*b)->ac;
		while (nbr < (*a)->ac)
		{
			cnt += transf_a_to_b_0(a, b, op_a, op_b);
			nbr++;
		}
//		while (cnt > 0)
//		{
//			do_op(NULL, b, op_a, RRB);
//			cnt--;
//		}
		nbr = (*b)->ac;
		while (nbr < (*a)->ac)
		{
			cnt += transf_a_to_b_1(a, b, op_a, op_b);
			nbr++;
		}
//		while (cnt > 0)
//		{
//			do_op(NULL, b, op_a, RRB);
//			cnt--;
//		}
		(*op_a)->ac--;
	}
	(*a)->ac =(*a)->ac - (*b)->ac;
	print_stack(*a, *b, NULL);

	while ((*op_a)->ac > 3)
	{
		cnt = 0;
		nbr = (*a)->ac;
		while (nbr < (*b)->ac)
		{
			cnt += transf_a_to_b_0(b, a, op_a, op_b);
			nbr++;
		}
//		while (cnt > 0)
//		{
//			do_op(NULL, a, op_a, RRB);
//			cnt--;
//		}
		nbr = (*a)->ac;
		while (nbr < (*b)->ac)
		{
			cnt += transf_a_to_b_1(b, a, op_a, op_b);
			nbr++;
		}
//		while (cnt > 0)
//		{
//			do_op(NULL, a, op_a, RRB);
//			cnt--;
//		}
		(*op_a)->ac--;
	}
	(*b)->ac =(*b)->ac - (*a)->ac;
	print_stack(*a, *b, NULL);

	while ((*op_a)->ac > 1)
	{
		cnt = 0;
		nbr = (*b)->ac;
		while (nbr < (*a)->ac)
		{
			cnt += transf_a_to_b_0(a, b, op_a, op_b);
			nbr++;
		}
//		while (cnt > 0)
//		{
//			do_op(NULL, b, op_a, RRB);
//			cnt--;
//		}
		nbr = (*b)->ac;
		while (nbr < (*a)->ac)
		{
			cnt += transf_a_to_b_1(a, b, op_a, op_b);
			nbr++;
		}
//		while (cnt > 0)
//		{
//			do_op(NULL, b, op_a, RRB);
//			cnt--;
//		}
		(*op_a)->ac--;
	}
	(*a)->ac =(*a)->ac - (*b)->ac;
	print_stack(*a, *b, NULL);

	while ((*op_a)->ac > 0)
	{
		cnt = 0;
		nbr = (*a)->ac;
		while (nbr < (*b)->ac)
		{
			cnt += transf_a_to_b_0(b, a, op_a, op_b);
			nbr++;
		}
//		while (cnt > 0)
//		{
//			do_op(NULL, a, op_a, RRB);
//			cnt--;
//		}
		nbr = (*a)->ac;
		while (nbr < (*b)->ac)
		{
			cnt += transf_a_to_b_1(b, a, op_a, op_b);
			nbr++;
		}
//		while (cnt > 0)
//		{
//			do_op(NULL, a, op_a, RRB);
//			cnt--;
//		}
		(*op_a)->ac--;
	}
	(*b)->ac =(*b)->ac - (*a)->ac;
	print_stack(*a, *b, NULL);
	(*op_a)->ac = bit_shift;
	print_stack(*op_a, *op_b, NULL);
}

static void	transf_b_to_a(t_stk **a, t_stk **b, t_stk **op_a, t_stk **op_b)
{
}

void	transf_based_bits(t_stk **a, t_stk **b, t_stk **op_a, t_stk **op_b)
{
	int cnt;

	init_transf(a, b, op_a, op_b);
	//	cnt = (*op_b)->ac / 2;
	//	while (cnt > 0)
	//	{
	//		transf_a_to_b_0(a, b, op_a, op_b);
	//		transf_b_to_a(a, b, op_a, op_b);
	//		cnt--;
	//	}
}
