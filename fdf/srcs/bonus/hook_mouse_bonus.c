/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:40:44 by jun               #+#    #+#             */
/*   Updated: 2021/09/06 19:05:27 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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
	{
		mlx_clear_window(fdf->prog->mlx_ptr, fdf->prog->win_ptr);
		draw(fdf);
	}
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
	{
		mlx_clear_window(fdf->prog->mlx_ptr, fdf->prog->win_ptr);
		draw(fdf);
	}
	return (x + y);
}

int	close_window(void *param)
{
	t_fdf	*fdf;

	fdf = param;
	exit(EXIT_SUCCESS);
}

int	mouse_move(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (fdf->camera->mouse_l == PRESSED_L && fdf->camera->proj != PALL)
	{
		fdf->camera->angle.y -= PI / 15;
		fdf->camera->angle.z += PI / 15;
		draw(fdf);
	}
	else if (fdf->camera->mouse_r == PRESSED_R && fdf->camera->proj != PALL)
	{
		fdf->camera->angle.y += PI / 15;
		fdf->camera->angle.z -= PI / 15;
		mlx_clear_window(fdf->prog->mlx_ptr, fdf->prog->win_ptr);
		draw(fdf);
	}
	return (button + y + x);
}
