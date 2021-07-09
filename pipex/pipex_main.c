/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 19:50:07 by jun               #+#    #+#             */
/*   Updated: 2021/07/10 03:01:44 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static	void	connect_pipe_fd(int *pipe_fd, int pipe_status)
{
	if (dup2(pipe_fd[pipe_status], pipe_status) == -1)
	{
		perror("Error while connecting pipe");
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[PIPE_RD]);
	close(pipe_fd[PIPE_WR]);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int pipe_fd[2];
	int status;

	check_arg_validity(argc, argv, envp);
	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
	{
		rdr_file_to_stdin(argv[1]);
		connect_pipe_fd(pipe_fd, STDOUT_FILENO);
		execve("/bin/cat", NULL, NULL);
	}
	else if (pid > 0)
	{
		wait(&status);
		if (WIFSIGNALED(status))
		{
			perror("dd");
			exit(EXIT_FAILURE);
		}
		rdr_stdout_to_file(argv[4]);
		connect_pipe_fd(pipe_fd, STDIN_FILENO);
		execve("/bin/cat", NULL, NULL);
	}
	else
		perror("Fail to fork");
	return (EXIT_SUCCESS);
}
