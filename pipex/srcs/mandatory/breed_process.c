/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breed_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:40:45 by jun               #+#    #+#             */
/*   Updated: 2021/09/01 16:55:31 by jun              ###   ########.fr       */
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
		if (!ft_strlen(args->params[0][0]))
			is_error("zsh: permission denied: ", args->params[1][0], X_ERR);
		if (access(args->params[0][0], F_OK) == -1)
			is_error("zsh: command not found: ", args->params[0][0], CMD_ERR);
		if (access(args->params[0][0], X_OK) == -1)
			is_error("zsh: permission denied: ", args->params[0][0], X_ERR);
		execve(args->params[0][0], args->params[0], args->envp);
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
		if (!ft_strlen(args->params[1][0]))
			is_error("zsh: permission denied: ", args->params[1][0], X_ERR);
		if (access(args->params[1][0], F_OK) == -1)
			is_error("zsh: command not found: ", args->params[1][0], CMD_ERR);
		if (access(args->params[1][0], X_OK) == -1)
			is_error("zsh: permission denied: ", args->params[1][0], X_ERR);
		execve(args->params[1][0], args->params[1], args->envp);
		is_error("pipex: ", strerror(errno), EXIT_FAILURE);
	}
	else if (pid < 0)
		is_error("pipex: ", strerror(errno), EXIT_FAILURE);
	args->pid[1] = pid;
}

static void	wait_processes(t_args *args, int *pipe_fd)
{
	pid_t	execed_pid;
	int		status;
	int		exit_code;

	execed_pid = 0;
	while (execed_pid != -1)
	{
		execed_pid = wait(&status);
		if (execed_pid == args->pid[0])
			close(pipe_fd[1]);
		else if (execed_pid == args->pid[1])
		{
			close(pipe_fd[0]);
			if (WIFEXITED(status))
				exit_code = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				exit_code = WTERMSIG(status);
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

	if (pipe(pipe_fd) == -1)
		is_error("pipex: ", strerror(errno), EXIT_FAILURE);
	pid = fork();
	if (pid == 0)
	{
		is_child_process(args, pipe_fd);
		is_parent_process(args, pipe_fd);
		wait_processes(args, pipe_fd);
	}
	else if (pid > 0)
	{
		destory_pipe(pipe_fd);
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			exit(WEXITSTATUS(status));
		else
			exit(EXIT_FAILURE);
	}
	else
		is_error("pipex: ", strerror(errno), EXIT_FAILURE);
}
