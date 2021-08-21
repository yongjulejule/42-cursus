/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:01:28 by jun               #+#    #+#             */
/*   Updated: 2021/08/21 15:58:11 by jun              ###   ########.fr       */
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

static t_camera	*init_camera_structure(void)
{
	t_camera	*camera;

	camera = (t_camera *)ft_calloc(1, sizeof(t_camera));
	camera->h_angle = 0;
	camera->v_angle = 0;
	camera->scale = 2;
	camera->horizon = T_W;
	camera->vertical = T_H * 2;
	camera->mouse_l = RELEASED_L;
	camera->mouse_r = RELEASED_R;
	camera->proj = ISO;
	camera->angle.x = 0;
	camera->angle.y = 0;
	camera->angle.z = 0;
	camera->center.x = 0;
	camera->center.y = 0;
	camera->center.z = 0;
	return (camera);
}

static void	translate_fdf(t_fdf *fdf)
{
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
			10, 20, 0xffffff, "Welcome to FDF!");
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
			10, 40, 0xffffff, "if cur_projection == ISO {");
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
			10, 60, 0xffffff, "    Press Arrow key to move");
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
			10, 80, 0xffffff, "    Press A/S/D to rotate");
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
			10, 100, 0xffffff, "    Use Z/X/C to rotate inversely");
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
			10, 120, 0xffffff, "    Press MOUSE_L to rotate_crazy");
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
			10, 140, 0xffffff, "    Press MOUSE_R to inverse_rotate_crazy");
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
			10, 160, 0xffffff, "}");
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
			10, 180, 0xffffff, "Press ESC to exit");
}

#include <stdio.h>
void	draw(t_fdf *fdf)
{
	fprintf(stderr, "scale : %f, v_angle : %f, h_angle : %f ,vert : %dhori :%d\n", fdf->camera->scale, fdf->camera->v_angle, fdf->camera->h_angle, fdf->camera->vertical, fdf->camera->horizon);
//	fdf->camera->center = get_center(fdf);
	if (fdf->camera->proj == ISO)
		fdf->proj_func = iso_proj;
	else if (fdf->camera->proj == PALL)
		fdf->proj_func = parallel;
	else
		fdf->proj_func = one_perspective_proj;
	draw_wireframe(fdf);
	mlx_put_image_to_window(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
			fdf->img->img_ptr, 0, 0);
	translate_fdf(fdf);
}

t_fdf	*mlx_main(t_data *data)
{
	t_fdf	*fdf;

	fdf = init_fdf_structure(data);
	fdf->camera = init_camera_structure();
	draw(fdf);
	hook_fdf(fdf);
	mlx_loop(fdf->prog->mlx_ptr);
	return (fdf);
}
