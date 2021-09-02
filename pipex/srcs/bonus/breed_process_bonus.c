/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breed_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:40:45 by jun               #+#    #+#             */
/*   Updated: 2021/09/02 11:40:36 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/ft_pipex_bonus.h"

static void	wait_process(t_args *args)
{
	int		status;
	int		exit_code;
	int		cmd;
	pid_t	execed_pid;

	execed_pid = 0;
	while (execed_pid != -1)
	{
		cmd = 1;
		while (cmd < args->argc - 3)
		{
			execed_pid = wait(&status);
			if (execed_pid == args->pid[cmd - 1])
				close(args->pipe_fd[cmd-1][1]);
			else if (execed_pid == args->pid[cmd])
				close(args->pipe_fd[cmd-1][0]);
			if (execed_pid == args->pid[args->argc - 4])
			{
				if (wifexited(status))
					exit_code = wexitstatus(status);
				else if (wifsignaled(status))
					exit_code = wtermsig(status);
				else
					exit_code = EXIT_FAILURE;
			}
			cmd++;
		}
	}
	while(1);
	exit(exit_code);
}

static void	parent_process(t_args *args, int cmd)
{
	pid_t	pid;
	extern int	errno;

	if (args->argc - 4 != cmd)
		if (pipe(args->pipe_fd[cmd]) == -1)
			is_error("pipex: ", strerror(errno), EXIT_FAILURE);
	pid = fork();
	args->pid[cmd] = pid;
	if (pid == 0)
	{
		if (cmd != args->argc - 4)
			connect_pipe_fd(args->pipe_fd[cmd], STDOUT_FILENO);
		else
			rdr_stdout_to_file(args->file[1], args, args->pipe_fd[cmd]);
		connect_pipe_fd(args->pipe_fd[cmd - 1], STDIN_FILENO);
		execve(args->params[cmd][0], args->params[cmd], args->envp);
	}
	else if (pid > 0)
	{
		if (cmd == args->argc - 4)
		{
			wait_process(args);
//			destroy_pipe(args->pipe_fd[cmd]);
//			exit(status);
		}
		parent_process(args, ++cmd);
	}
	else
		is_error("pipex: ", strerror(errno), EXIT_FAILURE);
}

static void	grand_child(t_args *args)
{
	pid_t	pid;
	extern int	errno;

	if (pipe(args->pipe_fd[0]) == -1)
		is_error("pipex: ", strerror(errno), EXIT_FAILURE);
	pid = fork();
	args->pid[0] = pid;
	if (pid == 0)
	{
		rdr_file_to_stdin(args->file[0], args);
		connect_pipe_fd(args->pipe_fd[0], STDOUT_FILENO);
		execve(args->params[0][0], args->params[0], args->envp);
	}
	else if (pid > 0)
		parent_process(args, 1);
	else
		is_error("pipex: ", strerror(errno), EXIT_FAILURE);
}

void	breed_process_recursively(t_args *args)
{
	int			status;
	pid_t		pid;
	extern int	errno;

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
