/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:26:06 by jun               #+#    #+#             */
/*   Updated: 2021/08/24 23:39:01 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_press(int keycode, void *param)
{
	t_fdf	*fdf;
	int		flag;

	flag = 0;
	fdf = (t_fdf *)param;
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (SUCCESS_FLAG);
}

int	close_window(void *param)
{
	t_fdf	*fdf;

	fdf = param;
	exit(EXIT_SUCCESS);
}

void	hook_fdf(t_fdf *fdf)
{
	mlx_hook(fdf->prog->win_ptr, KEY_PRESS, 0, key_press, fdf);
	mlx_hook(fdf->prog->win_ptr, RED_DOT, 0, close_window, fdf);
}
