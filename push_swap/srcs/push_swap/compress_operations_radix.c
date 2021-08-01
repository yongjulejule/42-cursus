/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_operations_radix.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 10:06:24 by jun               #+#    #+#             */
/*   Updated: 2021/08/01 13:15:51 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	compress_rotation_radix(t_stk **op)
{
	t_deq	*cur;
	t_deq	*tmp;
	int		flag;

	while (1)
	{
		flag = 0;
		cur = (*op)->head->next;
		while (cur != (*op)->tail)
		{
			if ((cur->num == RA && cur->next->num == RRA)\
					|| (cur->num == RRA && cur->next->num == RA)\
					|| (cur->num == RB && cur->next->num == RRB)\
					|| (cur->num == RRB && cur->next->num == RB))
			{
				tmp = cur;
				cur = cur->prev;
				flag = 1;
				dllst_del_n_node(op, tmp, 2);
			}
			cur = cur->next;
		}
		if (flag == 0)
			break;
	}
}

static	t_deq*	dual_rotation(t_stk **op, t_deq *cur, int op_1, int op_2)
{
	t_deq	*tmp;

	tmp = cur;
	cur = cur->next;
	while (cur->num == op_1 || cur->num == RR)
		cur = cur->next;
	if (cur->num == op_2)
	{
		dllst_delone(op, cur);
		cur = tmp;
		cur->num = RR;
	}
	return (tmp);
}

static	t_deq*	dual_rev_rotation(t_stk **op, t_deq *cur, int op_1, int op_2)
{
	t_deq	*tmp;

	tmp = cur;
	cur = cur->next;
	while (cur->num == op_1 || cur->num == RRR)
		cur = cur->next;
	if (cur->num == op_2)
	{
		dllst_delone(op, cur);
		cur = tmp;
		cur->num = RRR;
	}
	return (tmp);
}

void	compress_dual_rotation(t_stk **op)
{
	t_deq	*cur;

	cur = (*op)->head->next;
	while (cur->next != (*op)->tail)
	{
		if (cur->num == RA)
			cur = dual_rotation(op, cur, RA, RB);
		else if (cur->num == RB)
			cur = dual_rotation(op, cur, RB, RA);
		else if (cur->num == RRA)
			cur = dual_rev_rotation(op, cur, RRA, RRB);
		else if (cur->num == RRB)
			cur = dual_rev_rotation(op, cur, RRB, RRA);
		cur = cur->next;
	}
}
