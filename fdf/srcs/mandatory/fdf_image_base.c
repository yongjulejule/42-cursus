/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:46:48 by jun               #+#    #+#             */
/*   Updated: 2021/09/06 10:16:45 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_img(t_fdf *fdf)
{
	int	count_h;
	int	count_w;

	count_h = 0;
	while (count_h < WIN_H)
	{
		count_w = 0;
		while (count_w < WIN_W)
		{
			fdf->img->data[(count_h * fdf->img->size_l
					+ count_w * fdf->img->bpp / 8) / 4] = 0x8f000000;
			count_w++;
		}
		count_h++;
	}
}

void	init_img_structure(t_fdf *fdf)
{
	if (!fdf->img)
		fdf->img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!fdf->img->img_ptr)
		fdf->img->img_ptr = mlx_new_image(fdf->prog->mlx_ptr,
				WIN_W, WIN_H);
	if (!fdf->img->img_ptr)
		is_error("Error while initiate image");
	fdf->img->data = (int *)mlx_get_data_addr(fdf->img->img_ptr,
			&fdf->img->bpp, &fdf->img->size_l, &fdf->img->endian);
	if (!fdf->img->data)
		is_error("Error while initiate image data");
	init_img(fdf);
}
