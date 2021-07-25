/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 08:57:34 by jun               #+#    #+#             */
/*   Updated: 2021/07/25 16:25:46 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

#include <stdio.h>
void	print_stack(t_stk *a, t_stk *b)
{
	int idx;
	t_deq *tmp;

	idx = 0;
	tmp = a->head->next;
	while (tmp != a->tail)
	{
		printf("%d th node, data is %d\n", idx, tmp->num);
		tmp = tmp->next;
		idx++;
	}
	while (tmp != a->head)
	{
		printf("%d th node, data is %d\n", idx, tmp->num);
		tmp = tmp->prev;
		idx--;
	}
}

static int	push_swap_main(int *av_int, int ac)
{
	t_stk	*a;
	t_stk	*b;
	t_stk	*op;

	make_stack(&a, &b, av_int, ac);
	make_stack(&op, NULL, NULL, ac);
//	do_op(&a, &b, &op, PA);
	print_stack(a, b);
	do_op(&a, &b, &op, SA);
	print_stack(a, b);
	do_op(&a, &b, &op, RA);
	print_stack(a, b);
	do_op(&a, &b, &op, RRA);
	print_stack(a, b);
//	divide_data(&a, &b, &op);
//	sorting();
//	compress_op();
//	print_result();
	return (0);
}

int	main(int argc, char **argv)
{
	int *av_int;
	int	ac;

	if (argc < 2)
		is_error("Error : Check the number of arguments");
	av_int = parse_args(argc, argv, &ac);
	check_validity(av_int, ac);
	push_swap_main(av_int, ac);
}
