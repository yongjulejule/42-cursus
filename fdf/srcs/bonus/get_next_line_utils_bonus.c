/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:31:23 by yongjule          #+#    #+#             */
/*   Updated: 2021/08/24 21:16:56 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_file	*init_fd(int fd)
{
	t_file	*newnode;

	newnode = (t_file *)ft_calloc(sizeof(t_file), 1);
	newnode->text = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	newnode->fd = fd;
	newnode->nl = 0;
	newnode->next = NULL;
	newnode->size = 0;
	return (newnode);
}

int	free_lst(t_file **root, t_file **cur, char **line, int flag)
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

int	re_alloc(t_file *cur, int size)
{
	char	*tmp;
	int		idx;

	idx = 0;
	tmp = (char *)malloc(size + 1);
	if (!tmp)
		is_error("Error during malloc");
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
	substr = (char *)ft_calloc(len + 1, sizeof(char));
	while (idx < len)
	{
		*(substr + idx) = *(s + nl + idx);
		idx++;
	}
	*(substr + idx) = '\0';
	return (substr);
}
