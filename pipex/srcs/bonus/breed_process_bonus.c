/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breed_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:40:45 by jun               #+#    #+#             */
/*   Updated: 2021/09/09 11:08:54 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/ft_pipex_bonus.h"
#include <unistd.h>

static void	execute_processes(t_args *args, int cmd)
{
	extern int	errno;

	if (cmd != args->argc - 4)
		connect_pipe_fd(args->pipe_fd[cmd], STDOUT_FILENO);
	else
		rdr_stdout_to_file(args->file[1], args);
	connect_pipe_fd(args->pipe_fd[cmd - 1], STDIN_FILENO);
	execve(args->params[cmd][0], args->params[cmd], args->envp);
	if (errno == E_ACCESS || args->params[cmd][0] == NULL)
		is_error("zsh: permission denied: ", args->params[cmd][0], X_ERR);
	else if (errno == E_NOCMD)
		is_error("zsh: command not found: ", args->params[cmd][0], CMD_ERR);
	else
		is_error("pipex: ", strerror(errno), EXIT_FAILURE);
}

static void	execute_extra_processes(t_args *args, int cmd)
{
	pid_t		pid;
	extern int	errno;

	if (args->argc - 4 != cmd)
		if (pipe(args->pipe_fd[cmd]) == -1)
			is_error("pipex: ", strerror(errno), EXIT_FAILURE);
	pid = fork();
	args->pid[cmd] = pid;
	if (pid == 0)
		execute_processes(args, cmd);
	else if (pid > 0)
	{
		destroy_pipe(args->pipe_fd[cmd - 1]);
		if (cmd == args->argc - 4)
			wait_process(args);
		execute_extra_processes(args, ++cmd);
	}
	else
		is_error("pipex: ", strerror(errno), EXIT_FAILURE);
}

static void	execute_first_process(t_args *args)
{
	pid_t		pid;
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
		if (errno == E_ACCESS || args->params[0][0] == NULL)
			is_error("zsh: permission denied: ", args->params[0][0], X_ERR);
		else if (errno == E_NOCMD)
			is_error("zsh: command not found: ", args->params[0][0], CMD_ERR);
		else
			is_error("pipex: ", strerror(errno), EXIT_FAILURE);
	}
	else if (pid > 0)
		execute_extra_processes(args, 1);
	else
		is_error("pipex: ", strerror(errno), EXIT_FAILURE);
}

void	breed_process(t_args *args)
{
	int			status;
	pid_t		pid;
	extern int	errno;

	pid = fork();
	if (pid == 0)
		execute_first_process(args);
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
