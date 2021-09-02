/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breed_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:40:45 by jun               #+#    #+#             */
/*   Updated: 2021/09/02 14:16:17 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/ft_pipex.h"

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

static void	is_child_process(t_args *args, int *pipe_fd)
{
	pid_t		pid;
	extern int	errno;

	pid = fork();
	if (pid == 0)
	{
		rdr_file_to_stdin(args->file[0]);
		connect_pipe_fd(pipe_fd, STDOUT_FILENO);
		execve(args->params[0][0], args->params[0], args->envp);
		if (errno == E_ACCESS || args->params[0][0] == NULL)
			is_error("zsh: permission denied: ", args->params[0][0], X_ERR);
		else if (errno == E_NOCMD)
			is_error("zsh: command not found: ", args->params[0][0], CMD_ERR);
		else
			is_error("pipex: ", strerror(errno), EXIT_FAILURE);
	}
	else if (pid < 0)
		is_error("pipex: ", strerror(errno), EXIT_FAILURE);
	args->pid[0] = pid;
}

static void	is_parent_process(t_args *args, int *pipe_fd)
{
	pid_t		pid;
	extern int	errno;

	pid = fork();
	if (pid == 0)
	{
		rdr_stdout_to_file(args->file[1]);
		connect_pipe_fd(pipe_fd, STDIN_FILENO);
		execve(args->params[1][0], args->params[1], args->envp);
		if (errno == E_ACCESS || args->params[1][0] == NULL)
			is_error("zsh: permission denied: ", args->params[1][0], X_ERR);
		else if (errno == E_NOCMD)
			is_error("zsh: command not found: ", args->params[1][0], CMD_ERR);
		else
			is_error("pipex: ", strerror(errno), EXIT_FAILURE);
	}
	else if (pid < 0)
		is_error("pipex: ", strerror(errno), EXIT_FAILURE);
	args->pid[1] = pid;
}

static void	wait_processes(t_args *args)
{
	pid_t	execed_pid;
	int		status;
	int		exit_code;

	execed_pid = 0;
	while (execed_pid != -1)
	{
		execed_pid = wait(&status);
		if (execed_pid == args->pid[1])
		{
			if (wifexited(status))
				exit_code = wexitstatus(status);
			else if (wifsignaled(status))
				exit_code = wtermsig(status);
			else
				exit_code = EXIT_FAILURE;
		}
	}
	exit(exit_code);
}

void	breed_process(t_args *args)
{
	pid_t		pid;
	int			pipe_fd[2];
	int			status;
	extern int	errno;

	pid = fork();
	if (pid == 0)
	{
		if (pipe(pipe_fd) == -1)
			is_error("pipex: ", strerror(errno), EXIT_FAILURE);
		is_child_process(args, pipe_fd);
		is_parent_process(args, pipe_fd);
		destory_pipe(pipe_fd);
		wait_processes(args);
	}
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
