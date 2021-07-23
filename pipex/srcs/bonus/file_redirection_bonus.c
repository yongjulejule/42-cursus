/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_redirection_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 09:37:24 by yongjule          #+#    #+#             */
/*   Updated: 2021/07/23 12:07:40 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/ft_pipex_bonus.h"

static void	make_tmp_heredoc(char *file, t_args *args)
{
	int		fd;
	int		size;
	char	*line;

	size = ft_strlen(args->limiter);
	fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		is_error("Error while make tmp file");
	while (1)
	{
		ft_putstr_fd("heredoc>", 1);
		get_next_line(0, &line);
		if (!ft_memcmp(args->limiter, line, size))
		{
			free(line);
			line = NULL;
			close(fd);
			return ;
		}
		ft_putendl_fd(line, fd);
		free(line);
		line = NULL;
	}
}

void	rdr_file_to_stdin(char *file, t_args *args)
{
	int			fd;
	extern int	errno;

	if (args->is_heredoc == 1)
		make_tmp_heredoc(file, args);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("zsh:", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(file, 2);
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
		is_error("dup error in rdr_file_to_stdin");
	close(fd);
	if (args->is_heredoc == 1)
		unlink(file);
	return ;
}

void	rdr_stdout_to_file(char *file, t_args *args, int *pipe_fd)
{
	int	fd;

	destroy_pipe(pipe_fd);
	if (args->is_heredoc != 1)
		fd = open(file, O_RDWR | O_TRUNC | O_CREAT, 0644);
	else
		fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
		is_error("open error in rdr_file_to_stdout");
	if (dup2(fd, STDOUT_FILENO) == -1)
		is_error("dup error in rdr_file_to_stdout");
	close(fd);
	return ;
}
