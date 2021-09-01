/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 09:37:24 by yongjule          #+#    #+#             */
/*   Updated: 2021/09/01 16:46:05 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/ft_pipex.h"

void	destory_pipe(int *pipe_fd)
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}

void	rdr_file_to_stdin(char *file)
{
	int			fd;
	extern int	errno;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("zsh: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		is_error(": ", file, EXIT_FAILURE);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
		is_error("pipex: ", strerror(errno), EXIT_FAILURE);
	close(fd);
	return ;
}

void	rdr_stdout_to_file(char *file)
{
	int	fd;

	fd = open(file, O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		is_error("pipex: ", strerror(errno), EXIT_FAILURE);
	if (dup2(fd, STDOUT_FILENO) == -1)
		is_error("pipex: ", strerror(errno), EXIT_FAILURE);
	close(fd);
	return ;
}
