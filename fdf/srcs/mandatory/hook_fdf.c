/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:26:06 by jun               #+#    #+#             */
/*   Updated: 2021/08/20 01:39:04 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include <stdio.h>

int	key_press(int keycode, void *param)
{
	t_fdf	*fdf;
	int		flag;

	flag = 1;
	fdf = (t_fdf *)param;
	fprintf(stderr, "vert : %dhori :%d\n", fdf->carema->vertical, fdf->carema->horizon);
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_W)
		fdf->carema->vertical -= 5;
	else if (keycode == KEY_S)
		fdf->carema->vertical += 5;
	else if (keycode == KEY_A)
		fdf->carema->horizon -= 5;
	else if (keycode == KEY_D)
		fdf->carema->horizon += 5;
	else
		flag = 0;
	fprintf(stderr, "vert : %dhori :%d\n", fdf->carema->vertical, fdf->carema->horizon);
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
		fdf->carema->mouse = PRESSED_L;
	else if (button == MOUSE_R)
		fdf->carema->mouse = PRESSED_R;
	else if (button == SCR_UP)
		fdf->carema->scale += 5;
	else if (button == SCR_DOWN)
		fdf->carema->scale -= 5;
	else
		flag = 0;
	if (flag)
		draw(fdf);
	return (SUCCESS_FLAG);
}

int	mouse_release(int button, int x, int y, void *param)
{
	t_fdf	*fdf;
	int		flag;

	flag = 1;
	fdf = (t_fdf *)param;
	if (button == MOUSE_L)
		fdf->carema->mouse = RELEASED_L;
	else if (button == MOUSE_R)
		fdf->carema->mouse = RELEASED_R;
	else
		flag = 0;
	if (flag)
		draw(fdf);
	return (SUCCESS_FLAG);
}

int	mouse_move(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	fprintf(stderr, "x : %d, y : %d\n",x, y);
	fdf = (t_fdf *)param;
	if (fdf->carema->mouse == PRESSED_L)
	{
		fdf->carema->h_angle += ((double)x) * 0.0001;
		draw(fdf);
	}
	else if (fdf->carema->mouse == PRESSED_R)
	{
		fdf->carema->v_angle += ((double)x) * 0.0001;
		draw(fdf);
	}
	return (SUCCESS_FLAG);
}

void	hook_fdf(t_fdf *fdf)
{
	mlx_hook(fdf->prog->win_ptr, KEY_PRESS, 0, key_press, fdf);
	mlx_hook(fdf->prog->win_ptr, MOUSE_PRESS, 0, mouse_press, fdf);
	mlx_hook(fdf->prog->win_ptr, MOUSE_REL, 0, mouse_release, fdf);
	mlx_hook(fdf->prog->win_ptr, MOUSE_MOV, 0, mouse_move, fdf);
}
