/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:46:54 by jun               #+#    #+#             */
/*   Updated: 2021/07/24 16:57:36 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	init_cdll(t_deq **stack)
{
	t_deq	*c_stack;

	c_stack = *stack;
	c_stack->prev = NULL;
	c_stack->next = (t_deq *)ft_calloc_w_error(sizeof(t_deq), 1);
	c_stack->next->next = NULL;
	c_stack->next->prev = c_stack;
}

void	make_stack(t_deq **stack_a, t_deq **stack_b, int *av_int, int ac)
{
	int	idx;

	idx = 0;
	*stack_a = (t_deq *)ft_calloc_w_error(sizeof(t_deq), 1);
	*stack_b = (t_deq *)ft_calloc_w_error(sizeof(t_deq), 1);
	init_cdll(stack_a);
	init_cdll(stack_b);
	while (idx < ac)
	{
		cdlst_add_back(stack_a, av_int[idx]);
		idx++;
	}
}
