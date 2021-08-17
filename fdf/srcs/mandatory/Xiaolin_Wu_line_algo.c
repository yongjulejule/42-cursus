/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Xiaolin_Wu_line_algo.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:19:54 by jun               #+#    #+#             */
/*   Updated: 2021/08/17 21:26:39 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	drawline(void *mlx_ptr, void *win_ptr, double x0, double x1, double y0, double y1)
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

	steep = abs((int)(y1 - y0)) > abs((int)(x1 - x0));
	if (steep)
	{
		swap(&x0, &y0);
		swap(&x1, &y1);
	}
	if (x0 > x1)
	{
		swap(&x0, &x1);
		swap(&y0, &y1);
	}
	dx = x1 - x0;
	dy = y1 - y0;
	if (dx == 0)
		gradient = 1;
	else
		gradient = dy / dx;

	x_end = round(x0);
	y_end = y0 + gradient * (x_end - x0);
	x_gap = rfpart(x0 + 0.5);
	xpxl1 = x_end;
	ypxl1 = ipart(y_end);

	if (steep)
	{
		plot(mlx_ptr, win_ptr, ypxl1, xpxl1, rfpart(y_end) * x_gap + 0xFFFFFF);
		plot(mlx_ptr, win_ptr, ypxl1 + 1, xpxl1, fpart(y_end) * x_gap + 0xFFFFFF);
	}
	else
	{
		plot(mlx_ptr, win_ptr, xpxl1, ypxl1, rfpart(y_end) * x_gap + 0xFFFFFF);
		plot(mlx_ptr, win_ptr, xpxl1, ypxl1 + 1, fpart(y_end) * x_gap + 0xFFFFFF);
	}
	intery = y_end + gradient;

	x_end = round(x1);
	y_end = y1 + gradient * (x_end - x1);
	x_gap = fpart(x1 + 0.5);
	xpxl2 = x_end;
	ypxl2 = ipart(y_end);
	if (steep)
	{
		plot(mlx_ptr, win_ptr, ypxl2, xpxl2, rfpart(y_end) * x_gap + 0xFFFFFF);
		plot(mlx_ptr, win_ptr, ypxl2 + 1, xpxl2, fpart(y_end) * x_gap + 0xFFFFFF);
	}
	else
	{
		plot(mlx_ptr, win_ptr, xpxl2, ypxl2, rfpart(y_end) * x_gap + 0xFFFFFF);
		plot(mlx_ptr, win_ptr, xpxl2, ypxl2 + 1, fpart(y_end) * x_gap + 0xFFFFFF);
	}

	x = xpxl1 + 1;
	while (x < xpxl2)
	{
		if (steep)
		{
			plot(mlx_ptr, win_ptr, ipart(intery), x, rfpart(intery) + 0xFFFFFF);
			plot(mlx_ptr, win_ptr, ipart(intery) + 1, x, fpart(intery) + 0xFFFFFF);
			intery += gradient;
		}
		else
		{
			plot(mlx_ptr, win_ptr, x, ipart(intery), rfpart(intery) + 0xFFFFFF);
			plot(mlx_ptr, win_ptr, x, ipart(intery) + 1, fpart(intery) + 0xFFFFFF);
			intery += gradient;
		}
		x++;
	}
}
//
//#include <stdio.h>
//int	main()
//{
//	void	*mlx_ptr;
//	void	*win_ptr;
//	t_vec	vec_0;
//	t_vec	vec_1;
//
//	vec_0.x = 0;
//	vec_0.y = 0;
//	vec_0.z = 0;
//	vec_1.x = 0;
//	vec_1.y = 1;
//	vec_1.z = 1;
//	vec_0 = iso_proj(vec_0);
//	vec_1 = iso_proj(vec_1);
//	printf("%f, %f, %f", vec_0.x, vec_0.y, vec_0.z);
//	printf("%f, %f, %f", vec_1.x, vec_1.y, vec_1.z);
//	mlx_ptr = mlx_init();
//	win_ptr = mlx_new_window(mlx_ptr, 1000, 600, "title");
//	drawline(mlx_ptr, win_ptr, vec_0.x, vec_1.x, vec_0.y, vec_1.y);
////	drawline(mlx_ptr, win_ptr, 50, 100, 50, 100);
////	drawline(mlx_ptr, win_ptr, 60, 400, 50, 300);
////	drawline(mlx_ptr, win_ptr, 50, 500, 60, 200);
////	drawline(mlx_ptr, win_ptr, 60, 400, 60, 200);
//	mlx_loop(mlx_ptr);
//}
