/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Xiaolin_Wu_line_algo.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:19:54 by jun               #+#    #+#             */
/*   Updated: 2021/08/19 20:10:21 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	rastrized_color(int *color, double percent)
{
	int	r;
	int	g;
	int	b;
	int	rast_color;

	r = ((color[0] >> 16) & 0xff) * (1 - percent) + ((color[1] >> 16) & 0xff) * percent;
	g = ((color[0] >> 8) & 0xff) * (1 - percent) + ((color[1] >> 8) & 0xff) * percent;
	b = (color[0] & 0xff) * (1 - percent) + ((color[1]) & 0xff) * percent;
	rast_color = ((r << 16) | (g << 8) | b);
	return (rast_color);
}

double	percentage(double start, double cur, double end)
{
	if (end == start)
		return (1);
	return ((cur - start) / (end - start));
}

void	drawline(t_fdf *fdf, t_vec vec_0, t_vec vec_1, int *color)
{
	int		steep;
	int		x;
	double	dx;
	double	dy;
	double	gradient;
	double	x_end;
	double	y_end;
	double	x_gap;
	double	xpxl1;
	double	ypxl1;
	double	xpxl2;
	double	ypxl2;
	double	intery;
	double	percent;

	/* TODO : Handle offset here */
	if (((vec_0.x < T_W  || vec_1.x < T_W)  && (vec_0.y < T_H
			|| vec_1.y < T_H)) || vec_0.x > WIN_W || vec_1.x > WIN_W
			|| vec_1.y > WIN_H || vec_0.y > WIN_H || vec_0.x < 0
			|| vec_1.x < 0 || vec_0.y < 0 || vec_1.y < 0)
		return ;
	steep = fabs((vec_1.y - vec_0.y)) > fabs((vec_1.x - vec_0.x));
	if (steep)
	{
		swap(&vec_0.x, &vec_0.y);
		swap(&vec_1.x, &vec_1.y);
	}
	if (vec_0.x > vec_1.x)
	{
		swap(&vec_0.x, &vec_1.x);
		swap(&vec_0.y, &vec_1.y);
		swap_i(&color[0], &color[1]);
	}
	dx = vec_1.x - vec_0.x;
	dy = vec_1.y - vec_0.y;
	if (dx == 0)
		gradient = 1;
	else
		gradient = dy / dx;

	x_end = round(vec_0.x);
	y_end = vec_0.y + gradient * (x_end - vec_0.x);
	x_gap = rfpart(vec_0.x + 0.5);
	xpxl1 = x_end;
	ypxl1 = ipart(y_end);

	/* First pixcel */
	percent = 0;
	if (steep)
	{
		plot(fdf, fdf->prog->mlx_ptr, fdf->prog->win_ptr, ypxl1, xpxl1, rfpart(y_end) * x_gap, rastrized_color(color, percent));
		plot(fdf, fdf->prog->mlx_ptr, fdf->prog->win_ptr, ypxl1 + 1, xpxl1, fpart(y_end) * x_gap, rastrized_color(color, percent));
	}
	else
	{
		plot(fdf, fdf->prog->mlx_ptr, fdf->prog->win_ptr, xpxl1, ypxl1, rfpart(y_end) * x_gap, rastrized_color(color, percent));
		plot(fdf, fdf->prog->mlx_ptr, fdf->prog->win_ptr, xpxl1, ypxl1 + 1, fpart(y_end) * x_gap, rastrized_color(color, percent));
	}
	intery = y_end + gradient;

	x_end = round(vec_1.x);
	y_end = vec_1.y + gradient * (x_end - vec_1.x);
	x_gap = fpart(vec_1.x + 0.5);
	xpxl2 = x_end;
	ypxl2 = ipart(y_end);

	/* Last pixcel */
	percent = 1;
	if (steep)
	{
		plot(fdf, fdf->prog->mlx_ptr, fdf->prog->win_ptr, ypxl2, xpxl2, rfpart(y_end) * x_gap, rastrized_color(color, percent));
		plot(fdf, fdf->prog->mlx_ptr, fdf->prog->win_ptr, ypxl2 + 1, xpxl2, fpart(y_end) * x_gap, rastrized_color(color, percent));
	}
	else
	{
		plot(fdf, fdf->prog->mlx_ptr, fdf->prog->win_ptr, xpxl2, ypxl2, rfpart(y_end) * x_gap, rastrized_color(color, percent));
		plot(fdf, fdf->prog->mlx_ptr, fdf->prog->win_ptr, xpxl2, ypxl2 + 1, fpart(y_end) * x_gap, rastrized_color(color, percent));
	}

	x = xpxl1 + 1;
	while (x < xpxl2)
	{
		percent = percentage((double)xpxl1 + 1, (double)x, (double)xpxl2);
		if (steep)
		{
			plot(fdf, fdf->prog->mlx_ptr, fdf->prog->win_ptr, ipart(intery), x, rfpart(intery), rastrized_color(color, percent));
			plot(fdf, fdf->prog->mlx_ptr, fdf->prog->win_ptr, ipart(intery) + 1, x, fpart(intery), rastrized_color(color, percent));
			intery += gradient;
		}
		else
		{
			plot(fdf, fdf->prog->mlx_ptr, fdf->prog->win_ptr, x, ipart(intery), rfpart(intery), rastrized_color(color, percent));
			plot(fdf, fdf->prog->mlx_ptr, fdf->prog->win_ptr, x, ipart(intery) + 1, fpart(intery), rastrized_color(color, percent));
			intery += gradient;
		}
		x++;
	}
}
