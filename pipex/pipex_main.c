/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:15:51 by yongjule          #+#    #+#             */
/*   Updated: 2021/07/08 17:05:18 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static	void	connect_pipe_fd(int *pipefd, int pipe_status)
{
	if (dup2(pipefd[pipe_status], pipe_status) == -1)
	{
		perror("Error while connecting pipe");
		exit(EXIT_FAILURE);
	}
	close(pipefd[0]);
	close(pipefd[1]);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int pipefd[2];

	check_arg_validity(argc, argv, envp);
//	parse_commend(argv, envp);
//	rdr_file_to_stdin(argv[1]);
	pipe(pipefd);
//	close(pipefd[0]);
//	close(pipefd[1]);
	printf("AFTER DUP: pipe[0] = %d, pipe[1] = %d\n", pipefd[0], pipefd[1]);
	pid = fork();
	if (pid == 0)
	{
		rdr_file_to_stdin(argv[1]);
		connect_pipe_fd(pipefd, STDIN_FILENO);
		execve("/bin/cat", NULL, NULL);
	}
	else if (pid > 0)
	{
		wait(NULL);
		rdr_stdout_to_file(argv[2]);
		connect_pipe_fd(pipefd, STDOUT_FILENO);
		execve("/usr/bin/wc", NULL, NULL);
	}
	printf("SUCCESS?");
	while(1);
	return (EXIT_SUCCESS);
}
