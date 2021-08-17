/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wireframe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:39:12 by jun               #+#    #+#             */
/*   Updated: 2021/08/17 22:27:49 by jun              ###   ########.fr       */
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
void	draw_wireframe(t_fdf *fdf)
{
	t_vec	vec_0;
	t_vec	vec_1;

	while (fdf->data->y < fdf->data->max_y)
	{
		fdf->data->x = 0;
		while (fdf->data->x < fdf->data->max_x)
		{
			vec_0 = iso_proj(get_coordi(fdf, fdf->data->x, fdf->data->y));
			if (fdf->data->x != fdf->data->max_x - 1)
			{
				vec_1 = iso_proj(get_coordi(fdf, fdf->data->x + 1, fdf->data->y));
				drawline(fdf->prog->mlx_ptr, fdf->prog->win_ptr, vec_0.x, vec_1.x, vec_0.y, vec_1.y);
			}
			if (fdf->data->y != fdf->data->max_y - 1)
			{
				vec_1 = iso_proj(get_coordi(fdf, fdf->data->x, fdf->data->y + 1));
				drawline(fdf->prog->mlx_ptr, fdf->prog->win_ptr, vec_0.x, vec_1.x, vec_0.y, vec_1.y);
			}
			fdf->data->x += 1;
		}
		fdf->data->y += 1;
	}
}
