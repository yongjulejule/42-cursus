/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wireframe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:39:12 by jun               #+#    #+#             */
/*   Updated: 2021/08/23 17:20:00 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static t_vec	get_coordi(t_fdf *fdf, int x, int y)
{
	t_vec vec;

	vec.x = x;
	vec.y = y;
	vec.z = fdf->data->data[0][y][x];
	return (vec);
}

static void	init_img(t_fdf *fdf)
{
	int	count_h;
	int	count_w;

	count_h = 0;
	while (count_h < WIN_H)
	{
		count_w = 0;
		while (count_w < WIN_W)
		{
			if (count_w < T_W && count_h < T_H)
				fdf->img->data[(count_h * fdf->img->size_l\
						+ count_w * fdf->img->bpp / 8) / 4] = 0x242424;
			else
				fdf->img->data[(count_h * fdf->img->size_l\
						+ count_w * fdf->img->bpp / 8) / 4] = 0x8f000000;
			count_w++;
		}
		count_h++;
	}
}

static void	init_img_structure(t_fdf *fdf)
{
	if (!fdf->img)
		fdf->img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!fdf->img->img_ptr)
		fdf->img->img_ptr = mlx_new_image(fdf->prog->mlx_ptr, WIN_W, WIN_H);
	if (!fdf->img->img_ptr)
		is_error("Error while initiate image");
	fdf->img->data = (int *)mlx_get_data_addr(fdf->img->img_ptr,
			&fdf->img->bpp, &fdf->img->size_l, &fdf->img->endian);
	if (!fdf->img->data)
		is_error("Error while initiate image data");
	init_img(fdf);
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
