/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breed_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:40:45 by jun               #+#    #+#             */
/*   Updated: 2021/07/22 17:43:41 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/ft_pipex_bonus.h"

void	connect_pipe_fd(int *pipe_fd, int pipe_status)
{
	if (dup2(pipe_fd[pipe_status], pipe_status) == -1)
		is_error("Error while connecting pipe");
	close(pipe_fd[PIPE_RD]);
	close(pipe_fd[PIPE_WR]);
}

void	grand_parent(t_args *args, int *pipe_last, int cmd)
{
	int	status;

	wait(&status);
	if (!WIFEXITED(status))
		is_error("child process exited unexpectedly");
	rdr_stdout_to_file(args->file[1]);
	connect_pipe_fd(pipe_last, STDIN_FILENO);
	execve(args->params[cmd][0], args->params[cmd], NULL);
}

void	parent_process(t_args *args, int *pipe_prv, int cmd)
{
	pid_t	pid;
	int		pipe_new[2];

	if (pipe(pipe_new) == -1)
		is_error("Error while open pipe");
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
		is_error("Error while breed process");
}

void	grand_child(t_args *args, int *pipe_1st)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		write(1,"a",1);
		rdr_file_to_stdin(args->file[0]);
		connect_pipe_fd(pipe_1st, STDOUT_FILENO);
		execve(args->params[0][0], args->params[0], NULL);
	}
	else if (pid > 0)
	{
		wait(&status);
		if (!WIFEXITED(status))
			is_error("child process exited unexpectedly");
		parent_process(args, pipe_1st, 1);
	}
	else
		is_error("Error while breed process");
}

void	breed_process_recursively(t_args *args)
{
	int		pipe_prv[2];
	int		status;
	pid_t	pid;

	if (pipe(pipe_prv) == -1)
		is_error("Error while open pipe");
	pid = fork();
	if (pid == 0)
		grand_child(args, pipe_prv);
	else if (pid > 0)
	{
		wait(&status);
		if (!WIFEXITED(status))
			is_error("child process exited unexpectedly");
		exit(EXIT_SUCCESS);
	}
	else
		is_error("Error while breed process");
}
