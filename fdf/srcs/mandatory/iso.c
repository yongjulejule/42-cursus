/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:33:44 by jun               #+#    #+#             */
/*   Updated: 2021/08/09 17:39:40 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_vec	point_isometric_proj(t_vec vec)
{
	t_vec	proj_vec;

	proj_vec.x = sqrt(3) * vec.x - sqrt(3) * vec.z;
	proj_vec.y = vec.x + 2 * vec.y + vec.z;
	proj_vec.x /= sqrt(6);
	proj_vec.y /= sqrt(6);
	return (proj_vec);
}
