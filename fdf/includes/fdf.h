/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 09:11:23 by jun               #+#    #+#             */
/*   Updated: 2021/08/18 00:47:55 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// FIXME
# include <sys/resource.h>
# include <stdio.h>

# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <sys/errno.h>
# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include "get_next_line_bonus.h"

# define LIMIT_VALUE 960000000

typedef struct	s_data{
	int	x;
	int	y;
	int	max_x;
	int	max_y;
	int	**data[2];
}	t_data;

typedef struct	s_program{
	int	*mlx_ptr;
	int	*win_ptr;
}	t_program;

typedef	struct	s_vec{
	double x;
	double y;
	double z;
}	t_vec;

/* TODO : Need to make IMG structure*/
typedef struct	s_fdf{
	t_program	*prog;
	t_vec		vec;
	t_data		*data;
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

t_vec	iso_proj(t_vec vec);

/* draw_line */

void	plot(void *mlx_ptr, void * win_ptr, int x, int y, int color);
double	ipart(double x);
double	fpart(double x);
double	rfpart(double x);
void	swap(double *x, double *y);
void	drawline(void *mlx_ptr, void *win_ptr, double x0, double x1, double y0, double y1, int color);
#endif
