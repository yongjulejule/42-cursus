/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 12:35:44 by jun               #+#    #+#             */
/*   Updated: 2021/08/07 14:47:48 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_data	*get_data(char **argv)
{
	t_data	*data;
	char	**file;

	file = read_file(argv);
	data = (t_data*)ft_calloc(1, sizeof(t_data));
//	get_coord(data);
//	get_color(data);
	return NULL;
}
