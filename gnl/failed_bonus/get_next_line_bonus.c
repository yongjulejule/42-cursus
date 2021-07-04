/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 17:23:25 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/19 14:51:00 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	int	get_line(t_file **cur, char **line, int size, int flag)
{
	int len;

	if (flag != NOT_ALLOCED)
	{
		free(*line);
		*line = NULL;
	}
	len = (*cur)->nl - 1;
	while (++len < (*cur)->size)
		if (*((*cur)->text + len) == '\n')
		{
			if (!(*line = mysubstr((*cur)->text, (*cur)->nl, len - (*cur)->nl)))
				return (-1);
			(*cur)->nl = ++len;
			return (1);
		}
	if (size < BUFFER_SIZE && len == (*cur)->size)
	{
		if (!(*line = mysubstr((*cur)->text, (*cur)->nl, len - (*cur)->nl)))
			return (-1);
		return (0);
	}
	return (flag);
}

int			get_next_line(int fd, char **line)
{
	static t_file	*root;
	t_file			*cur;
	int				flag;
	int				size;

	flag = NOT_ALLOCED;
	if (fd < 0 || fd > 256 || BUFFER_SIZE < 1 || !line || (!root && !(root = init_fd(fd)))
			|| !(find_fd(&root, &cur, line, fd)))
		return (-1);
	while ((size = read(fd, (cur->text + cur->size), BUFFER_SIZE)) != 0)
	{
		cur->size += size;
		if (size == -1 || !re_alloc(cur, cur->size + BUFFER_SIZE))
			return (free_lst(&root, &cur, line, -1));
		if ((flag = get_line(&cur, line, size, flag)) == 1)
			return (flag);
		else if (flag == -1)
			break ;
	}
	if (flag != -1)
		flag = get_line(&cur, line, size, flag);
	if (flag != 1)
		free_lst(&root, &cur, line, flag);
	return (flag);
}
