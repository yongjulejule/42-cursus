/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:01:28 by jun               #+#    #+#             */
/*   Updated: 2021/08/19 20:13:59 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	translate_fdf(t_fdf *fdf)
{
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
			10, 20, 0xffffff, "Welcome to FDF");
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
			10, 40, 0xffffff, "Press A/D to move horizontaly");
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
			10, 60, 0xffffff, "Press W/S to move vertically");
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
			10, 80, 0xffffff, "Press Arrow key to rotate");
	mlx_string_put(fdf->prog->mlx_ptr, fdf->prog->win_ptr,
			10, 100, 0xffffff, "Press ESC to exit");
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
				fdf->img->data[(count_h * fdf->img->size_l + count_w * fdf->img->bpp / 8) / 4] = 0x242424;
			else
				fdf->img->data[(count_h * fdf->img->size_l + count_w * fdf->img->bpp / 8) / 4] = 0x000000;
			count_w++;
		}
		count_h++;
	}
}

static t_fdf	*init_fdf_structure(t_data *data)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)ft_calloc(1, sizeof(t_fdf));
	fdf->data = data;
	fdf->prog = (t_program *)ft_calloc(1, sizeof(t_program));
	fdf->img = (t_img *)ft_calloc(1, sizeof(t_img));
	fdf->prog->mlx_ptr = mlx_init();
	if (!fdf->prog->mlx_ptr)
		is_error("Error while initiate mlx");
	fdf->prog->win_ptr = mlx_new_window(fdf->prog->mlx_ptr,\
			WIN_W, WIN_H, "crazy_fdf");
	if (!fdf->prog->win_ptr)
		is_error("Error while initiate window");
	fdf->img->img_ptr = mlx_new_image(fdf->prog->mlx_ptr, WIN_W, WIN_H);
	if (!fdf->img->img_ptr)
		is_error("Error while initiate image");
	fdf->img->data = (int *)mlx_get_data_addr(fdf->img->img_ptr,
			&fdf->img->bpp, &fdf->img->size_l, &fdf->img->endian);
	if (!fdf->img->data)
		is_error("Error while initiate image data");
	init_img(fdf);
	translate_fdf(fdf);
	return (fdf);
}

static t_carema	*init_carema_structure(t_fdf *fdf)
{
	t_carema	*carema;

	carema = (t_carema *)ft_calloc(1, sizeof(t_carema));
	carema->h_angle = 0;
	carema->v_angle = 0;
	carema->scale = 20;
	carema->horizon = carema->scale * fdf->data->max_x * cos(atan(0.5));
	carema->vertical = 200;
	return (carema);
}

void	mlx_main(t_data *data)
{
	t_fdf	*fdf;

	fdf = init_fdf_structure(data);
	fdf->carema = init_carema_structure(fdf);
	draw_wireframe(fdf);
	mlx_put_image_to_window(fdf->prog->mlx_ptr, fdf->prog->win_ptr, fdf->img->img_ptr, 0, 0);
	translate_fdf(fdf);
	mlx_loop(fdf->prog->mlx_ptr);
}
