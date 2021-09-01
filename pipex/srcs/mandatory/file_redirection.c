/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 09:37:24 by yongjule          #+#    #+#             */
/*   Updated: 2021/09/01 12:34:48 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/ft_pipex.h"

void	rdr_file_to_stdin(char *file)
{
	int			fd;
	extern int	errno;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		is_error("zsh: no such file or directory : ", file, EXIT_FAILURE);
	if (dup2(fd, STDIN_FILENO) == -1)
		is_error("pipex: ", "error while dup file descriptor", EXIT_FAILURE);
	close(fd);
	return ;
}

void	rdr_stdout_to_file(char *file)
{
	int	fd;

	fd = open(file, O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
	{
		perror("open error in rdr_file_to_stdout");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("dup error in rdr_file_to_stdout");
		exit(EXIT_FAILURE);
	}
	close(fd);
	return ;
}
