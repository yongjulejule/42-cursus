/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:01:28 by jun               #+#    #+#             */
/*   Updated: 2021/09/06 17:45:13 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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

static t_camera	*init_camera_structure(void)
{
	t_camera	*camera;

	camera = (t_camera *)ft_calloc(1, sizeof(t_camera));
	camera->scale = 10;
	camera->horizon = T_W;
	camera->vertical = T_H * 2;
	camera->mouse_l = RELEASED_L;
	camera->mouse_r = RELEASED_R;
	camera->proj = ISO;
	camera->angle.x = 0;
	camera->angle.y = 0;
	camera->angle.z = 0;
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

void	draw(t_fdf *fdf)
{
	if (fdf->camera->proj == ISO)
		fdf->proj_func = iso_proj;
	else
		fdf->proj_func = parallel;
	init_img_structure(fdf);
	draw_wireframe(fdf);
	mlx_put_image_to_window(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
		fdf->background->img_ptr, 0, 0);
	mlx_put_image_to_window(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
		fdf->img->img_ptr, 0, 0);
	description_fdf(fdf);
	mlx_destroy_image(fdf->prog->mlx_ptr, fdf->img->img_ptr);
	fdf->img->img_ptr = NULL;
}

t_fdf	*mlx_main(t_data *data)
{
	t_fdf	*fdf;

	fdf = init_fdf_structure(data);
	fdf->camera = init_camera_structure();
	get_fdf_background(fdf);
	draw(fdf);
	hook_fdf(fdf);
	mlx_loop(fdf->prog->mlx_ptr);
	mlx_destroy_image(fdf->prog->mlx_ptr, fdf->background->img_ptr);
	fdf->background->img_ptr = NULL;
	return (fdf);
}
