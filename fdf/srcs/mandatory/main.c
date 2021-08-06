/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:09:09 by jun               #+#    #+#             */
/*   Updated: 2021/08/06 10:28:01 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include <stdlib.h>

#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_RELEASE 3
#define X_EVENT_KEY_EXIT 17

#define KEY_ESC 53
#define KEY_Q 12
#define KEY_W 13
#define KEY_E 14
#define KEY_R 15
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#include <stdio.h>

typedef struct s_param{
	int	x;
	int y;
	char str[3];
}t_param;

void	param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
	param->str[0] = 'a';
	param->str[1] = 'b';
	param->str[2] = '\0';
}

int	key_press(int keycode, t_param *param)
{
	if (keycode == KEY_W)
		param->x++;
	else if (keycode == KEY_S)
		param->x--;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("x: %d\n", param->x);
	return (0);
}

int main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_param	param;

	argc = 0;
	argv = 0;
	param_init(&param);
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		exit(EXIT_FAILURE);
	win_ptr = mlx_new_window(mlx_ptr, 1200, 800, "first_window");
	if (win_ptr == NULL)
		exit(EXIT_FAILURE);
	printf("-------------------------------\n");
	printf("'W key': Add 1 to x.\n");
	printf("'S key': Subtract 1 from x\n");
	printf("'ESC key': Exit this program\n");
	printf("'Other keys': print current x \n");
	printf("-------------------------------\n");
	printf("Current x = 3\n"); 
	mlx_hook(win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &param);
	int x = 0;
	int y = 0;

	while (1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00ffff);
		x++;
		y++;
		if (x == 500 || y == 500)
			break ;
	}
	mlx_string_put(mlx_ptr, win_ptr, 250, 250, 0x0000ff, "WTF IS THIS?");
	mlx_loop(mlx_ptr);
}
