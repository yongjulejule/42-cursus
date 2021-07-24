/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 08:57:34 by jun               #+#    #+#             */
/*   Updated: 2021/07/24 16:07:12 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


static int	push_swap_main(int *av_int, int ac)
{
	t_deq	*stack_a;
	t_deq	*stack_b;
//	t_ops	*op;

	make_stack(&stack_a, &stack_b, av_int, ac);
//	sorting();
//	compress_op();
//	print_result();
	return ac;
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
