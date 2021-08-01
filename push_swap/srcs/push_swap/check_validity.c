/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 14:08:08 by jun               #+#    #+#             */
/*   Updated: 2021/08/01 13:25:10 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	check_dup(int *av_int, int ac)
{
	int	tmp;
	int	num_idx;
	int	search;

	num_idx = 0;
	while (num_idx < ac)
	{
		tmp = av_int[num_idx];
		search = num_idx;
		while (search < ac)
		{
			if (tmp == av_int[search])
			{
				if (search != num_idx)
					is_error("Error : Have duplicated number");
			}
			search++;
		}
		num_idx++;
	}
}

static void	check_ordered(int *av_int, int ac)
{
	int	idx;
	int	tmp;
	int	search;

	idx = 0;
	while (idx < ac)
	{
		tmp = av_int[idx];
		search = idx + 1;
		while (search < ac)
		{
			if (tmp > av_int[search])
				return ;
			search++;
		}
		idx++;
	}
	exit(EXIT_SUCCESS);
}

void	check_validity(int *av_int, int ac)
{
	check_dup(av_int, ac);
	check_ordered(av_int, ac);
}
