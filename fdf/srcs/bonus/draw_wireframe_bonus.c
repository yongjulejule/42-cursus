/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wireframe_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:39:12 by jun               #+#    #+#             */
/*   Updated: 2021/09/07 16:29:41 by yongjule         ###   ########.fr       */
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

static void	draw_wireframe_sub(t_fdf *fdf, int cur_x, int cur_y)
{
	t_vec	vec_0;
	t_vec	vec_1;

	fdf->data->x = cur_x;
	fdf->data->y = cur_y;
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

static void	draw_wireframe(t_fdf *fdf, int **priority_arr)
{
	int	col;
	int	row;
	int	cur;

	cur = 0;
	while (1)
	{
		col = 0;
		if (cur == fdf->data->max_x + fdf->data->max_y - 1)
			break ;
		while (col < fdf->data->max_y)
		{
			row = 0;
			while (row < fdf->data->max_x)
			{
				if (cur == priority_arr[col][row])
					draw_wireframe_sub(fdf, row, col);
				row++;
			}
			col++;
		}
		cur++;
	}
	row = -1;
}

void	draw_wireframe_main(t_fdf *fdf)
{
	int		**priority_arr;
	int		row;
	t_vec	endpoint;

	endpoint = get_endpoint(fdf);
	priority_arr = get_priority_arr(fdf, endpoint.x, endpoint.y);
	draw_wireframe(fdf, priority_arr);
	row = 0;
	while (++row < fdf->data->max_y)
		free(priority_arr[row]);
	free(priority_arr);
	priority_arr = NULL;
	fdf->data->x = 0;
	fdf->data->y = 0;
}
