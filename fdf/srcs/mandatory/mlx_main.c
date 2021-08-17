/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:01:28 by jun               #+#    #+#             */
/*   Updated: 2021/08/17 22:38:38 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static t_fdf	*init_fdf_structure(t_data *data)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)ft_calloc(1, sizeof(t_fdf));
	fdf->data = data;
	fdf->prog = (t_program *)ft_calloc(1, sizeof(t_program));
	fdf->prog->mlx_ptr = (int *)ft_calloc(1, sizeof(int));
	fdf->prog->win_ptr = (int *)ft_calloc(1, sizeof(int));
	fdf->prog->mlx_ptr = mlx_init();
	if (!fdf->prog->mlx_ptr)
		is_error("Error while initiating mlx");
	fdf->prog->win_ptr = mlx_new_window(fdf->prog->mlx_ptr,\
			fdf->data->max_x * 50, fdf->data->max_y * 50, "crazy_fdf");
	/* TODO : need to put mlx_image */
	if (!fdf->prog->win_ptr)
		is_error("Error while open window");
	return (fdf);
}

void	mlx_main(t_data *data)
{
	t_fdf	*fdf;

	fdf = init_fdf_structure(data);
	draw_wireframe(fdf);
	mlx_loop(fdf->prog->mlx_ptr);
}
