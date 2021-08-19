/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 09:11:23 by jun               #+#    #+#             */
/*   Updated: 2021/08/19 20:14:25 by jun              ###   ########.fr       */
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
# define T_W 320
# define T_H 120
# define PI 3.1415

typedef struct	s_data{
	int	x;
	int	y;
	int	max_x;
	int	max_y;
	int	**data[2];
}	t_data;

typedef struct	s_program{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_program;

typedef	struct	s_vec{
	double x;
	double y;
	double z;
}	t_vec;

typedef struct	s_img{
	int		size_l;
	int		bpp;
	int		endian;
	int		*data;
	void	*img_ptr;
}	t_img;

typedef struct	s_carema{
	int		scale;
	int		horizon;
	int		vertical;
	double	h_angle;
	double	v_angle;
}	t_carema;

/* TODO : Need to make IMG structure*/
typedef struct	s_fdf{
	t_program	*prog;
	t_data		*data;
	t_img		*img;
	t_carema	*carema;
	t_vec		vec;
}	t_fdf;

int					ft_atoi_basis(const char *str);
unsigned long long	hexa_to_int(const char *str);
unsigned long long	bi_to_int(const char *str);
unsigned long long	oct_to_int(const char *str);
t_data				*get_data(char **argv);
char				**read_file(char **argv);

/* mlx */

void	mlx_main(t_data *data);
void	draw_wireframe(t_fdf *fdf);

/* Isometric Projection */

t_vec	iso_proj(t_fdf *fdf, t_vec vec);

/* draw_line */

void	plot(t_fdf *fdf, void *mlx_ptr, void * win_ptr, int x, int y, double brightness, int color);
double	ipart(double x);
double	fpart(double x);
double	rfpart(double x);
void	swap(double *x, double *y);
void	drawline(t_fdf *fdf, t_vec vec_0, t_vec vec_1, int *color);
void	swap_i(int *x, int *y);
#endif
