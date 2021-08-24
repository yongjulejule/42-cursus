/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:35:58 by jun               #+#    #+#             */
/*   Updated: 2021/08/24 11:36:21 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	handle_error(int argc, char **argv)
{
	char	*expension;

	if (argc != 2)
		is_error("Check The number of Arguments");
	expension = ft_strrchr(argv[1], '.');
	if (expension == NULL)
		is_error("File should end with .fdf");
	if (ft_strcmp(expension, ".fdf"))
		is_error("File should end with .fdf");
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_fdf	*fdf;

	handle_error(argc, argv);
	data = get_data(argv);
	fdf = mlx_main(data);
	return (0);
}
