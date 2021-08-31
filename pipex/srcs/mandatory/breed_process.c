/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breed_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:40:45 by jun               #+#    #+#             */
/*   Updated: 2021/08/31 14:21:15 by jun              ###   ########.fr       */
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

static pid_t	is_child_process(t_args *args, int *pipe_fd)
{
	pid_t	pid;
	extern int	errno;

	pid = fork();
	if (pid == 0)
	{
		rdr_file_to_stdin(args->file[0]);
		connect_pipe_fd(pipe_fd, STDOUT_FILENO);
		if (execve(args->params[0][0], args->params[0], args->envp) == -1)
			is_error("zsh: command not found: ", args->params[0][0]);
	}
	else if (pid < 0)
		is_error("pipex: ", strerror(errno));
	return pid;
}

static pid_t	is_parent_process(t_args *args, int *pipe_fd)
{
	pid_t	pid;
	extern int	errno;

	pid = fork();
	if (pid == 0)
	{
		rdr_stdout_to_file(args->file[1]);
		connect_pipe_fd(pipe_fd, STDIN_FILENO);
		if (execve(args->params[1][0], args->params[1], args->envp) == -1)
			is_error("zsh: command not found: ", args->params[1][0]);
	}
	else if (pid < 0)
		is_error("pipex: ", strerror(errno));
	return pid;
}

void	breed_process(t_args *args)
{
	pid_t	pid;
	int		pipe_fd[2];
	int			status;
	extern int	errno;

	if (pipe(pipe_fd) == -1)
		is_error("pipex: ", strerror(errno));
	pid = fork();
	if (pid == 0)
	{
		is_child_process(args, pipe_fd);
		is_parent_process(args, pipe_fd);
		while(waitpid(-1, &status, WNOHANG) != -1);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (!WIFEXITED(status))
		{
			perror("child process quited unexpectedly");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else
	{
		perror("Fail to fork");
		exit(EXIT_FAILURE);
	}
}
