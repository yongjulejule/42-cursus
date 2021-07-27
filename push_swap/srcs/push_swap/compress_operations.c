/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 18:57:28 by jun               #+#    #+#             */
/*   Updated: 2021/07/26 22:02:49 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	compress_rotation(t_stk **op)
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
			if ((cur->num == 6 && cur->next->num == 9)\
					|| (cur->num == 9 && cur->next->num == 6))
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

static t_deq	*r_to_rev_r(t_stk **op, t_deq *cur, t_deq *tmp, int cnt_r)
{
	int cnt_rr;

	tmp = cur->prev;
	cnt_rr = (*op)->ac - cnt_r;
	dllst_del_n_node(op, cur, cnt_r - cnt_rr);
	tmp = tmp->next;
	while (cnt_rr != 0)
	{
		tmp->num = 9;
		tmp = tmp->next;
		cnt_rr--;
	}
	return (tmp);
}

void	compress_r_revr(t_stk **op)
{
	t_deq	*cur;
	t_deq	*tmp;
	int		cnt_r;

	cur = (*op)->head->next;
	while (cur != (*op)->tail)
	{
		cnt_r = 0;
		tmp = cur;
		while (tmp->num == 6)
		{
			tmp = tmp->next;
			cnt_r++;
		}
		if (cnt_r > ((*op)->ac / 2) + 1)
			cur = r_to_rev_r(op, cur, tmp, cnt_r);
		cur = cur->next;
	}
}

void	compress_each_op(t_stk **op_a, t_stk **op_b)
{
	compress_rotation(op_a);
	compress_rotation(op_b);
	compress_r_revr(op_a);
	compress_r_revr(op_b);
	print_stack(*(op_a), *(op_b), NULL);
}
