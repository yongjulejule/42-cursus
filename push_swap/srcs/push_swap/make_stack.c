/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:46:54 by jun               #+#    #+#             */
/*   Updated: 2021/07/25 15:08:34 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	init_dll(t_stk **stk, int ac)
{
	t_stk	*cur;

	cur = *stk;
	cur->head = (t_deq *)ft_calloc_w_error(sizeof(t_deq), 1);
	cur->tail = (t_deq *)ft_calloc_w_error(sizeof(t_deq), 1);
	cur->tail->next = NULL;
	cur->tail->prev = cur->head;
	cur->head->prev = NULL;
	cur->head->next = cur->tail;
	cur->ac = ac;
}

void	make_stack(t_stk **a, t_stk **b, int *av_int, int ac)
{
	int	idx;

	idx = 0;
	*a = (t_stk *)ft_calloc_w_error(sizeof(t_stk), 1);
	init_dll(a, ac);
	if (b == NULL)
		return ;
	*b = (t_stk *)ft_calloc_w_error(sizeof(t_stk), 1);
	init_dll(b, ac);
	if (av_int == NULL)
		return ;
	while (idx < ac)
	{
		dllst_add_back(a, av_int[idx]);
		idx++;
	}
	indexing_args_by_bst(*a);
}
