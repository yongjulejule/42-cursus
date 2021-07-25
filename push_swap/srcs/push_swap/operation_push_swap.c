/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push_swap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:32:07 by jun               #+#    #+#             */
/*   Updated: 2021/07/25 16:12:53 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_stack(t_stk **stk)
{
	t_deq	*root;
	t_deq	*head;

	head = (*stk)->head;
	root = head->next;
	head->next = root->next;
	root->next = root->next->next;
	head->next->next = root;
	head->next->prev = head;
	root->prev = head->next;
	root->next->prev = root;
}

void	push_stack(t_stk **src, t_stk **dst)
{
	t_deq	*src_head;
	t_deq	*dst_head;
	t_deq	*src_root;
	t_deq	*dst_root;

	src_head = (*src)->head;
	dst_head = (*dst)->head;
	src_root = src_head->next;
	dst_root = dst_head->next;
	src_root->prev = dst_head;
	dst_root->prev = src_head;
	src_root->next = dst_root->next;
	dst_root->next = src_root->next;
	src_head->next->next->prev = dst_root;
	dst_head->next->next->prev = src_root;
	src_head->next = dst_root;
	dst_head->next = src_root;
}

void	rotate_stack(t_stk **stk)
{
	t_deq	*root;
	t_deq	*foot;
	t_deq	*head;
	t_deq	*tail;

	head = (*stk)->head;
	tail = (*stk)->tail;
	root = head->next;
	foot = tail->prev;
	head->next = root->next;
	root->next->prev = head;
	root->next = tail;
	root->next->prev = tail->prev;
	foot->next = root;
	root->prev = foot;
}

void	rev_rotate_stack(t_stk **stk)
{
	t_deq	*root;
	t_deq	*foot;
	t_deq	*head;
	t_deq	*tail;

	head = (*stk)->head;
	tail = (*stk)->tail;
	root = head->next;
	foot = tail->prev;
	head->next = foot;
	foot->next = root;
	root->prev = foot;
	tail->prev = foot->prev;
	tail->prev->next = tail;
	foot->prev = head;
}

void	do_op(t_stk **a, t_stk **b, t_stk **op, int op_idx)
{
	dllst_add_back(op, op_idx);
	if (op_idx == PA)
		push_stack(a, b);
	else if (op_idx == PB)
		push_stack(b, a);
	else if (op_idx == SA)
		swap_stack(a);
	else if (op_idx == SB)
		swap_stack(b);
	else if (op_idx == RA)
		rotate_stack(a);
	else if (op_idx == RB)
		rotate_stack(b);
	else if (op_idx == RRA)
		rev_rotate_stack(a);
	else if (op_idx == RRB)
		rev_rotate_stack(a);
}
