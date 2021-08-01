/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 09:46:08 by jun               #+#    #+#             */
/*   Updated: 2021/08/01 14:32:58 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_matched_operation(int op_idx)
{
	if (op_idx == PA)
		ft_putendl_fd("pa", 1);
	else if (op_idx == PB)
		ft_putendl_fd("pb", 1);
	else if (op_idx == SA)
		ft_putendl_fd("sa", 1);
	else if (op_idx == SB)
		ft_putendl_fd("sb", 1);
	else if (op_idx == SS)
		ft_putendl_fd("ss", 1);
	else if (op_idx == RA)
		ft_putendl_fd("ra", 1);
	else if (op_idx == RB)
		ft_putendl_fd("rb", 1);
	else if (op_idx == RR)
		ft_putendl_fd("rr", 1);
	else if (op_idx == RRA)
		ft_putendl_fd("rra", 1);
	else if (op_idx == RRB)
		ft_putendl_fd("rrb", 1);
	else if (op_idx == RRR)
		ft_putendl_fd("rrr", 1);
}

void	print_result(t_stk *op)
{
	t_deq	*cur;

	cur = op->head->next;
	while (cur != (op)->tail)
	{
		print_matched_operation(cur->num);
		cur = cur->next;
	}
}
