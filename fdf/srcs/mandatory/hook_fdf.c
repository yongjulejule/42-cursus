/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:26:06 by jun               #+#    #+#             */
/*   Updated: 2021/08/21 15:58:48 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	key_press(int keycode, void *param)
{
	t_fdf	*fdf;
	int		flag;

	flag = 1;
	fdf = (t_fdf *)param;
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == KEY_UP)
		fdf->camera->vertical -= 5;
	else if (keycode == KEY_DOWN)
		fdf->camera->vertical += 5;
	else if (keycode == KEY_LEFT)
		fdf->camera->horizon -= 5;
	else if (keycode == KEY_RIGHT)
		fdf->camera->horizon += 5;
	else if (keycode == KEY_Z)
		fdf->camera->angle.x += 3.14 / 60;
	else if (keycode == KEY_X)
		fdf->camera->angle.y += 3.14 / 60;
	else if (keycode == KEY_C)
		fdf->camera->angle.z += 3.14 / 60;
	else if (keycode == KEY_A)
		fdf->camera->angle.x -= 3.14 / 60;
	else if (keycode == KEY_S)
		fdf->camera->angle.y -= 3.14 / 60;
	else if (keycode == KEY_D)
		fdf->camera->angle.z -= 3.14 / 60;
	else if (keycode == KEY_SPACE)
	{
		fdf->camera->proj += 1;
		fdf->camera->proj %= 3;
	}
	else
		flag = 0;
	if (flag)
		draw(fdf);
	return (SUCCESS_FLAG);
}

int	mouse_press(int button, int x, int y, void *param)
{
	t_fdf	*fdf;
	int		flag;

	flag = 1;
	fdf = (t_fdf *)param;
	if (button == MOUSE_L)
		fdf->camera->mouse_l = PRESSED_L;
	else if (button == MOUSE_R)
		fdf->camera->mouse_r = PRESSED_R;
	else if (button == SCR_UP)
	{
		fdf->camera->scale *= 1.1;
	}
	else if (button == SCR_DOWN)
		fdf->camera->scale *= 0.9;
	else
		flag = 0;
	if (flag)
		draw(fdf);
	return (x + y);
}

int	mouse_release(int button, int x, int y, void *param)
{
	t_fdf	*fdf;
	int		flag;

	flag = 1;
	fdf = (t_fdf *)param;
	if (button == MOUSE_L)
		fdf->camera->mouse_l = RELEASED_L;
	else if (button == MOUSE_R)
		fdf->camera->mouse_r = RELEASED_R;
	else
		flag = 0;
	if (flag)
		draw(fdf);
	return (x + y);
}

int	mouse_move(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (fdf->camera->mouse_l == PRESSED_L)
	{
		fdf->camera->angle.y -= 3.14 / 15;
		fdf->camera->angle.z += 3.14 / 15;
		draw(fdf);
	}
	else if (fdf->camera->mouse_r == PRESSED_R)
	{
		fdf->camera->angle.y += 3.14 / 15;
		fdf->camera->angle.z -= 3.14 / 15;
		draw(fdf);
	}
	return (button + y);
}

void	hook_fdf(t_fdf *fdf)
{
	mlx_hook(fdf->prog->win_ptr, KEY_PRESS, 0, key_press, fdf);
	mlx_hook(fdf->prog->win_ptr, MOUSE_PRESS, 0, mouse_press, fdf);
	mlx_hook(fdf->prog->win_ptr, MOUSE_REL, 0, mouse_release, fdf);
	mlx_hook(fdf->prog->win_ptr, MOUSE_MOV, 0, mouse_move, fdf);
}
