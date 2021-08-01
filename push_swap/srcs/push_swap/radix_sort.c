/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 19:51:38 by jun               #+#    #+#             */
/*   Updated: 2021/08/01 13:34:07 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_most_sigf_bit(int num)
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

int	pow_to_get_pivot(int nbr)
{
	int	tmp;

	tmp = 1;
	while (nbr > 0)
	{
		tmp *= 2;
		nbr--;
	}
	return (tmp);
}

void	radix_msd_sort(t_stk **a, t_stk **b, t_stk **op, int cnt)
{
	update_idx(a);
	(*op)->ac = cnt;
	(*op)->pivot = pow_to_get_pivot(cnt - 2);
	transf_based_bits(a, b, op);
}
