/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:33:44 by jun               #+#    #+#             */
/*   Updated: 2021/08/17 23:09:28 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_vec	iso_proj(t_vec vec)
{
	t_vec	proj_vec;

	proj_vec.x = ((vec.x - vec.y) * cos(atan(0.5))) * 20;
	proj_vec.y = (-vec.z + ((vec.x + vec.y) * sin(atan(0.5)))) * 20;
	/* TODO : change location based on max_x, max_y*/
	proj_vec.x += 380;
	proj_vec.y += 220;
	return (proj_vec);
}
