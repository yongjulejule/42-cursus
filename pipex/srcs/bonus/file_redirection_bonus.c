/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_redirection_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 09:37:24 by yongjule          #+#    #+#             */
/*   Updated: 2021/07/13 15:18:57 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/ft_pipex_bonus.h"

void	rdr_file_to_stdin(char *file)
{
	int			fd;
	extern int	errno;

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
	{
		perror("dup error in rdr_file_to_stdin");
		exit(EXIT_FAILURE);
	}
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
