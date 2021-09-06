/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wireframe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:39:12 by jun               #+#    #+#             */
/*   Updated: 2021/09/06 11:26:58 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vec	get_coordi(t_fdf *fdf, int x, int y)
{
	t_vec	vec;

	vec.x = x;
	vec.y = y;
	vec.z = fdf->data->data[0][y][x];
	return (vec);
}

static void	draw_wireframe_sub(t_fdf *fdf)
{
	t_vec	vec_0;
	t_vec	vec_1;

	vec_0 = fdf->proj_func(fdf, get_coordi(fdf, fdf->data->x, fdf->data->y));
	if (fdf->data->x != fdf->data->max_x - 1)
	{
		vec_1 = fdf->proj_func(fdf,
				get_coordi(fdf, fdf->data->x + 1, fdf->data->y));
		fdf->color[0] = fdf->data->data[1][fdf->data->y][fdf->data->x];
		fdf->color[1] = fdf->data->data[1][fdf->data->y][fdf->data->x + 1];
		drawline(fdf, vec_0, vec_1);
	}
	if (fdf->data->y != fdf->data->max_y - 1)
	{
		vec_1 = fdf->proj_func(fdf,
				get_coordi(fdf, fdf->data->x, fdf->data->y + 1));
		fdf->color[0] = fdf->data->data[1][fdf->data->y][fdf->data->x];
		fdf->color[1] = fdf->data->data[1][fdf->data->y + 1][fdf->data->x];
		drawline(fdf, vec_0, vec_1);
	}
}

void	draw(t_fdf *fdf)
{
	fdf->proj_func = iso_proj;
	draw_wireframe(fdf);
	mlx_put_image_to_window(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
		fdf->background->img_ptr, 0, 0);
	mlx_put_image_to_window(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
		fdf->img->img_ptr, 0, 0);
	mlx_destroy_image(fdf->prog->mlx_ptr, fdf->img->img_ptr);
	fdf->img->img_ptr = NULL;
}

void	draw_wireframe(t_fdf *fdf)
{
	init_img_structure(fdf);
	while (fdf->data->y < fdf->data->max_y)
	{
		fdf->data->x = 0;
		while (fdf->data->x < fdf->data->max_x)
		{
			draw_wireframe_sub(fdf);
			fdf->data->x += 1;
		}
		fdf->data->y += 1;
	}
	fdf->data->x = 0;
	fdf->data->y = 0;
}
