/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:20:00 by jun               #+#    #+#             */
/*   Updated: 2021/08/19 20:20:08 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	plot(t_fdf *fdf, void *mlx_ptr, void * win_ptr, int x, int y, double brightness, int color)
{
//	int	r;
//	int	g;
//	int	b;
//	int	anti_aliased_color;
//
//	r = ((color >> 16) & 0xff) * brightness;
//	g = ((color >> 8) & 0xff) * brightness;
//	b = (color & 0xff) * brightness;
//	anti_aliased_color = ((r << 16) | (g << 8) | b);
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
