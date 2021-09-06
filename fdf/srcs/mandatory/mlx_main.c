/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:01:28 by jun               #+#    #+#             */
/*   Updated: 2021/09/06 12:13:23 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_fdf	*init_fdf_structure(t_data *data)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)ft_calloc(1, sizeof(t_fdf));
	fdf->data = data;
	fdf->prog = (t_program *)ft_calloc(1, sizeof(t_program));
	fdf->prog->mlx_ptr = mlx_init();
	if (!fdf->prog->mlx_ptr)
		is_error("Error while initiate mlx");
	fdf->prog->win_ptr = mlx_new_window(fdf->prog->mlx_ptr,
			WIN_W, WIN_H, "crazy_fdf");
	if (!fdf->prog->win_ptr)
		is_error("Error while initiate window");
	return (fdf);
}

static double	get_scale(t_data *data, double hori, double verdi)
{
	double	scale_w;
	double	scale_h;

	hori = verdi;
	scale_w = fabs(WIN_W
			/ ((data->max_x * cos(atan(0.5))) * 2));
	scale_h = fabs(WIN_H
			/ ((-data->max_z + (data->max_x + data->max_y) * sin(atan(0.5)))));
	if (scale_w > scale_h)
		return (scale_h);
	else
		return (scale_w);
}

static t_camera	*init_camera_structure(t_data *data)
{
	t_camera	*camera;

	camera = (t_camera *)ft_calloc(1, sizeof(t_camera));
	camera->horizon = WIN_W * 0.4;
	camera->vertical = WIN_H * 0.55;
	camera->scale = get_scale(data, camera->horizon, camera->vertical) / 2;
	camera->proj = ISO;
	return (camera);
}

static void	get_fdf_background(t_fdf *fdf)
{
	int	width;
	int	height;

	width = WIN_W;
	height = WIN_H;
	if (!fdf->background)
		fdf->background = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!fdf->background->img_ptr)
		fdf->background->img_ptr = mlx_png_file_to_image(fdf->prog->mlx_ptr,
				"./asset/cosmos.png", &width, &height);
	if (!fdf->background->img_ptr)
		is_error("Error while initiate image");
}

t_fdf	*mlx_main(t_data *data)
{
	t_fdf	*fdf;

	fdf = init_fdf_structure(data);
	fdf->camera = init_camera_structure(data);
	get_fdf_background(fdf);
	draw(fdf);
	hook_fdf(fdf);
	mlx_loop(fdf->prog->mlx_ptr);
	mlx_destroy_image(fdf->prog->mlx_ptr, fdf->background->img_ptr);
	fdf->background->img_ptr = NULL;
	return (fdf);
}
