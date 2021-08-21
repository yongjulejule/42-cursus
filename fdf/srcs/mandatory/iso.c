/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:33:44 by jun               #+#    #+#             */
/*   Updated: 2021/08/20 21:44:42 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include <string.h>

t_vec	rotation_based_angle(t_fdf *fdf, t_vec vec, t_vec angle)
{
	t_vec	newvec;
	double	alpha;
	double	beta;
	double	gamma;

	alpha = angle.x;
	beta = angle.y;
	gamma = angle.z;
	newvec.x =\
			  ((cos(alpha) * cos(beta) * vec.x)\
			   + ((cos(alpha) * sin(beta) * sin(gamma) - sin(alpha) * cos(gamma)) * vec.y)\
			   + ((cos(alpha) * sin(beta) * cos(gamma) + sin(alpha) * sin(gamma)) * vec.z));
	newvec.y =\
			  ((sin(alpha) * cos(beta) * vec.x)\
			   + ((sin(alpha) * sin(beta) * sin(gamma) + cos(alpha) * cos(gamma)) * vec.y)\
			   + ((sin(alpha) * sin(beta) * cos(gamma) - cos(alpha) * sin(gamma)) * vec.z));
	newvec.z =\
			  ((-sin(beta) * vec.x)\
			   + ((cos(beta) * sin(gamma)) * vec.y)\
			   + ((cos(beta) * cos(gamma)) * vec.z));
	return (newvec);
}

t_vec	horizontal_rotate(t_fdf *fdf, t_vec vec, double angle)
{
	t_vec	prev_vec;

	prev_vec = vec;
	vec.x = prev_vec.x * cos(angle) - prev_vec.y * sin(angle);
	vec.y = prev_vec.x * sin(angle) + prev_vec.y * cos(angle);
	return (vec);
}

t_vec	vertical_rotate(t_vec vec, double angle)
{
	t_vec	prev_vec;

	prev_vec = vec;
	vec.x = prev_vec.x * cos(angle) - prev_vec.z * sin(angle);
	vec.z = prev_vec.x * sin(angle) + prev_vec.z * cos(angle);
	return (vec);
}

t_vec	get_center(t_fdf *fdf)
{
	t_vec	proj_vec;
	t_vec	gap;

	gap = fdf->camera->center;
	gap.x = round((double)fdf->data->max_x / 2);
	gap.y = round((double)fdf->data->max_y / 2);
	gap.z = 0;
	gap = rotation_based_angle(fdf, gap, fdf->camera->angle);
	proj_vec.x = (((gap.x - gap.y) * cos(atan(0.5))) * fdf->camera->scale);
	proj_vec.y = ((-gap.z + ((gap.x + gap.y) * sin(atan(0.5))))\
			* fdf->camera->scale);
	gap.x = ((double)WIN_W / 2) - proj_vec.x;
	gap.y = ((double)WIN_H / 2) - proj_vec.y;
	return (gap);
}

t_vec	iso_proj(t_fdf *fdf, t_vec vec)
{
	t_vec	proj_vec;

	vec = rotation_based_angle(fdf, vec, fdf->camera->angle);
	proj_vec.x = (((vec.x - vec.y) * cos(atan(0.5))) * fdf->camera->scale);
	proj_vec.y = ((-vec.z + ((vec.x + vec.y) * sin(atan(0.5))))\
			* fdf->camera->scale);
	proj_vec.x += fdf->camera->horizon;
	proj_vec.y += fdf->camera->vertical;
	return (proj_vec);   
}

t_vec	parallel(t_fdf *fdf, t_vec vec)
{
	t_vec	proj_vec;

	vec = rotation_based_angle(fdf, vec, fdf->camera->angle);
	proj_vec.x = vec.x * fdf->camera->scale;
	proj_vec.y = vec.y * fdf->camera->scale;
	proj_vec.x += fdf->camera->horizon;
	proj_vec.y += fdf->camera->vertical;
	return (proj_vec);
}

#include <stdio.h>
t_vec	one_perspective_proj(t_fdf *fdf, t_vec vec)
{
	t_vec	proj_vec;
	double	d;
	double	px;
	double	py;

//	swap(&vec.y, &vec.z);
//	swap(&vec.x, &vec.y);
	vec = rotation_based_angle(fdf, vec, fdf->camera->angle);
	px = vec.x * vec.x;
	py = vec.y * vec.y;
	fprintf(stderr, "px : %f, py : %f\n", px, py);
	d = sqrt(px + py + 1);
	proj_vec.x = (((d * vec.y) / (vec.y + d)) * fdf->camera->scale);
	proj_vec.y = (((d * vec.z) / (vec.y + d)) * fdf->camera->scale);
	proj_vec.x += fdf->camera->horizon;
	proj_vec.y += fdf->camera->vertical;
	//	proj_vec.x = WIN_W - proj_vec.x;
	//	proj_vec.y = WIN_H - proj_vec.y;
	return (proj_vec);
}
