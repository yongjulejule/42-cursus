/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiting_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:09:06 by jun               #+#    #+#             */
/*   Updated: 2021/09/07 10:14:17 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/ft_pipex_bonus.h"

static int	get_exit_status(int status)
{
	int	exit_code;

	if (wifexited(status))
		exit_code = wexitstatus(status);
	else if (wifsignaled(status))
		exit_code = wtermsig(status);
	else
		exit_code = EXIT_FAILURE;
	return (exit_code);
}

void	wait_process(t_args *args)
{
	int		status;
	int		exit_code;
	int		cmd;
	pid_t	execed_pid;

	execed_pid = 0;
	while (execed_pid != -1)
	{
		cmd = 1;
		while (cmd < args->argc - 3)
		{
			execed_pid = wait(&status);
			if (execed_pid == args->pid[args->argc - 4])
				exit_code = get_exit_status(status);
			cmd++;
		}
	}
	exit(exit_code);
}
