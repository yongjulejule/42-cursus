/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_priority.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <yongjule@42student.42seoul.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:20:00 by yongjule          #+#    #+#             */
/*   Updated: 2021/09/07 16:32:55 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	**get_priority_arr(t_fdf *fdf, int x_end, int y_end)
{
	int	**arr;
	int	col;
	int	row;

	col = 0;
	arr = (int **)ft_calloc(fdf->data->max_y, sizeof(int *));
	while (col < fdf->data->max_y)
	{
		arr[col] = (int *)ft_calloc(fdf->data->max_x, sizeof(int));
		row = -1;
		while (++row < fdf->data->max_x)
		{
			if ((y_end + x_end) == 0)
				arr[col][row] = fdf->data->max_y - 1 - col
					+ fdf->data->max_x - 1 - row;
			else if (y_end == 0)
				arr[col][row] = fdf->data->max_y - 1 - col + row;
			else if (x_end == 0)
				arr[col][row] = col + fdf->data->max_x - 1 - row;
			else
				arr[col][row] = row + col;
		}
		col++;
	}
	return (arr);
}

t_vec	init_vector(double x, double y, double z)
{
	t_vec	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

int	compare_point(double x0, double x1, double x2, double x3)
{
	int		flag;
	double	tmp1;
	double	tmp2;

	flag = 0;
	tmp1 = x0;
	tmp2 = x2;
	if (x0 < x1)
		tmp1 = x1;
	if (x2 < x3)
		tmp2 = x3;
	if (tmp1 < tmp2)
		tmp1 = tmp2;
	if (tmp1 == x0)
		flag = 1;
	else if (tmp1 == x1)
		flag = 2;
	else if (tmp1 == x2)
		flag = 3;
	else
		flag = 4;
	return (flag);
}

t_vec	get_endpoint(t_fdf *fdf)
{
	int		flag;
	t_vec	vec_0;
	t_vec	vec_1;
	t_vec	vec_2;
	t_vec	vec_3;

	flag = 0;
	vec_0 = iso_proj(fdf, init_vector(0, 0, 0));
	vec_1 = iso_proj(fdf, init_vector(0, fdf->data->max_y - 1, 0));
	vec_2 = iso_proj(fdf, init_vector(fdf->data->max_x - 1, 0, 0));
	vec_3 = iso_proj(fdf, init_vector(fdf->data->max_x - 1,
				fdf->data->max_y - 1, 0));
	flag = compare_point(vec_0.y, vec_1.y, vec_2.y, vec_3.y);
	if (flag == 1)
		vec_0 = init_vector(0, 0, 0);
	else if (flag == 2)
		vec_0 = init_vector(0, fdf->data->max_y - 1, 0);
	else if (flag == 3)
		vec_0 = init_vector(fdf->data->max_x, 0, 0);
	else
		vec_0 = init_vector(fdf->data->max_x, fdf->data->max_y, 0);
	return (vec_0);
}
