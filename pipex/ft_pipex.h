/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:18:34 by yongjule          #+#    #+#             */
/*   Updated: 2021/07/11 15:39:13 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

/*include libraries*/

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h> //perror
#include <string.h> //strerror
#include "ft_pipex.h"
#include "libft/libft.h"

/*user defines*/

#define PIPE_RD 0
#define PIPE_WR 1

typedef	struct	s_args
{
	int		argc;
	char	*file[2];
	char	**env_path;
	char	***cmd_w_params;
}	t_args;

/*errno*/

extern	int	errno;

/*functions*/

void	check_arg_validity(int argc, char **argv, char **envp);
void	rdr_file_to_stdin(char *file);
void	rdr_stdout_to_file(char *file);
void	build_structure(int argc, char **argv, char **envp, t_args *cmds);
#endif
