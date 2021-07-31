/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_based_bits.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 10:51:11 by jun               #+#    #+#             */
/*   Updated: 2021/07/31 18:20:00 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"



#include <stdio.h>

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

	printf("==== pivot is %d====\n", (*a)->pivot);
	while ((*a)->ac > (*a)->pivot)
	{
		printf("==== ac is %d====\n", (*a)->ac);
		subprocess_a_to_b(a, b, op, shift);
		print_stack(*a, *b, NULL, "a_to_b");
	}
	(*op)->pivot >>= 2;
	shift += 4;
}

void	transf_based_bits(t_stk **a, t_stk **b, t_stk **op)
{
	int cnt;

	init_transf(a, b, op);
	print_stack(*a, *b, NULL, "swap!!");
	ft_putnbr_fd((*op)->pivot, 1);
	transf_b_to_a(a, b, op);
	print_stack(*a, *b, NULL, "b_to_a");
	transf_a_to_b(a, b, op);
	print_stack(*a, *b, NULL, "a_to_b");
//	cnt = (*op)->ac / 4;
//	while (cnt > 0)
//	{
//		transf_b_to_a(a, b, op);
//		transf_a_to_b(a, b, op);
//		cnt--;
//	}
}
