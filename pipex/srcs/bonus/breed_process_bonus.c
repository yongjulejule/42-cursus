/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breed_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:40:45 by jun               #+#    #+#             */
/*   Updated: 2021/07/15 11:31:11 by jun              ###   ########.fr       */
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

void	parent_process(t_args *args, int *pipe_fd, int nth_cmd)
{
	int status;

//	wait(&status);
//	if (!WIFEXITED(status))
//	{
//		perror("child process quited unexpectedly");
//		exit(EXIT_FAILURE);
//	}
	ft_putendl_fd("HERE IS PARENT PROCESS", 2);
	ft_putnbr_fd(nth_cmd, 2);
	ft_putendl_fd(args->params[nth_cmd][0],2);
	if (args->params[nth_cmd + 1] == NULL)
		rdr_stdout_to_file(args->file[1]);
	connect_pipe_fd(pipe_fd, STDIN_FILENO);
	ft_putendl_fd("PARENT EXECVED!!", 2);
	execve(args->params[nth_cmd][0], args->params[nth_cmd], NULL);
}

void	child_process(t_args *args, int *pipe_fd, int nth_cmd)
{
	pid_t	pid;
	int		pipe_fds[2];

	ft_putnbr_fd(nth_cmd, 2);
	ft_putstr_fd(":here is child process\n", 2);
	if (pipe(pipe_fds) == -1)
	{
		perror("Error while open pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == 0)
	{
		if (nth_cmd == 0)
			rdr_file_to_stdin(args->file[0]);
		connect_pipe_fd(pipe_fds, STDOUT_FILENO);
		ft_putnbr_fd(nth_cmd, 2);
		ft_putendl_fd("CHILD EXECVED!!", 2);
		execve(args->params[nth_cmd][0], args->params[nth_cmd], NULL);
	}
	else if (pid > 0)
	{
		wait(NULL);
		if (nth_cmd == args->argc - 5)
			parent_process(args, pipe_fds, nth_cmd + 1);
		child_process(args, pipe_fds, ++nth_cmd);
	}
}

void	breed_process_recursively(t_args *args, int nth_cmd)
{
	int		pipe_fd[2];
	pid_t	pid;

	child_process(args, NULL, 0);
//	ft_putnbr_fd(nth_cmd, 2);
//	if (pipe(pipe_fd) == -1)
//	{
//		perror("Error while open pipe");
//		exit(EXIT_FAILURE);
//	}
//	pid = fork();
//	if (pid == 0)
//		child_process(args, pipe_fd, nth_cmd - 2);
//	else if (pid > 0)
//		parent_process(args, pipe_fd, nth_cmd);
//	else
//	{
//		perror("Error while Fork");
//		exit(EXIT_FAILURE);
//	}
}
