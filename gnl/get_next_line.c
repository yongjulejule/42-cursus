/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 16:24:58 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/18 09:58:45 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (BUFFER_SIZE < 1 || !line || (!root && !(root = init_fd(fd))))
		return (-1);
	cur = root;
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
