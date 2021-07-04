/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:31:23 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/17 17:08:12 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

int		find_fd(t_file **root, t_file **cur, char **line, int fd)
{
	t_file	*head;

	head = *root;
	*cur = *root;
	if ((*cur)->fd == fd)
		return (SUCCESS_FLAG);
	*cur = (*cur)->next;
	while (*cur)
	{
		if ((*cur)->fd == fd)
		{
			(*root)->next = *cur;
			return (SUCCESS_FLAG);
		}
		*cur = (*cur)->next;
		*root = (*root)->next;
	}
	if (!((*cur) = init_fd(fd)))
	{
		free_lst(root, cur, line, -1);
		return (ERROR_FLAG);
	}
	(*root)->next = *cur;
	*root = head;
	return (SUCCESS_FLAG);
}

int		free_lst(t_file **root, t_file **cur, char **line, int flag)
{
	t_file *head;

	head = *root;
	if (flag != NOT_ALLOCED && !(*line))
	{
		free(*line);
		*line = NULL;
	}
	if ((*root)->next != NULL && (*root) != *cur)
		while ((*root)->next != *cur)
			(*root) = (*root)->next;
	(*root)->next = (*cur)->next;
	free((*cur)->text);
	(*cur)->text = NULL;
	if ((head)->next == NULL && (head)->text == NULL)
	{
		if (head != *cur)
			free(*cur);
		*root = head->next;
		free(head);
		*root = NULL;
	}
	else
	{
		if (*cur != head)
			free(*cur);
	}
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
