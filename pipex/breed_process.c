/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breed_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:40:45 by jun               #+#    #+#             */
/*   Updated: 2021/07/11 13:34:50 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	connect_pipe_fd(int *pipe_fd, int pipe_status)
{
	if (dup2(pipe_fd[pipe_status], pipe_status) == -1)
	{
		perror("Error while connecting pipe");
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[PIPE_RD]);
	close(pipe_fd[PIPE_WR]);
}

void	breed_process(char **file, t_args *cmd)
{
	pid_t pid;
	int	pipe_fd[2];

	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
	{
		rdr_file_to_stdin(file[0]);
		connect_pipe_fd(pipe_fd, STDOUT_FILENO);
		execve("/bin/cat", NULL, NULL);
	}
	else if (pid > 0)
	{
		wait(&status);
		if (WIFSIGNALED(status))
		{
			perror("dd");
			exit(EXIT_FAILURE);
		}
		rdr_stdout_to_file(file[1]);
		connect_pipe_fd(pipe_fd, STDIN_FILENO);
		execve("/usr/bin/wc", NULL, NULL);
	}
	else
	{
		perror("Fail to fork");
		exit(EXIT_FAILURE);
	}
}
