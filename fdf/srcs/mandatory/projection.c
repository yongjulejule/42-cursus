/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:33:44 by jun               #+#    #+#             */
/*   Updated: 2021/08/24 22:47:45 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec	iso_proj(t_fdf *fdf, t_vec vec)
{
	t_vec	proj_vec;

	proj_vec.x = (((vec.x - vec.y) * cos(atan(0.5))) * fdf->camera->scale);
	proj_vec.y = ((-vec.z + ((vec.x + vec.y) * sin(atan(0.5))))
			* fdf->camera->scale);
	proj_vec.x += fdf->camera->horizon;
	proj_vec.y += fdf->camera->vertical;
	return (proj_vec);
}
