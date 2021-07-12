/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 22:22:19 by jun               #+#    #+#             */
/*   Updated: 2021/07/12 09:29:57 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int main(int argc, char **argv, char **envp)
{
	pid_t pid;
	int pipe_fd[2];

	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			rdr_file_to_stdin(argv[1]);
			connect_pipe_fd(pipe_fd, STDOUT_FILENO);
//			while(1);
			execve("/bin/cat", NULL, NULL);
		}
		else if (pid > 0)
		{
			wait(NULL);
//			char a[100];
//			read(3, a, 50);
//			ft_putendl_fd(a, 2);
//			dup2(3, 0);
//			connect_pipe_fd(pipe_fd, STDIN_FILENO);
			rdr_stdout_to_file(argv[4]);
			dup2(pipe_fd[0], 0);
            dup2(pipe_fd[1], 4); //error occurs here:(
			while(1);
			execve("/usr/bin/wc", NULL, NULL);
		}
	}
	else if (pid > 0)
	{
		wait(NULL);
		rdr_stdout_to_file(argv[4]);
		connect_pipe_fd(pipe_fd, STDIN_FILENO);
		execve("/bin/cat", NULL, NULL);
	}	
}
