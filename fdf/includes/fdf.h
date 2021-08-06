/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 09:11:23 by jun               #+#    #+#             */
/*   Updated: 2021/08/06 17:44:05 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <sys/resource.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
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

unsigned long long	hexa_to_int(const char *str);
unsigned long long	bi_to_int(const char *str);
unsigned long long	oct_to_int(const char *str);
#endif