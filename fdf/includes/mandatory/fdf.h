/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 09:11:23 by jun               #+#    #+#             */
/*   Updated: 2021/09/08 10:54:48 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <sys/errno.h>
# include "../../lib/libft/libft.h"
# include "../../lib/mlx/mlx.h"
# include "get_next_line_bonus.h"

/*
** My define
*/

# define LIMIT_VALUE 960000000
# define WIN_W 1600
# define WIN_H 900
# define KEY_PRESS 2
# define KEY_ESC 53
# define RED_DOT 17
# define ISO 0

/*
** Structure
*/

typedef struct s_data{
	int	x;
	int	y;
	int	max_x;
	int	max_y;
	int	max_z;
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
	double	horizon;
	double	vertical;
	double	scale;
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

/*
** Get data
*/

int					ft_atoi_basis(const char *str);
unsigned long long	hexa_to_int(const char *str);
unsigned long long	bi_to_int(const char *str);
unsigned long long	oct_to_int(const char *str);
t_data				*get_data(char **argv);
char				**read_file(char **argv);

/*
** MLX lib
*/

t_fdf				*mlx_main(t_data *data);
void				init_img_structure(t_fdf *fdf);

/*
** Projection
*/

t_vec				iso_proj(t_fdf *fdf, t_vec vec);

/*
** Draw
*/

void				draw_wireframe(t_fdf *fdf);
void				plot(t_fdf *fdf, int x, int y, int color);
void				swap(double *x, double *y);
void				drawline(t_fdf *fdf, t_vec vec_0, t_vec vec_1);
void				swap_i(int *x, int *y);
void				draw(t_fdf *fdf);
int					rasterized_color(int *color, double percent);
double				percentage(double start, double cur, double end);
void				hook_fdf(t_fdf *fdf);
#endif
