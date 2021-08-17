/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:35:58 by jun               #+#    #+#             */
/*   Updated: 2021/08/17 21:07:41 by jun              ###   ########.fr       */
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

	handle_error(argc);
	data = get_data(argv);
	mlx_main(data);
	return (0);
}
