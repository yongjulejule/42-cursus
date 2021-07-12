/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breed_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:40:45 by jun               #+#    #+#             */
/*   Updated: 2021/07/12 20:31:56 by jun              ###   ########.fr       */
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
void	breed_process(t_args *args)
{
	pid_t pid;
	int	pipe_fd[2];
	int	status;

	if (pipe(pipe_fd) == -1)
	{
		perror("Fail to Open PIPE");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == 0)
	{
		rdr_file_to_stdin(args->file[0]);
		connect_pipe_fd(pipe_fd, STDOUT_FILENO);
		execve(args->cmd_w_params[0][0], args->cmd_w_params[0], NULL);
	}
	else if (pid > 0)
	{
		wait(&status);
		if (WIFSIGNALED(status))
		{
			perror("dd");
			exit(EXIT_FAILURE);
		}
		rdr_stdout_to_file(args->file[1]);
		connect_pipe_fd(pipe_fd, STDIN_FILENO);
		execve(args->cmd_w_params[1][0], args->cmd_w_params[1], NULL);
	}
	else
	{
		perror("Fail to fork");
		exit(EXIT_FAILURE);
	}
}

