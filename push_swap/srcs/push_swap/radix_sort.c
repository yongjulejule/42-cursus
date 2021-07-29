/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 19:51:38 by jun               #+#    #+#             */
/*   Updated: 2021/07/29 20:09:46 by jun              ###   ########.fr       */
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

	cnt = 0;
	while ((num >> cnt) != 0)
		cnt++;
	return (cnt);
}

void	transf_based_bits(t_stk **a, t_stk **b, t_stk **op, int cnt)
{

}
