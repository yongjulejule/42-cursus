/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 08:57:34 by jun               #+#    #+#             */
/*   Updated: 2021/08/01 13:14:12 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	bucket_sort_main(t_stk **a, t_stk **b, t_stk **op)
{
	divide_data(a, b, op);
	sort_each_stack(a, b, op);
	merge_stack(a, b, op);
	compress_push(op);
}

static void	radix_msd_sort_main(t_stk **a, t_stk **b, t_stk **op)
{
	int		cnt;

	(*b)->ac = 0;
	cnt = get_most_sigf_bit((*a)->ac - 1);
	radix_msd_sort(a, b, op, cnt);
	compress_rotation_radix(op);
	compress_dual_rotation(op);
	compress_push(op);
}

static int	push_swap_main(int *av_int, int ac)
{
	t_stk	*a;
	t_stk	*b;
	t_stk	*op;

	make_stack(&a, &b, av_int, ac);
	make_stack(&op, NULL, NULL, ac);
	if (ac < 10)
		bucket_sort_main(&a, &b, &op);
	else
		radix_msd_sort_main(&a, &b, &op);
	print_result(&op);
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
