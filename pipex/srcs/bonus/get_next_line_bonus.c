/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 16:24:58 by yongjule          #+#    #+#             */
/*   Updated: 2021/07/22 18:37:20 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/ft_pipex_bonus.h"

static	int	get_line(t_file **cur, char **line, int size, int flag)
{
	int	len;

	if (flag != NOT_ALLOCED)
	{
		free(*line);
		*line = NULL;
	}
	len = (*cur)->nl - 1;
	while (++len < (*cur)->size)
	{
		if (*((*cur)->text + len) == '\n')
		{
			*line = mysubstr((*cur)->text, (*cur)->nl, len - (*cur)->nl);
			(*cur)->nl = ++len;
			return (1);
		}
	}
	if (size < BUFFER_SIZE && len == (*cur)->size)
	{
		*line = mysubstr((*cur)->text, (*cur)->nl, len - (*cur)->nl);
		return (0);
	}
	return (flag);
}

static int	read_fd(int fd, t_file *cur)
{
	int	size;

	size = read(fd, (cur->text + cur->size), BUFFER_SIZE);
	if (size == 0)
		return (0);
	cur->size += size;
	if (size == -1 || !re_alloc(cur, cur->size + BUFFER_SIZE))
		is_error("error while read");
	return (size);
}

int	get_next_line(int fd, char **line)
{
	static t_file	*root;
	t_file			*cur;
	int				flag;
	int				size;

	flag = NOT_ALLOCED;
	if (!root)
		root = init_fd(fd);
	if (BUFFER_SIZE < 1 || !line)
		is_error("check get_next_line arguments");
	cur = root;
	while (1)
	{
		size = read_fd(fd, cur);
		if (size == 0)
			break ;
		flag = get_line(&cur, line, size, flag);
		if (flag == 1)
			return (flag);
	}
	if (flag != -1)
		flag = get_line(&cur, line, size, flag);
	if (flag != 1)
		free_lst(&root, &cur, line, flag);
	return (flag);
}
