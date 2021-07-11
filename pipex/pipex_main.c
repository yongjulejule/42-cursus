/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <yongjule@42student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 19:50:07 by jun               #+#    #+#             */
/*   Updated: 2021/07/11 16:10:51 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"


int	main(int argc, char **argv, char **envp)
{
	int pipe_fd[2];
	char	*file[2];
	t_args *args;

	file[0] = argv[1];
	file[1] = argv[3];
	check_arg_validity(argc, argv, envp);
	build_structure(argc, argv, envp, args);
	pipe(pipe_fd);
	breed_process(args);
}
