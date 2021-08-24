/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 09:11:23 by jun               #+#    #+#             */
/*   Updated: 2021/08/24 13:52:34 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <sys/errno.h>
# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include "get_next_line_bonus.h"

# define LIMIT_VALUE 960000000
# define WIN_H 900
# define WIN_W 1600
# define T_W 360
# define T_H 200
# define PI 3.1415

# define KEY_PRESS 2
# define KEY_REL 3
# define MOUSE_PRESS 4
# define MOUSE_REL 5
# define MOUSE_MOV 6
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_ESC 53
# define KEY_SPACE 49
# define MOUSE_L 1
# define MOUSE_R 2
# define SCR_UP 4
# define SCR_DOWN 5
# define PRESSED_L 1
# define RELEASED_L 0
# define PRESSED_R 3
# define RELEASED_R 2
# define ISO 0
# define PALL 1

typedef struct s_data{
	int	x;
	int	y;
	int	max_x;
	int	max_y;
	int	**data[2];
}	t_data;

typedef struct s_program{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_program;

typedef struct s_vec{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef struct s_img{
	int		size_l;
	int		bpp;
	int		endian;
	int		*data;
	void	*img_ptr;
}	t_img;

typedef struct s_camera{
	int		proj;
	int		mouse_r;
	int		mouse_l;
	double	horizon;
	double	vertical;
	double	scale;
	t_vec	angle;
}	t_camera;

typedef struct s_line_info{
	int		steep;
	double	gradient;
	double	intery;
	t_vec	vec_0;
	t_vec	vec_1;
}	t_line_info;

typedef struct s_fdf{
	int			color[2];
	t_program	*prog;
	t_data		*data;
	t_img		*img;
	t_img		*background;
	t_camera	*camera;
	t_vec		(*proj_func)(struct s_fdf *, t_vec);
}	t_fdf;

int					ft_atoi_basis(const char *str);
unsigned long long	hexa_to_int(const char *str);
unsigned long long	bi_to_int(const char *str);
unsigned long long	oct_to_int(const char *str);
t_data				*get_data(char **argv);
char				**read_file(char **argv);

/* mlx */

t_fdf				*mlx_main(t_data *data);
void				draw_wireframe(t_fdf *fdf);

/* Isometric Projection */

t_vec				iso_proj(t_fdf *fdf, t_vec vec);

/* draw_line */

void				plot(t_fdf *fdf, int x, int y, int color);
double				ipart(double x);
double				fpart(double x);
double				rfpart(double x);
void				swap(double *x, double *y);
void				drawline(t_fdf *fdf, t_vec vec_0, t_vec vec_1);
void				swap_i(int *x, int *y);

void				hook_fdf(t_fdf *fdf);
t_vec				get_center(t_fdf *fdf);
void				draw(t_fdf *fdf);
t_vec				parallel(t_fdf *fdf, t_vec vec);
int					rasterized_color(int *color, double percent);
double				percentage(double start, double cur, double end);
void				init_img_structure(t_fdf *fdf);
void				description_fdf(t_fdf *fdf);
int					mouse_press(int button, int x, int y, void *param);
int					mouse_release(int button, int x, int y, void *param);
int					mouse_move(int button, int x, int y, void *param);
#endif
