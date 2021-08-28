/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breed_one_pipe_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:40:45 by jun               #+#    #+#             */
/*   Updated: 2021/08/28 12:01:27 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/ft_pipex_bonus.h"

static void	is_child_process(t_args *args, int *pipe_fd)
{
	extern int	errno;

	rdr_file_to_stdin(args->file[0], args);
	connect_pipe_fd(pipe_fd, STDOUT_FILENO);
	if (execve(args->params[0][0], args->params[0], args->envp) == -1)
		is_error(strerror(errno));
}

static void	is_parent_process(t_args *args, int *pipe_fd)
{
	int			status;
	extern int	errno;

	wait(&status);
	if (!WIFEXITED(status))
	{
		perror("child process quited unexpectedly");
		exit(EXIT_FAILURE);
	}
	rdr_stdout_to_file(args->file[1], args, NULL);
	connect_pipe_fd(pipe_fd, STDIN_FILENO);
	if (execve(args->params[1][0], args->params[1], args->envp) == -1)
		is_error(strerror(errno));
}

void	breed_one_process(t_args *args)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
	{
		perror("Fail to Open PIPE");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == 0)
		is_child_process(args, pipe_fd);
	else if (pid > 0)
		is_parent_process(args, pipe_fd);
	else
	{
		perror("Fail to fork");
		exit(EXIT_FAILURE);
	}
}
