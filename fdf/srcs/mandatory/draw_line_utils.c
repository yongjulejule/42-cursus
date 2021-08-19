/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:20:00 by jun               #+#    #+#             */
/*   Updated: 2021/08/19 23:09:28 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	plot(t_fdf *fdf, int x, int y, int color)
{
	if (x < T_W && y < T_H)
		return ;
	if (x < 0 || x > 1600 || y < 0 || y > 900)
		return ;
	fdf->img->data[(y * fdf->img->size_l + x * fdf->img->bpp / 8) / 4] = color; 
} 

double	ipart(double x)
{
	return (floor(x));
}

double	fpart(double x)
{
	return (x - floor(x));
}

double	rfpart(double x)
{
	return (1 - fpart(x));
}

void	swap(double *x, double *y)
{
	double	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void	swap_i(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}
