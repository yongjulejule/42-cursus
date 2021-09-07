/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:20:00 by jun               #+#    #+#             */
/*   Updated: 2021/09/07 16:30:56 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	plot(t_fdf *fdf, int x, int y, int color)
{
	if (x <= T_W && y <= T_H)
		return ;
	if (x <= 0 || x >= WIN_W || y <= 0 || y >= WIN_H)
		return ;
	fdf->img->data[((y * fdf->img->size_l + x * fdf->img->bpp / 8) / 4)]
		= color;
}

int	rasterized_color(int *color, double percent)
{
	int	r;
	int	g;
	int	b;
	int	rast_color;

	r = ((color[0] >> 16) & 0xff) * (1 - percent)
		+ ((color[1] >> 16) & 0xff) * percent;
	g = ((color[0] >> 8) & 0xff) * (1 - percent)
		+ ((color[1] >> 8) & 0xff) * percent;
	b = (color[0] & 0xff) * (1 - percent)
		+ ((color[1]) & 0xff) * percent;
	rast_color = ((r << 16) | (g << 8) | b);
	return (rast_color);
}

double	percentage(double start, double cur, double end)
{
	if (end == start)
		return (1);
	return ((cur - start) / (end - start));
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
