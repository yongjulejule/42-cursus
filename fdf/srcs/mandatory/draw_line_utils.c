/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:20:00 by jun               #+#    #+#             */
/*   Updated: 2021/08/09 17:33:07 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	plot(void *mlx_ptr, void * win_ptr, int x, int y, int color)
{
	mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
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
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}
