/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:35:58 by jun               #+#    #+#             */
/*   Updated: 2021/08/21 14:50:35 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	handle_error(int argc)
{
	if (argc != 2)
		is_error("Check The number of Arguments");
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_fdf	*fdf;

	handle_error(argc);
	data = get_data(argv);
	fdf = mlx_main(data);
	return (0);
}
