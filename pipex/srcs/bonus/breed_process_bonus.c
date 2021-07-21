/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breed_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:40:45 by jun               #+#    #+#             */
/*   Updated: 2021/07/21 14:30:47 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/ft_pipex_bonus.h"

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

void	grand_parent(t_args *args, int *pipe_last, int cmd)
{
	wait(NULL);
	rdr_stdout_to_file(args->file[1]);
	connect_pipe_fd(pipe_last, STDIN_FILENO);
	execve(args->params[args->argc - 4][0], args->params[args->argc - 4], NULL);
}

void	parent_process(t_args *args, int *pipe_prv, int cmd)
{
	pid_t	pid;
	int	pipe_new[2];

	if (pipe(pipe_new) == -1)
	{
		perror("Error while open pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == 0)
	{
		connect_pipe_fd(pipe_prv, STDIN_FILENO);
		connect_pipe_fd(pipe_new, STDOUT_FILENO);
		execve(args->params[cmd][0], args->params[cmd], NULL);
	}
	else if (pid > 0)
	{
		if (cmd == args->argc - 5)
			grand_parent(args, pipe_new, cmd + 1);
		parent_process(args, pipe_new, ++cmd);
	}
	else
	{
		perror("Error while breed process");
		exit(EXIT_FAILURE);
	}
}

void	grand_child(t_args *args, int *pipe_1st)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		rdr_file_to_stdin(args->file[0]);
		connect_pipe_fd(pipe_1st, STDOUT_FILENO);
		execve(args->params[0][0], args->params[0], NULL);
	}
	else if (pid > 0)
	{
		wait(NULL);
		parent_process(args, pipe_1st, 1);
	}
	else
	{
		perror("Error while breed process");
		exit(EXIT_FAILURE);
	}
}

void	breed_process_recursively(t_args *args, int cmd)
{
	int	pipe_prv[2];
	pid_t	pid;

	if (pipe(pipe_prv) == -1)
	{
		perror("Error while open pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == 0)
		grand_child(args, pipe_prv);
	else if (pid > 0)
	{
		wait(NULL);
		exit(EXIT_SUCCESS);
	}
	else
	{
		perror("Error while breed process");
		exit(EXIT_FAILURE);
	}
}
