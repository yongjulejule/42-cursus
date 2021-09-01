/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breed_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:40:45 by jun               #+#    #+#             */
/*   Updated: 2021/09/01 22:25:21 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/ft_pipex_bonus.h"

static int	wait_process(t_args *args, int *pipe_prv, int cmd)
{
	int		status;
	int		exit_code;
	pid_t	execed_pid;

	execed_pid = 0;
	while (execed_pid != -1)
	{
		execed_pid = wait(&status);
		if (execed_pid == args->pid[cmd - 1])
			close(pipe_prv[1]);
		else if (execed_pid == args->pid[cmd])
			close(pipe_prv[0]);
		if (execed_pid == args->pid[args->argc - 4])
		{
			if (wifexited(status))
				exit_code = wexitstatus(status);
			else if (wifsignaled(status))
				exit_code = wtermsig(status);
			else
				exit_code = EXIT_FAILURE;
		}
	}
	return (exit_code);
}

static void	parent_process(t_args *args, int *pipe_prv, int cmd)
{
	pid_t	pid;
	int		pipe_new[2];
	int		status;
	extern int	errno;

	if (pipe(pipe_new) == -1)
		is_error("pipex: ", strerror(errno), EXIT_FAILURE);
	pid = fork();
	args->pid[cmd] = pid;
	if (pid == 0)
	{
		if (cmd != args->argc - 4)
			connect_pipe_fd(pipe_new, STDOUT_FILENO);
		else
			rdr_stdout_to_file(args->file[1], args, pipe_new);
		connect_pipe_fd(pipe_prv, STDIN_FILENO);
		execve(args->params[cmd][0], args->params[cmd], args->envp);
	}
	else if (pid > 0)
	{
		status = wait_process(args, pipe_prv, cmd);
		if (cmd == args->argc - 4)
		{
			destroy_pipe(pipe_new);
			exit(status);
		}
		parent_process(args, pipe_new, ++cmd);
	}
	else
		is_error("pipex: ", strerror(errno), EXIT_FAILURE);
}

static void	grand_child(t_args *args)
{
	int		pipe_cur[2];
	pid_t	pid;
	extern int	errno;

	if (pipe(pipe_cur) == -1)
		is_error("pipex: ", strerror(errno), EXIT_FAILURE);
	pid = fork();
	args->pid[0] = pid;
	if (pid == 0)
	{
		rdr_file_to_stdin(args->file[0], args);
		connect_pipe_fd(pipe_cur, STDOUT_FILENO);
		execve(args->params[0][0], args->params[0], args->envp);
	}
	else if (pid > 0)
		parent_process(args, pipe_cur, 1);
	else
		is_error("pipex: ", strerror(errno), EXIT_FAILURE);
}

void	breed_process_recursively(t_args *args)
{
	int			status;
	pid_t		pid;
	extern int	errno;

	if (args->is_heredoc == 1)
		args->argc--;
	args->pid = (pid_t *)ft_calloc_w_error(args->argc - 3, sizeof(pid_t));
	pid = fork();
	if (pid == 0)
		grand_child(args);
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (wifexited(status))
			exit(wexitstatus(status));
		else
			exit(EXIT_FAILURE);
	}
	else
		is_error("pipex: ", strerror(errno), EXIT_FAILURE);
}
