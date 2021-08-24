/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image_base_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:46:48 by jun               #+#    #+#             */
/*   Updated: 2021/08/24 21:16:55 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	descript_iso(t_fdf *fdf)
{
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
		10, 60, 0xffffff, "Press Arrow_key to Move");
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
		10, 80, 0xffffff, "Press A/S/D to Rotate");
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
		10, 100, 0xffffff, "Press Z/X/C to Rotate Inversely");
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
		10, 120, 0xffffff, "Press MOUSE_L/R to Rotate_crazy");
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
		10, 140, 0xffffff, "Use Scroll to Zoom In/Out");
}

static void	descript_parallel(t_fdf *fdf)
{
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
		10, 65, 0xffffff, "Press Arrow_key to Move");
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
		10, 90, 0xffffff, "Press A to Rotate");
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
		10, 115, 0xffffff, "Press Z to Rotate Inversely");
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
		10, 140, 0xffffff, "Use Scroll to Zoom In/Out");
}

void	description_fdf(t_fdf *fdf)
{
	char	*scale;
	char	*scale_info;

	scale = ft_itoa(fdf->camera->scale);
	if (!scale)
		is_error("Error while Malloc");
	scale_info = ft_strjoin("Current Scale is ", scale);
	if (!scale_info)
		is_error("Error while Malloc");
	free(scale);
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
		10, 20, 0xffffff, "Welcome to FDF!");
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
		10, 40, 0xffffff, "Press Space to Swich Projection");
	if (fdf->camera->proj == ISO)
		descript_iso(fdf);
	else
		descript_parallel(fdf);
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
		10, 160, 0xffffff, scale_info);
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
		10, 180, 0xffffff, "Press ESC to exit");
	free(scale_info);
}

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
			if (count_w < T_W && count_h < T_H)
				fdf->img->data[(count_h * fdf->img->size_l
						+ count_w * fdf->img->bpp / 8) / 4] = 0x242424;
			else
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
		fdf->img->img_ptr = mlx_new_image(fdf->prog->mlx_ptr, WIN_W, WIN_H);
	if (!fdf->img->img_ptr)
		is_error("Error while initiate image");
	fdf->img->data = (int *)mlx_get_data_addr(fdf->img->img_ptr,
			&fdf->img->bpp, &fdf->img->size_l, &fdf->img->endian);
	if (!fdf->img->data)
		is_error("Error while initiate image data");
	init_img(fdf);
}
