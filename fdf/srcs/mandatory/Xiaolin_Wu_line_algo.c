/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Xiaolin_Wu_line_algo.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:19:54 by jun               #+#    #+#             */
/*   Updated: 2021/08/19 23:09:58 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	rastrized_color(int *color, double percent)
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

static double	percentage(double start, double cur, double end)
{
	if (end == start)
		return (1);
	return ((cur - start) / (end - start));
}

void	drawline(t_fdf *fdf, t_vec vec_0, t_vec vec_1, int *color)
{
	int		steep;
	int		x;
	double	gradient;
	double	xpxl1;
	double	ypxl1;
	double	xpxl2;
	double	ypxl2;
	double	intery;
	double	percent;

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
	if (vec_1.x == vec_0.x)
		gradient = 1;
	else
		gradient = (vec_1.y - vec_0.y) / (vec_1.x - vec_0.x);

	xpxl1 = round(vec_0.x);
	ypxl1 = ipart(vec_0.y + gradient * (xpxl1 - vec_0.x));

	/* First pixcel */
	if (steep)
	{
		plot(fdf, ypxl1, xpxl1, rastrized_color(color, 0));
		plot(fdf, ypxl1 + 1, xpxl1, rastrized_color(color, 0));
	}
	else
	{
		plot(fdf, xpxl1, ypxl1, rastrized_color(color, 0));
		plot(fdf, xpxl1, ypxl1 + 1, rastrized_color(color, 0));
	}
	intery = vec_0.y + gradient * (round(vec_0.x) - vec_0.x) + gradient;

	xpxl2 = round(vec_1.x);
	ypxl2 = ipart(vec_1.y + gradient * (xpxl2 - vec_1.x));

	/* Last pixcel */
	if (steep)
	{
		plot(fdf, ypxl2, xpxl2, rastrized_color(color, 1));
		plot(fdf, ypxl2 + 1, xpxl2, rastrized_color(color, 1));
	}
	else
	{
		plot(fdf, xpxl2, ypxl2, rastrized_color(color, 1));
		plot(fdf, xpxl2, ypxl2 + 1, rastrized_color(color, 1));
	}

	x = xpxl1 + 1;
	while (x < xpxl2)
	{
		percent = percentage((double)xpxl1 + 1, (double)x, (double)xpxl2);
		if (steep)
		{
			plot(fdf, ipart(intery), x,  rastrized_color(color, percent));
			plot(fdf, ipart(intery) + 1, x, rastrized_color(color, percent));
		}
		else
		{
			plot(fdf, x, ipart(intery), rastrized_color(color, percent));
			plot(fdf, x, ipart(intery) + 1, rastrized_color(color, percent));
		}
		intery += gradient;
		x++;
	}
}
