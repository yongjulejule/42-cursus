/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:01:28 by jun               #+#    #+#             */
/*   Updated: 2021/08/20 01:04:59 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"


static t_fdf	*init_fdf_structure(t_data *data)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)ft_calloc(1, sizeof(t_fdf));
	fdf->data = data;
	fdf->prog = (t_program *)ft_calloc(1, sizeof(t_program));
	fdf->prog->mlx_ptr = mlx_init();
	if (!fdf->prog->mlx_ptr)
		is_error("Error while initiate mlx");
	fdf->prog->win_ptr = mlx_new_window(fdf->prog->mlx_ptr,\
			WIN_W, WIN_H, "crazy_fdf");
	if (!fdf->prog->win_ptr)
		is_error("Error while initiate window");
	return (fdf);
}

static t_carema	*init_carema_structure(t_fdf *fdf)
{
	t_carema	*carema;

	carema = (t_carema *)ft_calloc(1, sizeof(t_carema));
	carema->h_angle = 0;
	carema->v_angle = 0;
	carema->scale = 20;
	carema->horizon = carema->scale * fdf->data->max_x * cos(atan(0.5));
	carema->vertical = 200;
	carema->mouse = RELEASED;
	carema->proj = ISO;
	return (carema);
}

static void	translate_fdf(t_fdf *fdf)
{
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
			10, 20, 0xffffff, "Welcome to FDF");
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
			10, 40, 0xffffff, "Press A/D to move horizontaly");
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
			10, 60, 0xffffff, "Press W/S to move vertically");
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
			10, 80, 0xffffff, "Press Arrow key to rotate");
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
			10, 100, 0xffffff, "Press ESC to exit");
}
#include <stdio.h>
void	draw(t_fdf *fdf)
{
	fprintf(stderr, "draw: vert : %dhori :%d\n", fdf->carema->vertical, fdf->carema->horizon);
	draw_wireframe(fdf);
	mlx_put_image_to_window(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
			fdf->img->img_ptr, 0, 0);
	translate_fdf(fdf);
//	mlx_destroy_image(fdf->prog->mlx_ptr, fdf->img->img_ptr);
}

t_fdf	*mlx_main(t_data *data)
{
	t_fdf	*fdf;

	fdf = init_fdf_structure(data);
	fdf->carema = init_carema_structure(fdf);
	draw(fdf);
	return (fdf);
}
