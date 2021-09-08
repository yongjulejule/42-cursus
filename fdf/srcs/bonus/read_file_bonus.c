/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 13:29:42 by jun               #+#    #+#             */
/*   Updated: 2021/09/08 10:33:57 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static char	**lst_to_arr(t_list *lines)
{
	int			idx;
	char		**tmp;
	t_list		*backup;
	extern int	errno;

	idx = 0;
	backup = lines;
	tmp = (char **)ft_calloc(ft_lstsize(lines) + 1, sizeof(char *));
	while (lines)
	{
		tmp[idx] = ft_strdup(lines->content);
		if (tmp[idx] == NULL)
			is_error(strerror(errno));
		idx++;
		lines = lines->next;
	}
	ft_lstclear(&backup, free);
	return (tmp);
}

static char	**line_to_arr(int fd)
{
	char	*line;
	t_list	*lines;

	get_next_line(fd, &line);
	lines = ft_lstnew(line);
	while (get_next_line(fd, &line) > 0)
		ft_lstadd_back(&lines, ft_lstnew(line));
	free(line);
	line = NULL;
	close(fd);
	return (lst_to_arr(lines));
}

char	**read_file(char **argv)
{
	int			fd;
	extern int	errno;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		is_error(strerror(errno));
	return (line_to_arr(fd));
}
