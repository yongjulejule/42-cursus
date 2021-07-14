/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breed_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:40:45 by jun               #+#    #+#             */
/*   Updated: 2021/07/14 10:28:00 by jun              ###   ########.fr       */
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

void	child_process(t_args *args, int *pipe_fd, int nth_cmd)
{
	if (nth_cmd == 0)
		rdr_file_to_stdin(args->file[0]);
	connect_pipe_fd(pipe_fd, STDOUT_FILENO);
//ft_putstr_fd("\nin child args->params[nth_cmd][0] is : ", 2);
//ft_putstr_fd(args->params[nth_cmd][0], 2);
//ft_putstr_fd("\nin child nth_cmd  is ", 2);
//ft_putnbr_fd( nth_cmd, 2);
	execve(args->params[nth_cmd][0], args->params[nth_cmd], NULL);
}

void	parent_process(t_args *args, int *pipe_fd, int nth_cmd)
{
	int status;

	wait(&status);
	if (!WIFEXITED(status))
	{
		perror("child process quited unexpectedly");
		exit(EXIT_FAILURE);
	}
//ft_putstr_fd("\nparent process nth_cmd is", 2);
//ft_putnbr_fd(nth_cmd, 2);
	if (nth_cmd == args->argc - 5)
		rdr_stdout_to_file(args->file[1]);
	connect_pipe_fd(pipe_fd, STDIN_FILENO);
//ft_putstr_fd("\nin parent args->params[nth_cmd][0] is \n", 2);
//ft_putstr_fd(args->params[nth_cmd + 1][0], 2);
//ft_putnbr_fd( nth_cmd, 2);
//ft_putstr_fd("\nin parent nth_cmd  is ", 2);
	execve(args->params[nth_cmd + 1][0], args->params[nth_cmd + 1], NULL);
}

void	breed_process_recursively(t_args *args, int nth_cmd)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (!nth_cmd)
		return ;
	if (pipe(pipe_fd) == -1)
	{
		perror("Error while open pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == 0)
	{
		breed_process_recursively(args, --nth_cmd);
		child_process(args, pipe_fd, nth_cmd);
	}
	else if (pid > 0)
		parent_process(args, pipe_fd, nth_cmd);
	else
	{
		perror("Error while Fork");
		exit(EXIT_FAILURE);
	}
}
