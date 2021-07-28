/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 18:57:28 by jun               #+#    #+#             */
/*   Updated: 2021/07/28 13:46:59 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	compress_push(t_stk **op)
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
			if ((cur->num == 1 && cur->next->num == 2)\
					|| (cur->num == 2 && cur->next->num == 1))
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
	if (cnt_r == (*op)->ac)
		cnt_rr = 0;
	else
		cnt_rr = (*op)->ac - cnt_r;
	dllst_del_n_node(op, cur, cnt_r - cnt_rr);
	tmp = tmp->next;
	while (cnt_rr > 0 && tmp != (*op)->tail)
	{
		tmp->num = 9;
		tmp = tmp->next;
		cnt_rr--;
	}
	return (tmp->prev);
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
		while (tmp->num == 6 && cnt_r < (*op)->ac)
		{
			cnt_r++;
			tmp = tmp->next;
		}
		if (cnt_r >= ((float)(*op)->ac / 2))
			cur = r_to_rev_r(op, cur, tmp, cnt_r);
		if (cur == (*op)->tail)
			break ;
		cur = cur->next;
	}
}

void	compress_each_op(t_stk **op_a, t_stk **op_b)
{
	compress_rotation(op_a);
	compress_rotation(op_b);
	compress_r_revr(op_a);
	compress_r_revr(op_b);
}
