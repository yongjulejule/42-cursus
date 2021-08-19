/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wireframe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:39:12 by jun               #+#    #+#             */
/*   Updated: 2021/08/19 18:04:30 by jun              ###   ########.fr       */
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
	int		color[2];

	while (fdf->data->y < fdf->data->max_y)
	{
		fdf->data->x = 0;
		while (fdf->data->x < fdf->data->max_x)
		{
			vec_0 = iso_proj(fdf, get_coordi(fdf, fdf->data->x, fdf->data->y));
			if (fdf->data->x != fdf->data->max_x - 1)
			{
				vec_1 = iso_proj(fdf,
						get_coordi(fdf, fdf->data->x + 1, fdf->data->y));
				color[0] = fdf->data->data[1][fdf->data->y][fdf->data->x];
				color[1] = fdf->data->data[1][fdf->data->y][fdf->data->x + 1];
				drawline(fdf, vec_0, vec_1, color);
			}
			if (fdf->data->y != fdf->data->max_y - 1)
			{
				vec_1 = iso_proj(fdf,
						get_coordi(fdf, fdf->data->x, fdf->data->y + 1));
				color[0] = fdf->data->data[1][fdf->data->y][fdf->data->x];
				color[1] = fdf->data->data[1][fdf->data->y + 1][fdf->data->x];
				drawline(fdf, vec_0, vec_1, color);
			}
			fdf->data->x += 1;
		}
		fdf->data->y += 1;
	}
}
