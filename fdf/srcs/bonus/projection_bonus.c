/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:33:44 by jun               #+#    #+#             */
/*   Updated: 2021/09/07 09:51:49 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_vec	rotation_based_angle(t_vec vec, t_vec angle)
{
	t_vec	newvec;
	double	alpha;
	double	beta;
	double	gamma;

	alpha = angle.x;
	beta = angle.y;
	gamma = angle.z;
	newvec.x = ((cos(alpha) * cos(beta) * vec.x)
			+ ((cos(alpha) * sin(beta) * sin(gamma)
					- sin(alpha) * cos(gamma)) * vec.y)
			+ ((cos(alpha) * sin(beta) * cos(gamma)
					+ sin(alpha) * sin(gamma)) * vec.z));
	newvec.y = ((sin(alpha) * cos(beta) * vec.x)
			+ ((sin(alpha) * sin(beta) * sin(gamma)
					+ cos(alpha) * cos(gamma)) * vec.y)
			+ ((sin(alpha) * sin(beta) * cos(gamma)
					- cos(alpha) * sin(gamma)) * vec.z));
	newvec.z = ((-sin(beta) * vec.x)
			+ ((cos(beta) * sin(gamma)) * vec.y)
			+ ((cos(beta) * cos(gamma)) * vec.z));
	return (newvec);
}

t_vec	iso_proj(t_fdf *fdf, t_vec vec)
{
	t_vec	proj_vec;

	vec = rotation_based_angle(vec, fdf->camera->angle);
	proj_vec.x = (((vec.x - vec.y) * cos(atan(0.5))) * fdf->camera->scale);
	proj_vec.y = ((-vec.z * 0.9 + ((vec.x + vec.y) * sin(atan(0.5))))
			* fdf->camera->scale);
	proj_vec.x += fdf->camera->horizon;
	proj_vec.y += fdf->camera->vertical;
	return (proj_vec);
}

t_vec	parallel(t_fdf *fdf, t_vec vec)
{
	t_vec	proj_vec;

	vec = rotation_based_angle(vec, fdf->camera->angle);
	proj_vec.x = vec.x * fdf->camera->scale;
	proj_vec.y = vec.y * fdf->camera->scale;
	proj_vec.x += fdf->camera->horizon;
	proj_vec.y += fdf->camera->vertical;
	return (proj_vec);
}
