/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:15:51 by yongjule          #+#    #+#             */
/*   Updated: 2021/07/08 08:33:33 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int i = -1;
	pid_t pid;

	printf("argc is %d\n", argc);
	while (argv[i++])
		printf("argv[%d] is %s\n",i, argv[i]);
	i = 0;
//	while (envp[i])
//		printf("envp is %s\n", envp[i++]);
	int fd = open(argv[1], O_RDONLY);
	if (dup2(fd, STDIN_FILENO) == -1)
		exit(0);
	close(fd);
	pid = fork();
	if (pid == 0)
			execve("/usr/bin/sed", &argv[1], NULL);
	wait(NULL);
	write(3, "abc", 3);
	printf("%d", fd);
	return (int)**envp;
}
