/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wireframe_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:39:12 by jun               #+#    #+#             */
/*   Updated: 2021/09/06 21:21:49 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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

void	draw_wireframe(t_fdf *fdf)
{
//	if (fdf->camera->angle.x > PI / 2)
//	recursion based on 4 angles

//	if (fdf->camera->angle.x < PI / 2)
//	{
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
//	}
//	else if (fdf->camera->angle.x < PI)
//	{
//		while (fdf->data->y < fdf->data->max_y)
//		{
//			fdf->data->x = fdf->data->max_x - 1;
//			while (fdf->data->x >= 0)
//			{
//				draw_wireframe_sub(fdf);
//				fdf->data->x -= 1;
//			}
//			fdf->data->y += 1;
//		}
//	}
//	else if (fdf->camera->angle.x < (PI * 3) / 2)
//	{
//		while (fdf->data->y < fdf->data->max_y)
//		{
//			fdf->data->x = fdf->data->max_x - 1;
//			while (fdf->data->x >= 0)
//			{
//				draw_wireframe_sub(fdf);
//				fdf->data->x -= 1;
//			}
//			fdf->data->y += 1;
//		}
//	}
//	else{
//		while (fdf->data->y < fdf->data->max_y)
//		{
//			fdf->data->x = fdf->data->max_x - 1;
//			while (fdf->data->x >= 0)
//			{
//				draw_wireframe_sub(fdf);
//				fdf->data->x -= 1;
//			}
//			fdf->data->y += 1;
//		}
//	}
	fdf->data->x = 0;
	fdf->data->y = 0;
}
