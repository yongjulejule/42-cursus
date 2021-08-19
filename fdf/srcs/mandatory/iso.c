/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:33:44 by jun               #+#    #+#             */
/*   Updated: 2021/08/19 17:33:49 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_vec	horizontal_rotate(t_vec vec, double angle)
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
t_vec	iso_proj(t_fdf *fdf, t_vec vec)
{
	t_vec	proj_vec;

	vec = horizontal_rotate(vec, fdf->carema->h_angle);
	vec = vertical_rotate(vec, fdf->carema->v_angle);
	proj_vec.x = ((vec.x - vec.y) * cos(atan(0.5))) * fdf->carema->scale;
	proj_vec.y = (-vec.z + ((vec.x + vec.y) * sin(atan(0.5))))
		* fdf->carema->scale;
	proj_vec.x += 200 + fdf->carema->horizon;
	proj_vec.y += 100 + fdf->carema->vertical;
	return (proj_vec);
}
