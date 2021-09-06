/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fdf_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:26:06 by jun               #+#    #+#             */
/*   Updated: 2021/09/06 19:10:02 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	handle_translation(t_fdf *fdf, int keycode)
{
	int	flag;

	flag = 1;
	if (keycode == KEY_UP)
		fdf->camera->vertical -= 5;
	else if (keycode == KEY_DOWN)
		fdf->camera->vertical += 5;
	else if (keycode == KEY_LEFT)
		fdf->camera->horizon -= 5;
	else if (keycode == KEY_RIGHT)
		fdf->camera->horizon += 5;
	else
		flag = 0;
	return (flag);
}

static void	mod_angle(t_fdf *fdf)
{
	if (fdf->camera->angle.x >= 2 * PI)
		fdf->camera->angle.x -= 2 * PI;
	else if (fdf->camera->angle.x < 0)
		fdf->camera->angle.x += 2 * PI;
	if (fdf->camera->angle.y >= 2 * PI)
		fdf->camera->angle.y -= 2 * PI;
	else if (fdf->camera->angle.y < 0)
		fdf->camera->angle.y += 2 * PI;
	if (fdf->camera->angle.z >= 2 * PI)
		fdf->camera->angle.z -= 2 * PI;
	else if (fdf->camera->angle.z < 0)
		fdf->camera->angle.z += 2 * PI;
}

static int	handle_rotation(t_fdf *fdf, int keycode)
{
	int	flag;

	flag = 1;
	if (keycode == KEY_Z)
		fdf->camera->angle.x += PI / 60;
	else if (keycode == KEY_X && fdf->camera->proj != PALL)
		fdf->camera->angle.y += PI / 60;
	else if (keycode == KEY_C && fdf->camera->proj != PALL)
		fdf->camera->angle.z += PI / 60;
	else if (keycode == KEY_A)
		fdf->camera->angle.x -= PI / 60;
	else if (keycode == KEY_S && fdf->camera->proj != PALL)
		fdf->camera->angle.y -= PI / 60;
	else if (keycode == KEY_D && fdf->camera->proj != PALL)
		fdf->camera->angle.z -= PI / 60;
	else
		return (0);
	mod_angle(fdf);
	return (flag);
}

int	key_press(int keycode, void *param)
{
	t_fdf	*fdf;
	int		flag;

	flag = 0;
	fdf = (t_fdf *)param;
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	flag += handle_translation(fdf, keycode);
	flag += handle_rotation(fdf, keycode);
	if (keycode == KEY_SPACE)
	{
		fdf->camera->proj += 1;
		fdf->camera->proj %= 2;
		fdf->camera->angle.y = 0;
		fdf->camera->angle.z = 0;
		flag += 1;
	}
	if (flag)
	{
		mlx_clear_window(fdf->prog->mlx_ptr, fdf->prog->win_ptr);
		draw(fdf);
	}
	return (SUCCESS_FLAG);
}

void	hook_fdf(t_fdf *fdf)
{
	mlx_hook(fdf->prog->win_ptr, KEY_PRESS, 0, key_press, fdf);
	mlx_hook(fdf->prog->win_ptr, RED_DOT, 0, close_window, fdf);
	mlx_hook(fdf->prog->win_ptr, MOUSE_PRESS, 0, mouse_press, fdf);
	mlx_hook(fdf->prog->win_ptr, MOUSE_REL, 0, mouse_release, fdf);
	mlx_hook(fdf->prog->win_ptr, MOUSE_MOV, 0, mouse_move, fdf);
}
