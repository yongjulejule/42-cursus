/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Xiaolin_Wu_line_algo.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:19:54 by jun               #+#    #+#             */
/*   Updated: 2021/08/24 11:34:49 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	drawline_sub(t_fdf *fdf, t_line_info info)
{
	int		x;
	double	xpxl1;
	double	xpxl2;
	double	per;

	xpxl1 = round(info.vec_0.x);
	xpxl2 = round(info.vec_1.x);
	x = xpxl1 - 1;
	while (++x < xpxl2)
	{
		per = percentage((double)xpxl1, (double)x, (double)xpxl2);
		if (info.steep)
		{
			plot(fdf, floor(info.intery), x, rasterized_color(fdf->color, per));
			plot(fdf, floor(info.intery) + 1, x,
				rasterized_color(fdf->color, per));
		}
		else
		{
			plot(fdf, x, floor(info.intery), rasterized_color(fdf->color, per));
			plot(fdf, x, floor(info.intery) + 1,
				rasterized_color(fdf->color, per));
		}
		info.intery += info.gradient;
	}
}

void	drawline(t_fdf *fdf, t_vec vec_0, t_vec vec_1)
{
	t_line_info	info;

	info.vec_0 = vec_0;
	info.vec_1 = vec_1;
	info.steep = fabs((info.vec_1.y - info.vec_0.y))
		> fabs((info.vec_1.x - info.vec_0.x));
	if (info.steep)
	{
		swap(&info.vec_0.x, &info.vec_0.y);
		swap(&info.vec_1.x, &info.vec_1.y);
	}
	if (info.vec_0.x > info.vec_1.x)
	{
		swap(&info.vec_0.x, &info.vec_1.x);
		swap(&info.vec_0.y, &info.vec_1.y);
		swap_i(&fdf->color[0], &fdf->color[1]);
	}
	if (info.vec_1.x == info.vec_0.x)
		info.gradient = 1;
	else
		info.gradient = (info.vec_1.y - info.vec_0.y)
			/ (info.vec_1.x - info.vec_0.x);
	info.intery = info.vec_0.y + info.gradient
		* (round(info.vec_0.x) - info.vec_0.x);
	drawline_sub(fdf, info);
}
