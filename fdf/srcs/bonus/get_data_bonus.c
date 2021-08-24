/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 12:35:44 by jun               #+#    #+#             */
/*   Updated: 2021/08/24 21:16:55 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	free_double_ptr(char **strs)
{
	int	idx;

	idx = 0;
	while (strs[idx])
	{
		free(strs[idx]);
		idx++;
	}
	free(strs);
}

static void	put_data(t_data *data, char **nbrs)
{
	int			row;
	static int	col = 0;
	char		*color;

	row = 0;
	while (*nbrs)
	{
		data->data[0][col][row] = ft_atoi_basis(*nbrs);
		color = ft_strrchr(*nbrs, ',');
		if (!color)
			ft_strrchr(*nbrs, '.');
		if (color != NULL)
			data->data[1][col][row] = ft_atoi_basis(&color[1]);
		else
			data->data[1][col][row] = 0xFFFFFF;
		nbrs++;
		row++;
	}
	col++;
}

static void	convert_str_data_to_int_arr(t_data *data, char **file)
{
	char	**nbrs;

	while (*file)
	{
		nbrs = ft_split_charset(*file, "\t\r\n\f\v ");
		if (nbrs)
		{
			if (data->max_x != ft_strsetlen(nbrs))
				is_error("Found wrong line length. Check your file!");
			put_data(data, nbrs);
			free_double_ptr(nbrs);
			nbrs = NULL;
		}
		else
			break ;
		file++;
	}
}

static void	init_t_data(t_data *data, char **file)
{
	char	**tmp;
	int		idx;
	int		col;

	idx = 0;
	tmp = ft_split_charset(*file, "\r\t\v\f\n ");
	data->x = 0;
	data->y = 0;
	data->max_x = ft_strsetlen(tmp);
	data->max_y = ft_strsetlen(file);
	while (idx < 2)
	{
		col = 0;
		data->data[idx] = (int **)ft_calloc(data->max_y, sizeof(int *));
		while (col < data->max_y)
		{
			data->data[idx][col] = (int *)ft_calloc(data->max_x, sizeof(int));
			col++;
		}
		idx++;
	}
	free_double_ptr(tmp);
	tmp = NULL;
}

t_data	*get_data(char **argv)
{
	t_data	*data;
	char	**file;

	file = read_file(argv);
	data = (t_data *)ft_calloc(1, sizeof(t_data));
	init_t_data(data, file);
	convert_str_data_to_int_arr(data, file);
	free_double_ptr(file);
	file = NULL;
	return (data);
}
