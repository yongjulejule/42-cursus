/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:31:23 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/17 12:48:48 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_file	*init_fd(int fd)
{
	t_file *newnode;

	if (!(newnode = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	newnode->text = (char*)malloc(BUFFER_SIZE + 1);
	if (!newnode->text)
	{
		free(newnode);
		return (NULL);
	}
	newnode->fd = fd;
	newnode->nl = 0;
	newnode->next = NULL;
	newnode->size = 0;
	return (newnode);
}

int		free_lst(t_file **root, t_file **cur, char **line, int flag)
{
	if (flag != NOT_ALLOCED && !(*line))
	{
		free(*line);
		*line = NULL;
	}
	free((*root)->text);
	(*root)->text = NULL;
	free(*root);
	*root = NULL;
	*cur = NULL;
	return (flag);
}

int		re_alloc(t_file *cur, int size)
{
	char	*tmp;
	int		idx;

	idx = 0;
	if (!(tmp = (char*)malloc(size + 1)))
		return (ERROR_FLAG);
	while (idx < cur->size)
	{
		*(tmp + idx) = *(cur->text + idx);
		idx++;
	}
	*(tmp + idx) = '\0';
	free(cur->text);
	cur->text = tmp;
	return (SUCCESS_FLAG);
}

char	*mysubstr(char *s, int nl, int len)
{
	char	*substr;
	int		idx;

	idx = 0;
	if (!(substr = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (idx < len)
	{
		*(substr + idx) = *(s + nl + idx);
		idx++;
	}
	*(substr + idx) = '\0';
	return (substr);
}
